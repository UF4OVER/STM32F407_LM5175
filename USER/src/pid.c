//
// Created by 33974 on 2025/9/17.
//

#include "pid.h"
#include "stdio.h"
#include "uf4power.h"
#include "usbd_cdc_if.h"
#include <string.h>
#include <stdlib.h>

#define PID_DT 0.005f

pid_v pidv;
pid_i pidi;


void VPID_init()
{
    printf("vPID_init begin \n");
    pidv.SetVoltage = DEFAULT_V_SET;
    pidv.ActualVoltage = 0.0f;

    pidv.err = 0.0f;
    pidv.err_last = 0.0f;
    pidv.err_llast = 0.0f;  // 增加前次误差
    pidv.integral = 0.0f;
    pidv.derivative = 0.0f;

    pidv.Kp = PID_V_P;
    pidv.Ki = PID_V_I;
    pidv.Kd = PID_V_D;

    pidv.integral_max = INTEGRAL_MAX;
    pidv.output_min   = PID_OUTPUT_MIN;
    pidv.output_max   = PID_OUTPUT_MAX;

    pidv.d_filter_alpha = D_FILTER_ALPHA;
    // 初始化输出值为设定值
    pidv.output = DEFAULT_V_SET;

    printf("vPID_init end \n");
}

// =================== 电流环 PID ===================
void IPID_init()
{
    printf("iPID_init begin \n");
    pidi.SetCurrent = DEFAULT_I_SET;
    pidi.ActualCurrent = 0.0f;

    pidi.err = 0.0f;
    pidi.err_last = 0.0f;
    pidi.err_llast = 0.0f;  // 增加前次误差
    pidi.integral = 0.0f;
    pidi.derivative = 0.0f;

    pidi.Kp = PID_I_P;
    pidi.Ki = PID_I_I;
    pidi.Kd = PID_I_D;

    pidi.integral_max = INTEGRAL_MAX;
    pidi.output_min   = PID_OUTPUT_MIN;
    pidi.output_max   = PID_OUTPUT_MAX;

    pidi.d_filter_alpha = D_FILTER_ALPHA;
    // 初始化输出值为设定值
    pidi.output = DEFAULT_I_SET;

    printf("iPID_init end \n");
}


// =================== 电压环计算 (增量式PID) ===================
float VPID_realize(float set_v, float act_v)
{
    pidv.SetVoltage = set_v;
    pidv.ActualVoltage = act_v;

    // 更新误差值
    pidv.err_llast = pidv.err_last;
    pidv.err_last = pidv.err;
    pidv.err = pidv.SetVoltage - pidv.ActualVoltage;

    // 计算增量
    float delta_p = pidv.Kp * (pidv.err - pidv.err_last);
    float delta_i = pidv.Ki * pidv.err;
    float delta_d = pidv.Kd * (pidv.err - 2 * pidv.err_last + pidv.err_llast);

    // 计算输出增量
    float delta_output = delta_p + delta_i + delta_d;

    // 累加到输出值
    pidv.output += delta_output;

    // 输出限幅
    if (pidv.output > pidv.output_max) pidv.output = pidv.output_max;
    if (pidv.output < pidv.output_min) pidv.output = pidv.output_min;

    return pidv.output;
}

// =================== 电流环计算 (增量式PID) ===================
float IPID_realize(float i, float i_r)
{
    pidi.SetCurrent = i;
    pidi.ActualCurrent = i_r;

    // 更新误差值
    pidi.err_llast = pidi.err_last;
    pidi.err_last = pidi.err;
    pidi.err = pidi.SetCurrent - pidi.ActualCurrent;

    // 计算增量
    float delta_p = pidi.Kp * (pidi.err - pidi.err_last);
    float delta_i = pidi.Ki * pidi.err;
    float delta_d = pidi.Kd * (pidi.err - 2 * pidi.err_last + pidi.err_llast);

    // 计算输出增量
    float delta_output = delta_p + delta_i + delta_d;

    // 累加到输出值
    pidi.output += delta_output;

    // 输出限幅
    if (pidi.output > pidi.output_max) pidi.output = pidi.output_max;
    if (pidi.output < pidi.output_min) pidi.output = pidi.output_min;

    return pidi.output;
}
