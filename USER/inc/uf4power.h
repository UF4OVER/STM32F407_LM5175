
// uf4power.h
#ifndef UF4POWER_H
#define UF4POWER_H

#include "pid.h"


// ---- DAC 通道选择（按你的硬件调整） ----
#define DAC_VOLTAGE_CHANNEL    DAC_CHANNEL_1
#define DAC_CURRENT_CHANNEL    DAC_CHANNEL_2
extern DAC_HandleTypeDef hdac; // CubeMX 生成的 hdac

// 输出控制 IO（控制输出继电器/使能）
#define OUTPUT_ENABLE()  HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_SET)
#define OUTPUT_DISABLE() HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_RESET)

// 常量
#define MAX_VOLTAGE 26.5f
#define MAX_CURRENT 10.0f
#define DAC_MAX 4095.0f

// 调速周期（ms）
#define CONTROL_PERIOD_MS 100

// 空载判定阈值（A）
#define NOLOAD_CURRENT_THRESHOLD 0.05f

extern pid_v pidv;
extern pid_i pidi;
void Control_Init(void);
#endif
