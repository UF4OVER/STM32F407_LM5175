//
// Created by 33974 on 2025/9/17.
//

#include "pid.h"
#include "stdio.h"

pid_v pidv;
pid_i pidi;
//pid位置式
void VPID_init()
{
    printf("PID_init begin \n");
    pidv.SetVoltage= 5.0;		  	// 设定的预期电压值，默认12V
    pidv.ActualVoltage= 0.0;			// adc实际电压值
    pidv.err= 0.0;				    // 当前次实际与理想的偏差
    pidv.err_last=0.0;			    // 上一次的偏差
    pidv.voltage= 0.0;			    // 控制电压值
    pidv.integral= 0.0;			  	// 积分值
    pidv.Kp= 0.2;				    // 比例系数
    pidv.Ki= 0.15;				    // 积分系数
    pidv.Kd= 0.2;				    // 微分系数
    printf("vPID_init end \n");
}
void IPID_init()
{
    printf("PID_init begin \n");
    pidi.SetCurrent= 2.0;		  	// 设定的预期电流值，默认5A
    pidi.ActualCurrent= 0.0;
    pidi.current= 0.0;			    // 输出电流值
    pidi.err= 0.0;				    // 当前次实际与理想的偏差
    pidi.err_last=0.0;			    // 上一次的偏差
    pidi.integral= 0.0;			  	// 积分值
    pidi.Kp= 0.2;
    pidi.Ki= 0.15;
    pidi.Kd= 0.2;
    printf("iPID_init end \n");
}

float VPID_realize( float v, float v_r)
{
    pidv.SetVoltage = v;			// 固定值传入
    pidv.ActualVoltage = v_r;	// 实际传入
    pidv.err = pidv.SetVoltage - pidv.ActualVoltage;	//计算偏差
    pidv.integral += pidv.err;						//积分求和
    pidv.result = pidv.Kp * pidv.err + pidv.Ki * pidv.integral + pidv.Kd * ( pidv.err - pidv.err_last);//位置式公式
    pidv.err_last = pidv.err;				//留住上一次误差
    return pidv.result;
}
float IPID_realize( float i, float i_r)
{
    pidi.SetCurrent = i;			// 固定值传入
    pidi.ActualCurrent = i_r;	// 实际传入
    pidi.err = pidi.SetCurrent - pidi.ActualCurrent;	//计算偏差
    pidi.integral += pidi.err;						//积分求和
    pidi.result = pidi.Kp * pidi.err + pidi.Ki * pidi.integral + pidi.Kd * ( pidi.err - pidi.err_last);//位置式公式
    pidi.err_last = pidi.err;				//留住上一次误差
    return pidi.result;
}
