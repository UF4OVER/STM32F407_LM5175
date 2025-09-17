
// uf4power.h
#ifndef UF4POWER_H
#define UF4POWER_H

#include <stdint.h>
#include "dac.h"
#include "pid.h"

#define MAX_VOLTAGE 26.0f
#define MAX_CURRENT 10.0f
#define DAC_MAX 4095           // 12位DAC

// DAC输出与实际值的映射关系
#define DAC_VOLTAGE_SCALE (MAX_VOLTAGE / DAC_MAX)  // 每个DAC单位对应电压值
#define DAC_CURRENT_SCALE (MAX_CURRENT / DAC_MAX)  // 每个DAC单位对应电流值

// DAC Handle
extern DAC_HandleTypeDef hdac;

/*========================= 全局变量 =========================*/
extern float target_voltage;
extern float target_current;

extern uint16_t DAC_voltage;
extern uint16_t DAC_current;

extern int digit_index;  // 当前选择位 0=十位,1=个位,2=十分位,3=百分位
extern uint8_t mode;     // 当前模式 0=电压, 1=电流

extern float step_value[4];

// PID 控制器
extern pid_v pidv;
extern pid_i pidi;

extern uint8_t output_enabled;  // 输出使能标志

void UpdateDAC(void);
void ProcessKeys(void);
void UpdateLVGLLabels(void);
void UF4Power_Init(void);
void ControlLoop(void);

#endif
