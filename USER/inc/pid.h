//
// Created by 33974 on 2025/9/17.
//

#ifndef STM32F407_LM5175_PID_H
#define STM32F407_LM5175_PID_H

#include "main.h"


#define PID_V_P 0.85
#define PID_V_I 0.038
#define PID_V_D 0.0016

#define PID_I_P 1
#define PID_I_I 0
#define PID_I_D 0

// PID输出限幅值
#define PID_OUTPUT_MAX  100000.0f
#define PID_OUTPUT_MIN -100000.0f
#define INTEGRAL_MAX    100000.0f

#define D_FILTER_ALPHA 0.2f


// CDC接收缓冲区
#define CDC_RX_BUFFER_SIZE 64

extern volatile uint8_t cdc_data_received;
extern char cdc_rx_buffer[];

typedef struct {
    float SetVoltage;
    float ActualVoltage;

    float Kp, Ki, Kd;
    float err, err_last;
    float integral;
    float derivative;
    float output;

    float output_max;
    float output_min;
    float integral_max;

    float d_filter_alpha; // D项滤波系数
} pid_v;

typedef struct {
    float SetCurrent;
    float ActualCurrent;

    float Kp, Ki, Kd;
    float err, err_last;
    float integral;
    float derivative;
    float output;

    float output_max;
    float output_min;
    float integral_max;

    float d_filter_alpha;
} pid_i;

extern pid_v pidv;
extern pid_i pidi;


void VPID_init( void);
void IPID_init( void);
float VPID_realize( float v, float v_r);
float IPID_realize( float i, float i_r);

// 添加用于处理CDC命令的函数
void process_pid_command(char* command);
void update_pid_parameters(char pid_type, float kp, float ki, float kd);

extern pid_v pidv;
extern pid_i pidi;

#endif
