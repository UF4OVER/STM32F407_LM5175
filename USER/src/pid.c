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

// =================== 电压环 PID ===================
void VPID_init()
{
    printf("vPID_init begin \n");
    pidv.SetVoltage = DEFAULT_V_SET;
    pidv.ActualVoltage = 0.0f;

    pidv.err = 0.0f;
    pidv.err_last = 0.0f;
    pidv.integral = 0.0f;
    pidv.derivative = 0.0f;

    pidv.Kp = PID_V_P;
    pidv.Ki = PID_V_I;
    pidv.Kd = PID_V_D;

    pidv.integral_max = INTEGRAL_MAX;
    pidv.output_min   = PID_OUTPUT_MIN;
    pidv.output_max   = PID_OUTPUT_MAX;

    pidv.d_filter_alpha = D_FILTER_ALPHA;
    pidv.output = 0.0f;

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
    pidi.integral = 0.0f;
    pidi.derivative = 0.0f;

    pidi.Kp = PID_I_P;
    pidi.Ki = PID_I_I;
    pidi.Kd = PID_I_D;

    pidi.integral_max = INTEGRAL_MAX;
    pidi.output_min   = PID_OUTPUT_MIN;
    pidi.output_max   = PID_OUTPUT_MAX;

    pidi.d_filter_alpha = D_FILTER_ALPHA;
    pidi.output = 0.0f;

    printf("iPID_init end \n");
}

// =================== 电压环计算 ===================
float VPID_realize(float set_v, float act_v)
{
    pidv.SetVoltage = set_v;
    pidv.ActualVoltage = act_v;

    pidv.err = pidv.SetVoltage - pidv.ActualVoltage;

    // P项
    float p_term = pidv.Kp * pidv.err;

    // I项 (积分抗饱和)
    if (pidv.output < pidv.output_max && pidv.output > pidv.output_min) {
        pidv.integral += pidv.err * PID_DT;
        if (pidv.integral > pidv.integral_max) pidv.integral = pidv.integral_max;
        if (pidv.integral < -pidv.integral_max) pidv.integral = -pidv.integral_max;
    }
    float i_term = pidv.Ki * pidv.integral;

    // D项 (带滤波)
    float d_raw = (pidv.err - pidv.err_last) / PID_DT;
    pidv.derivative = pidv.d_filter_alpha * d_raw +
                      (1.0f - pidv.d_filter_alpha) * pidv.derivative;
    float d_term = pidv.Kd * pidv.derivative;

    // PID 输出
    float result = p_term + i_term + d_term;

    // 输出限幅
    if (result > pidv.output_max) result = pidv.output_max;
    if (result < pidv.output_min) result = pidv.output_min;

    pidv.err_last = pidv.err;
    pidv.output = result;
    return result;
}

// =================== 电流环计算 ===================
float IPID_realize(float i, float i_r)
{
    pidi.SetCurrent = i;
    pidi.ActualCurrent = i_r;

    pidi.err = pidi.SetCurrent - pidi.ActualCurrent;

    // P项
    float p_term = pidi.Kp * pidi.err;

    // I项 (积分抗饱和)
    if (pidi.output < pidi.output_max && pidi.output > pidi.output_min) {
        pidi.integral += pidi.err * PID_DT;
        if (pidi.integral > pidi.integral_max) pidi.integral = pidi.integral_max;
        if (pidi.integral < -pidi.integral_max) pidi.integral = -pidi.integral_max;
    }
    float i_term = pidi.Ki * pidi.integral;

    // D项 (带滤波)
    float d_raw = (pidi.err - pidi.err_last) / PID_DT;
    pidi.derivative = pidi.d_filter_alpha * d_raw +
                      (1.0f - pidi.d_filter_alpha) * pidi.derivative;
    float d_term = pidi.Kd * pidi.derivative;

    // PID 输出
    float result = p_term + i_term + d_term;

    // 输出限幅
    if (result > pidi.output_max) result = pidi.output_max;
    if (result < pidi.output_min) result = pidi.output_min;

    pidi.err_last = pidi.err;
    pidi.output = result;
    return result;
}
