//
// Created by 33974 on 2025/9/17.
//

#include "pid.h"
#include "stdio.h"
#include "uf4power.h"

pid_v pidv;
pid_i pidi;

// pid位置式
void VPID_init()
{
    printf("PID_init begin \n");
    pidv.SetVoltage = DEFAULT_V_SET;    // 设定的预期电压值，默认12V
    pidv.ActualVoltage = 0.0; // adc实际电压值
    pidv.err = 0.0;           // 当前次实际与理想的偏差
    pidv.err_last = 0.0;      // 上一次的偏差
    pidv.voltage = 0.0;       // 控制电压值
    pidv.integral = 0.0;      // 积分值
    pidv.Kp = PID_V_P;  // 1 //参考：将pid的参数初始从1,0,0开始，先P。位置式pid一般不用i，调pd即可，d参考实际，可不调 libo3
                    // pid参数最好传出，以宏定义的形式修改
    pidv.Ki = PID_V_I; // 积分系数
    pidv.Kd = PID_V_D;  // 微分系数
    printf("vPID_init end \n");
}
void IPID_init()
{
    printf("PID_init begin \n");
    pidi.SetCurrent = DEFAULT_I_SET; // 设定的预期电流值
    pidi.ActualCurrent = 0.0;
    pidi.current = 0.0;  // 输出电流值
    pidi.err = 0.0;      // 当前次实际与理想的偏差
    pidi.err_last = 0.0; // 上一次的偏差
    pidi.integral = 0.0; // 积分值
    pidi.Kp = PID_I_P;
    pidi.Ki = PID_I_I;
    pidi.Kd = PID_I_D;
    printf("iPID_init end \n");
}

// 参考：pid计算要有限幅，Pmax和PImax，防止输出爆炸 libo4
float VPID_realize(float set_v, float act_v)
{
    pidv.SetVoltage = set_v;
    pidv.ActualVoltage = act_v;

    // 计算偏差 = 目标 - 实测
    pidv.err = pidv.SetVoltage - pidv.ActualVoltage;

    // 位置式 PID
    float p_term = pidv.Kp * pidv.err;
    pidv.integral += pidv.err; // 积分累加
    float i_term = pidv.Ki * pidv.integral;
    float d_term = pidv.Kd * (pidv.err - pidv.err_last);

    float result = p_term + i_term + d_term;

    pidv.err_last = pidv.err;
    return result;
}

float IPID_realize(float i, float i_r)
{
    pidi.SetCurrent = i;                                                                               // 固定值传入
    pidi.ActualCurrent = i_r;                                                                          // 实际传入
    pidi.err = pidi.SetCurrent - pidi.ActualCurrent;                                                   // 计算偏差
    pidi.integral += pidi.err;                                                                         // 积分求和
    pidi.result = pidi.Kp * pidi.err + pidi.Ki * pidi.integral + pidi.Kd * (pidi.err - pidi.err_last); // 位置式公式
    pidi.err_last = pidi.err;                                                                          // 留住上一次误差
    return pidi.result;
}
