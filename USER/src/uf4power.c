// control.c
#include "main.h"
#include "pid.h"
#include "key.h"
#include "lvgl.h"
#include "uf4power.h"

#include "ina226.h"
#include "ui_Screen1.h"
#include <stdio.h>
#include <math.h>

// 编辑位：3位整数 + 1位小数 -> 格式 "xx.x"（支持 0..26.5）
static int edit_pos = 0; // 0..3 (0: tens, 1: units, 2: ones? 看下实现) 我们定义：pos0=十位(10s), pos1=个位(1s), pos2=小数位(0.1s)
static float V_setpoint = 12.0f;
static float I_setpoint = 2.0f;

// PID 使能标志
static volatile uint8_t voltage_pid_enabled = 0;
static volatile uint8_t current_pid_enabled = 0;

// 上次更新 tick
static uint32_t last_control_tick = 0;

// helper: clamp
static float clampf(float v, float lo, float hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

// 映射：电压(0..MAX_VOLTAGE) -> DAC (0..4095) 按你要求：0V -> 4095, MAX_VOLTAGE -> 0
static uint32_t voltage_to_dac(float v) {
    v = clampf(v, 0.0f, MAX_VOLTAGE);
    float ratio = v / MAX_VOLTAGE;
    float dacf = (1.0f - ratio) * DAC_MAX;
    return (uint32_t)roundf(dacf);
}

// 映射：电流(0..MAX_CURRENT) -> DAC (0..4095) 0A->0, MAX_CURRENT->4095
static uint32_t current_to_dac(float i) {
    i = clampf(i, 0.0f, MAX_CURRENT);
    float ratio = i / MAX_CURRENT;
    float dacf = ratio * DAC_MAX;
    return (uint32_t)roundf(dacf);
}

// 将指定值写入 DAC（12-bit right aligned）
static void dac_write_voltage(uint32_t value) {
    if (value > 4095) value = 4095;
    HAL_DAC_SetValue(&hdac, DAC_VOLTAGE_CHANNEL, DAC_ALIGN_12B_R, value);
    // 如果需要，启动通道（如果尚未启动）：
    // HAL_DAC_Start(&hdac, DAC_VOLTAGE_CHANNEL); // 确保在 init 中已启动
}

static void dac_write_current(uint32_t value) {
    if (value > 4095) value = 4095;
    HAL_DAC_SetValue(&hdac, DAC_CURRENT_CHANNEL, DAC_ALIGN_12B_R, value);
}

// 根据 edit_pos, up/down 修改 V_setpoint
static void edit_voltage_by_delta(int delta)
{
    // pos 0: 十位（10s）； pos1: 个位（1s）； pos2: 小数(0.1)
    int tens = ((int)floorf(V_setpoint)) / 10;
    int ones = ((int)floorf(V_setpoint)) % 10;
    int tenths = (int)roundf((V_setpoint - floorf(V_setpoint)) * 10.0f) % 10;

    if (edit_pos == 0) {
        tens += delta;
    } else if (edit_pos == 1) {
        ones += delta;
    } else {
        tenths += delta;
    }
    int new_int = tens*10 + ones;
    float new_v = new_int + (tenths * 0.1f);
    new_v = clampf(new_v, 0.0f, MAX_VOLTAGE);
    V_setpoint = new_v;
}

// 左右切位
static void move_edit_pos(int dir) {
    // dir: +1 -> right, -1 -> left
    if (dir > 0) {
        edit_pos++;
        if (edit_pos > 2) edit_pos = 0;
    } else {
        if (edit_pos == 0) edit_pos = 2;
        else edit_pos--;
    }
}

// 显示设定值到 lvgl label（比如 "12.3"）
static void show_setpoints_to_ui(void) {
    char buf[16];
    snprintf(buf, sizeof(buf), "%05.2f", V_setpoint);
    lv_label_set_text(VsetLabel, buf);
    snprintf(buf, sizeof(buf), "%05.2f", I_setpoint);
    lv_label_set_text(IsetLabel, buf);
}

// 控制定时器回调（由 lvgl 定时器或 HAL 定时器每 CONTROL_PERIOD_MS 调用一次）
// - 读取 INA226
// - 运行 PID（如果 enabled）
// - 写 DAC
// - 更新 UI 标签
void control_timer_cb(lv_timer_t * timer)
{
    (void) timer;
    // 先处理按键事件采样
    process_key_events();

    // 处理一按事件（edge）
    if (RIGHT_KEY_pressed) { move_edit_pos(+1); RIGHT_KEY_pressed = 0; }
    if (LEFT_KEY_pressed)  { move_edit_pos(-1); LEFT_KEY_pressed = 0; }
    if (UP_KEY_pressed)    { edit_voltage_by_delta(+1); UP_KEY_pressed = 0; }
    if (DOWN_KEY_pressed)  { edit_voltage_by_delta(-1); DOWN_KEY_pressed = 0; }

    // RECOVER_KEY 按下 -> 启动电压 PID 并使能输出
    if (RECOVER_KEY_pressed) {
        RECOVER_KEY_pressed = 0;
        // 把 pidv.voltage 初始置为当前测得电压以避免突变
        pidv.voltage = INA226_BusVoltage();
        pidv.integral = 0.0f;
        pidv.err = 0.0f;
        pidv.err_last = 0.0f;
        voltage_pid_enabled = 1;
        OUTPUT_ENABLE();
    }

    // PAUSED_KEY 可以用来停 PID（短按切换）
    if (PAUSED_KEY_pressed) {
        PAUSED_KEY_pressed = 0;
        voltage_pid_enabled = 0;
        current_pid_enabled = 0;
        OUTPUT_DISABLE();
    }

    // FALSE_KEY: 直接把 DAC 设为某个安全值（如 0 输出）
    if (FALSE_KEY_pressed) {
        FALSE_KEY_pressed = 0;
        voltage_pid_enabled = 0;
        current_pid_enabled = 0;
        OUTPUT_DISABLE();
        dac_write_voltage(4095); // 对应 0V
        dac_write_current(0);
    }

    // 读取测量值
    float Vout = INA226_BusVoltage();  // 单位 V
    float Iout = INA226_Current();     // 单位 A
    float Pout = INA226_Power();       // 单位 W

    // 电流 PID 是否启用：当检测到负载（Iout >= threshold）时可以启用当前 PID
    if (Iout >= NOLOAD_CURRENT_THRESHOLD) {
        // 如果用户设置了 I_setpoint > 0 可以开启电流 PID（这里我用简单策略：当电压 PID 启动且测得电流存在时）
        if (I_setpoint > 0.001f) {
            // 初始化 pidi 初始输出为当前测得值的近似映射
            if (!current_pid_enabled) {
                pidi.current = Iout;
                pidi.integral = 0.0f;
                pidi.err = 0.0f;
                pidi.err_last = 0.0f;
            }
            current_pid_enabled = 1;
        }
    } else {
        current_pid_enabled = 0;
    }

    if (voltage_pid_enabled)
    {
        float pid_out = VPID_realize(V_setpoint, Vout);
        float new_voltage = clampf(V_setpoint + pid_out, 0.0f, MAX_VOLTAGE);
        uint32_t dacv = voltage_to_dac(new_voltage);
        dac_write_voltage(dacv);
    }else {
        // PID 未启用，仍允许用户手动以设定值直接输出（需求是 RECOVER_KEY 时启动 PID 并输出设定电压）
        // 如果你希望按键直接生效可以取消注释：
        // uint32_t dacv = voltage_to_dac(V_setpoint);
        // dac_write_voltage(dacv);
        ;
    }

    if (current_pid_enabled) {
        float pid_out_i = IPID_realize(I_setpoint, Iout);
        pidi.current += pid_out_i;
        pidi.current = clampf(pidi.current, 0.0f, MAX_CURRENT);
        uint32_t daci = current_to_dac(pidi.current);
        dac_write_current(daci);
    } else {
        // 如果电流 PID 未启用，写 0（空载）
        dac_write_current(0);
    }

    // 更新 UI 标签
    static char buf1[16], buf2[16], buf3[16];
    snprintf(buf1, sizeof(buf1), "%05.2f", Vout);
    lv_label_set_text(VoutLabel, buf1);
    snprintf(buf2, sizeof(buf2), "%05.2f", Iout);
    lv_label_set_text(IoutLabel, buf2);
    snprintf(buf3, sizeof(buf3), "%05.2f", Pout);
    lv_label_set_text(PoutLabel, buf3);

    // 更新设定值显示
    show_setpoints_to_ui();
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
    lv_timer_create(control_timer_cb, CONTROL_PERIOD_MS, NULL);
}