#include "uf4power.h"
#include "ina226.h"
#include "key.h"
#include "stdio.h"
#include "main.h"
#include "widgets/lv_label.h"
#include "ui_Screen1.h"

/*========================= 全局变量定义 =========================*/
float target_voltage = 12.0f;
float target_current = 5.0f;

uint16_t DAC_voltage = 0;
uint16_t DAC_current = 0;

int digit_index = 0;  // 当前选择位 0=十位,1=个位,2=十分位,3=百分位
uint8_t mode = 0;     // 当前模式 0=电压, 1=电流

float step_value[4] = {10.0f, 1.0f, 0.1f, 0.01f};

uint8_t output_enabled = 0;  // 输出使能标志

// 添加变量来保存PID调整后的值
float adjusted_voltage = 0;
float adjusted_current = 0;

/*========================= 函数实现 =========================*/

/**
 * @brief 初始化UF4电源控制模块
 */
void UF4Power_Init(void)
{
    // 初始化PID控制器
    VPID_init();
    IPID_init();

    // 初始化调整值为目标值
    adjusted_voltage = target_voltage;
    adjusted_current = target_current;

    // 设置初始DAC值
    UpdateDAC();

    printf("UF4 Power Control Initialized\n");
}

/**
 * @brief 更新DAC输出值
 */
void UpdateDAC(void)
{
    // 限制电压和电流在有效范围内
    if (target_voltage > MAX_VOLTAGE) target_voltage = MAX_VOLTAGE;
    if (target_voltage < 0) target_voltage = 0;

    if (target_current > MAX_CURRENT) target_current = MAX_CURRENT;
    if (target_current < 0) target_current = 0;

    // 限制调整后的值
    if (adjusted_voltage > MAX_VOLTAGE) adjusted_voltage = MAX_VOLTAGE;
    if (adjusted_voltage < 0) adjusted_voltage = 0;

    if (adjusted_current > MAX_CURRENT) adjusted_current = MAX_CURRENT;
    if (adjusted_current < 0) adjusted_current = 0;

    // 计算DAC值 (根据您的描述：4095对应0V/10A)
    // 电压: 4095 = 0V, 0 = 26V
    DAC_voltage = (uint16_t)((MAX_VOLTAGE - adjusted_voltage) * DAC_MAX / MAX_VOLTAGE);
    // 电流: 0 = 0A, 4095 = 10A
    DAC_current = (uint16_t)(adjusted_current * DAC_MAX / MAX_CURRENT);

    // 设置DAC输出
    if (output_enabled) {
        HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
        HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_voltage);
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, DAC_current);

    } else {
        // 输出关闭时，设置DAC为0V和0A
        HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
        HAL_DAC_Start(&hdac, DAC_CHANNEL_2);
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0); // 0V
        HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, 0);       // 0A

    }
}

/**
 * @brief 更新LVGL界面显示
 */
void UpdateLVGLLabels(void)
{
    char buf[16];

    // 更新目标电压显示
    sprintf(buf, "%05.2f", target_voltage);
    lv_label_set_text(VsetLabel, buf);

    // 更新目标电流显示
    sprintf(buf, "%05.2f", target_current);
    lv_label_set_text(IsetLabel, buf);

    // 更新实际电压显示
    float actual_voltage = INA226_BusVoltage();
    sprintf(buf, "%05.2f", actual_voltage);
    lv_label_set_text(VoutLabel, buf);

    // 更新实际电流显示
    float actual_current = INA226_Current();
    sprintf(buf, "%05.2f", actual_current);
    lv_label_set_text(IoutLabel, buf);

    // 更新功率显示
    float power = actual_voltage * actual_current;
    sprintf(buf, "%05.2f", power);
    lv_label_set_text(PoutLabel, buf);
}

/**
 * @brief 处理按键输入
 */
void ProcessKeys(void)
{
    static uint32_t last_key_time = 0;
    uint32_t current_time = HAL_GetTick();

    // 消抖处理
    if (current_time - last_key_time < 100) {
        return;
    }

    // 切换模式：电压/电流
    if (PAUSED_KEY_pressed) {
        PAUSED_KEY_pressed = 0;
        mode = !mode;  // 在电压和电流模式间切换
        last_key_time = current_time;
        printf("Mode switched to %s\n", mode ? "Current" : "Voltage");
    }

    // 开启/关闭输出
    if (FALSE_KEY_pressed) {
        FALSE_KEY_pressed = 0;
        output_enabled = !output_enabled;

        if (output_enabled) {
            lv_obj_add_state(ui_Switch1, LV_STATE_CHECKED);
            HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_SET);
            printf("Output Enabled\n");
        } else {
            lv_obj_clear_state(ui_Switch1, LV_STATE_CHECKED);
            HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_RESET);
            printf("Output Disabled\n");
        }

        UpdateDAC();  // 更新DAC输出
        last_key_time = current_time;
    }

    // 切换数字位选择
    if (RIGHT_KEY_pressed) {
        RIGHT_KEY_pressed = 0;
        digit_index = (digit_index + 1) % 4;
        last_key_time = current_time;
        printf("Digit index: %d\n", digit_index);
    }

    if (LEFT_KEY_pressed) {
        LEFT_KEY_pressed = 0;
        digit_index = (digit_index + 3) % 4;  // 避免负数
        last_key_time = current_time;
        printf("Digit index: %d\n", digit_index);
    }

    // 增加数值
    if (UP_KEY_pressed) {
        UP_KEY_pressed = 0;
        if (mode == 0) {  // 电压模式
            target_voltage += step_value[digit_index];
            if (target_voltage > MAX_VOLTAGE) target_voltage = MAX_VOLTAGE;
            adjusted_voltage = target_voltage; // 同时更新调整值
        } else {  // 电流模式
            target_current += step_value[digit_index];
            if (target_current > MAX_CURRENT) target_current = MAX_CURRENT;
            adjusted_current = target_current; // 同时更新调整值
        }
        UpdateDAC(); // 更新DAC输出
        UpdateLVGLLabels();
        last_key_time = current_time;
        printf("Value increased\n");
    }

    // 减少数值
    if (DOWN_KEY_pressed) {
        DOWN_KEY_pressed = 0;
        if (mode == 0) {  // 电压模式
            target_voltage -= step_value[digit_index];
            if (target_voltage < 0) target_voltage = 0;
            adjusted_voltage = target_voltage; // 同时更新调整值
        } else {  // 电流模式
            target_current -= step_value[digit_index];
            if (target_current < 0) target_current = 0;
            adjusted_current = target_current; // 同时更新调整值
        }
        UpdateDAC(); // 更新DAC输出
        UpdateLVGLLabels();
        last_key_time = current_time;
        printf("Value decreased\n");
    }
}

/**
 * @brief 控制循环 - PID调节
 */
void ControlLoop(void)
{
    static uint32_t last_control_time = 0;
    uint32_t current_time = HAL_GetTick();

    // 每100ms执行一次控制循环
    if (current_time - last_control_time < 100) {
        return;
    }

    last_control_time = current_time;

    if (output_enabled) {
        // 读取实际值
        float actual_voltage = INA226_BusVoltage();
        float actual_current = INA226_Current();

        // 电压PID控制
        float voltage_correction = VPID_realize(target_voltage, actual_voltage);
        // 使用PID输出调整电压值
        adjusted_voltage = target_voltage + voltage_correction;

        // 电流PID控制 (仅在电流不为0时启用)
        if (target_current > 0.01f) {  // 避免空载时的电流控制
            float current_correction = IPID_realize(target_current, actual_current);
            // 使用PID输出调整电流值
            adjusted_current = target_current + current_correction;
        } else {
            // 空载情况下使用目标电流
            adjusted_current = target_current;
        }

        // 更新DAC输出
        UpdateDAC();
    }

    // 更新显示
    UpdateLVGLLabels();
}