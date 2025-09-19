
// uf4power.h
#ifndef UF4POWER_H
#define UF4POWER_H

#include "pid.h"
#include "misc/lv_timer.h"

#define DEBUGMODE 0

#define DAC_VOLTAGE_CHANNEL DAC_CHANNEL_2  // 电压输出通道
#define DAC_CURRENT_CHANNEL DAC_CHANNEL_1
extern DAC_HandleTypeDef hdac;

// 输出控制 IO
#define OUTPUT_ENABLE() HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_SET)
#define OUTPUT_DISABLE() HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_RESET)

// 常量
#define MAX_VOLTAGE 26.5f
#define MAX_CURRENT 10.0f
#define DAC_MAX 4095.0f

#define DEFAULT_V_SET 5.0f
#define DEFAULT_I_SET 2.0f

// 调速周期（ms）
// #define CONTROL_PERIOD_MS 100 // 100ms 控制周期 建议为10ms libo2

// 空载判定阈值（A）
#define NOLOAD_CURRENT_THRESHOLD 0.05f


// 存储 INA226 测量值
extern float g_Vout;  // 电压 (V)
extern float g_Iout;  // 电流 (A)
extern float g_Pout;  // 功率 (W)

extern pid_v pidv;
extern pid_i pidi;
void Control_Init(void);
void control_timer_cb(void);
#endif
