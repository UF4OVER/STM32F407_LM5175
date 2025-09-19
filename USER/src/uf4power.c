// control.c
#include "uf4power.h"
#include "key.h"
#include "lvgl.h"
#include "main.h"
#include "pid.h"

#include "ina226.h"
#include "ui_DEFAULT.h"
#include "ui_DEBUG.h"
#include "ui_const.h"
#include "usbd_cdc_if.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 编辑位：3位整数 + 1位小数 -> 格式 "xx.x"（支持 0..26.5）
static int edit_pos = 0;
static float V_setpoint = 12.0f;
static float I_setpoint = 2.0f;

// PID 使能标志
static volatile uint8_t voltage_pid_enabled = 1;
static volatile uint8_t current_pid_enabled = 0;

// 全局变量定义，用于存储 INA226 测量值
float g_Vout = 0.0f;  // 总线电压 (V)
float g_Iout = 0.0f;  // 电流 (A)
float g_Pout = 0.0f;  // 功率 (W)

// VOFA数据发送相关
static uint32_t vofa_send_counter = 0;
#define VOFA_SEND_INTERVAL 5  // 每10次控制循环发送一次数据
#define CH_COUNT 2

volatile uint8_t cdc_data_received = 0;
char cdc_rx_buffer[CDC_RX_BUFFER_SIZE];



// helper: clamp
static float clampf(float v, float lo, float hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

// 映射：电压(0..MAX_VOLTAGE) -> DAC (0..4095) 按你要求：0V -> 4095, MAX_VOLTAGE -> 0
static uint32_t voltage_to_dac(float v)
{
    v = clampf(v, 0.0f, MAX_VOLTAGE);
    float ratio = v / MAX_VOLTAGE;
    float dacf = (1.0f - ratio) * DAC_MAX;
    return (uint32_t)roundf(dacf);
}

// 映射：电流(0..MAX_CURRENT) -> DAC (0..4095) 0A->0, MAX_CURRENT->4095
static uint32_t current_to_dac(float i)
{
    i = clampf(i, 0.0f, MAX_CURRENT);
    float ratio = i / MAX_CURRENT;
    float dacf = ratio * DAC_MAX;
    return (uint32_t)roundf(dacf);
}

// 将指定值写入 DAC（12-bit right aligned）
// 写电压DAC限位
static void dac_write_voltage(uint32_t value)
{
    if (value > 4095)
        value = 4095;
    HAL_DAC_SetValue(&hdac, DAC_VOLTAGE_CHANNEL, DAC_ALIGN_12B_R, value);
    // 如果需要，启动通道（如果尚未启动）：
    HAL_DAC_Start(&hdac, DAC_VOLTAGE_CHANNEL); // 确保在 init 中已启动
}

static void dac_write_current(uint32_t value)
{
    if (value > 4095)
        value = 4095;
    HAL_DAC_SetValue(&hdac, DAC_CURRENT_CHANNEL, DAC_ALIGN_12B_R, value);
    HAL_DAC_Start(&hdac, DAC_CURRENT_CHANNEL); // 确保在 init 中已启动

}

// 根据 edit_pos, up/down 修改 V_setpoint
static void edit_voltage_by_delta(int delta)
{
    // pos 0: 十位（10s）； pos1: 个位（1s）； pos2: 小数(0.1)
    int tens = ((int)floorf(V_setpoint)) / 10;
    int ones = ((int)floorf(V_setpoint)) % 10;
    int tenths = (int)roundf((V_setpoint - floorf(V_setpoint)) * 10.0f) % 10;

    if (edit_pos == 0)
    {
        tens += delta;
    }
    else if (edit_pos == 1)
    {
        ones += delta;
    }
    else
    {
        tenths += delta;
    }
    int new_int = tens * 10 + ones;
    float new_v = new_int + (tenths * 0.1f);
    new_v = clampf(new_v, 0.0f, MAX_VOLTAGE);
    V_setpoint = new_v;
}

// 左右切位
static void move_edit_pos(int dir)
{
    // dir: +1 -> right, -1 -> left
    if (dir > 0)
    {
        edit_pos++;
        if (edit_pos > 2)
            edit_pos = 0;
    }
    else
    {
        if (edit_pos == 0)
            edit_pos = 2;
        else
            edit_pos--;
    }
}

// 显示设定值到 lvgl label（比如 "12.3"）
static void show_setpoints_to_ui(void)
{
    char buf[16];
    snprintf(buf, sizeof(buf), "%05.2f", V_setpoint);
    lv_label_set_text(VsetLabel, buf);
    snprintf(buf, sizeof(buf), "%05.2f", I_setpoint);
    lv_label_set_text(IsetLabel, buf);
}

// 发送VOFA格式数据
static void send_vofa_data(void)
{
    // VOFA JustFloat格式: 数据 + 0x00 0x00 0x80 0x7f (帧尾)
    struct {
        float ch_data[CH_COUNT];
        unsigned char tail[4];
    } vofa_frame;

    // 填充通道数据
    vofa_frame.ch_data[0] = g_Vout;      // 实际电压
    vofa_frame.ch_data[1] = V_setpoint;  // 预设电压

    // 填充帧尾
    vofa_frame.tail[0] = 0x00;
    vofa_frame.tail[1] = 0x00;
    vofa_frame.tail[2] = 0x80;
    vofa_frame.tail[3] = 0x7f;

    // 通过CDC发送
    CDC_Transmit_FS((uint8_t*)&vofa_frame, sizeof(vofa_frame));
}

// 处理来自CDC的PID参数更新命令
// 命令格式: "PID,V,1.0,0.5,0.1" 或 "PID,I,1.0,0.5,0.1"
void process_pid_command(char* command)
{
    // 检查命令是否以"PID"开头
    if (strncmp(command, "PID,", 4) != 0) {
        char error_msg[] = "Invalid command format. Expected: PID,<V|I>,<Kp>,<Ki>,<Kd>\r\n";
        CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        return;
    }

    char pid_type = command[4]; // 'V' 或 'I'
    char* token = strtok(command, ",");

    // 跳过"PID"标记
    token = strtok(NULL, ",");
    if (token == NULL) {
        char error_msg[] = "Missing PID type. Expected: V or I\r\n";
        CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        return;
    }

    pid_type = token[0];

    // 获取Kp
    token = strtok(NULL, ",");
    if (token == NULL) {
        char error_msg[] = "Missing Kp value\r\n";
        CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        return;
    }
    float kp = atof(token);

    // 获取Ki
    token = strtok(NULL, ",");
    if (token == NULL) {
        char error_msg[] = "Missing Ki value\r\n";
        CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        return;
    }
    float ki = atof(token);

    // 获取Kd
    token = strtok(NULL, ",");
    if (token == NULL) {
        char error_msg[] = "Missing Kd value\r\n";
        CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        return;
    }
    float kd = atof(token);

    // 更新PID参数
    switch (pid_type) {
        case 'V':
        case 'v':
            pidv.Kp = kp;
            pidv.Ki = ki;
            pidv.Kd = kd;
            {
                char msg[100];
                snprintf(msg, sizeof(msg), "Updated Voltage PID: Kp=%.2f, Ki=%.2f, Kd=%.2f\r\n", kp, ki, kd);
                CDC_Transmit_FS((uint8_t*)msg, strlen(msg));
            }
            break;

        case 'I':
        case 'i':
            pidi.Kp = kp;
            pidi.Ki = ki;
            pidi.Kd = kd;
            {
                char msg[100];
                snprintf(msg, sizeof(msg), "Updated Current PID: Kp=%.2f, Ki=%.2f, Kd=%.2f\r\n", kp, ki, kd);
                CDC_Transmit_FS((uint8_t*)msg, strlen(msg));
            }
            break;

        default:
            {
                char error_msg[] = "Invalid PID type. Use 'V' for voltage or 'I' for current\r\n";
                CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
            }
            return;
    }
}

// 处理CDC接收到的数据
void process_cdc_data(void)
{
    if (cdc_data_received) {
        cdc_data_received = 0;

        // 确保字符串以null结尾
        cdc_rx_buffer[CDC_RX_BUFFER_SIZE-1] = '\0';

        // 如果是PID命令，则处理它
        if (strncmp(cdc_rx_buffer, "PID,", 4) == 0) {
            process_pid_command(cdc_rx_buffer);
        } else {
            char error_msg[] = "Unknown command\r\n";
            CDC_Transmit_FS((uint8_t*)error_msg, strlen(error_msg));
        }
    }
}

// 控制定时器回调（由HAL 定时器每 1_MS 调用一次）
// - 读取 INA226
// - 运行 PID（如果 enabled）
// - 写 DAC
// - 更新 UI 标签
void control_timer_cb()
{
    // 处理CDC接收到的数据
    process_cdc_data();

    // 先处理按键事件采样
    process_key_events();

    if (RIGHT_KEY_pressed)
    {
        move_edit_pos(+1);
        RIGHT_KEY_pressed = 0;
    }
    if (LEFT_KEY_pressed)
    {
        move_edit_pos(-1);
        LEFT_KEY_pressed = 0;
    }
    if (UP_KEY_pressed)
    {
        edit_voltage_by_delta(+1);
        UP_KEY_pressed = 0;
    }
    if (DOWN_KEY_pressed)
    {
        edit_voltage_by_delta(-1);
        DOWN_KEY_pressed = 0;
    }

    if (RECOVER_KEY_pressed)
    {
        RECOVER_KEY_pressed = 0;
        pidv.SetVoltage = g_Vout;
        pidv.integral = 0.0f;
        pidv.err = 0.0f;
        pidv.err_last = 0.0f;
        voltage_pid_enabled = 1;  // 启用 PID
        OUTPUT_ENABLE();
    }
    if (PAUSED_KEY_pressed)
    {
        PAUSED_KEY_pressed = 0;
        voltage_pid_enabled = 0;  // 禁用 PID
        current_pid_enabled = 0;
        OUTPUT_DISABLE();
    }

    // FALSE_KEY: 直接把 DAC 设为某个安全值（如 0 输出）
//    if (FALSE_KEY_pressed)
//    {
//        FALSE_KEY_pressed = 0;
//        voltage_pid_enabled = 0;
//        current_pid_enabled = 0;
//        OUTPUT_DISABLE();
//        dac_write_voltage(4095); // 对应 0V
//        dac_write_current(0);
//    }

    // 读取测量值并更新全局变量
    g_Vout = INA226_BusVoltage(); // 单位 V
    g_Iout = INA226_Current();    // 单位 A
    g_Pout = INA226_Power();      // 单位 W

    // 电流 PID 是否启用：当检测到负载（g_Iout >= threshold）时可以启用当前 PID
    if (g_Iout >= NOLOAD_CURRENT_THRESHOLD)
    {
        // 如果用户设置了 I_setpoint > 0
        if (I_setpoint > 0.01f)
        {
            // 初始化 pidi 初始输出为当前测得值的近似映射
            if (!current_pid_enabled)
            {
                pidi.SetCurrent = g_Iout;
                pidi.integral = 0.0f;
                pidi.err = 0.0f;
                pidi.err_last = 0.0f;
            }
            current_pid_enabled = 1;
        }
    }
    else
    {
        current_pid_enabled = 0;
    }

    if (voltage_pid_enabled)
    {
        float pid_out = VPID_realize(V_setpoint, g_Vout);
        // V_setpoint 无法是否改变

        float new_voltage = clampf(V_setpoint + pid_out, 0.0f, MAX_VOLTAGE); // 问题代码V_setpoint + pid_out可能累加
        uint32_t dacv = voltage_to_dac(new_voltage);
        dac_write_voltage(dacv);

        char buf[16];
        snprintf(buf, sizeof(buf), "%05.4f", pid_out);
        lv_label_set_text(DEBUG_PIDOUT_Label, buf);
        snprintf(buf, sizeof(buf), "%05.4f", g_Vout);
        lv_label_set_text(DEBUG_VOUT_Label, buf);
        snprintf(buf, sizeof(buf), "%05.4f", new_voltage);
        lv_label_set_text(DEBUG_NEWVOUT_Label, buf);
        snprintf(buf, sizeof(buf), "%05.4lu", dacv);
        lv_label_set_text(DEBUG_DACV_Label, buf);
        // 可能是问题所在，new_voltage是pidout+设定值限幅，pidout+设定值可能会累加，导致最终到达限幅，理论上pid_out的值会很大，需实际观察pid_out输出
        // libo

    }
    else
    {
        // PID 未启用，仍允许用户手动以设定值直接输出（需求是 RECOVER_KEY 时启动 PID 并输出设定电压）
        // 如果你希望按键直接生效可以取消注释：
        // uint32_t dacv = voltage_to_dac(V_setpoint);
        // dac_write_voltage(dacv);
        ;
    }

    if (current_pid_enabled)
    {
        float pid_out_i = IPID_realize(I_setpoint, g_Iout);
        pidi.SetCurrent += pid_out_i;
        pidi.SetCurrent = clampf(pidi.SetCurrent, 0.0f, MAX_CURRENT);
        uint32_t daci = current_to_dac(pidi.SetCurrent);
        dac_write_current(daci);
    }
    else
    {
        // 如果电流 PID 未启用，写 0（空载）
        dac_write_current(0);
    }

    // 更新 UI 标签
    static char buf1[16], buf2[16], buf3[16];
    snprintf(buf1, sizeof(buf1), "%05.2f", g_Vout);
    lv_label_set_text(VoutLabel, buf1);
    snprintf(buf2, sizeof(buf2), "%05.2f", g_Iout);
    lv_label_set_text(IoutLabel, buf2);
    snprintf(buf3, sizeof(buf3), "%05.2f", g_Pout);
    lv_label_set_text(PoutLabel, buf3);

    // 更新设定值显示
    show_setpoints_to_ui();

    // 发送VOFA数据
    vofa_send_counter++;
    if (vofa_send_counter >= VOFA_SEND_INTERVAL) {
        vofa_send_counter = 0;
        send_vofa_data();
    }
}
void Control_Init(void)
{
    // 启动 DAC 通道（CubeMX 生成 hdac，确保在 MX_DAC_Init() 中已 HAL_DAC_Start）
    HAL_DAC_Start(&hdac, DAC_VOLTAGE_CHANNEL);
    HAL_DAC_Start(&hdac, DAC_CURRENT_CHANNEL);

    // 初始写入（使输出为 0V, 0A）
    dac_write_voltage(voltage_to_dac(0.0f)); // 0V -> 4095
    dac_write_current(current_to_dac(0.0f));

    // Ensure output disabled initially
    OUTPUT_DISABLE();

    // 创建 LVGL 定时器，周期 CONTROL_PERIOD_MS
//    lv_timer_create(control_timer_cb, CONTROL_PERIOD_MS, NULL);
}
