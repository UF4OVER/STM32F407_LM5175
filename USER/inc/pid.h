//
// Created by 33974 on 2025/9/17.
//

#ifndef STM32F407_LM5175_PID_H
#define STM32F407_LM5175_PID_H

#include "main.h"

typedef struct
{
    float SetVoltage;	  	//定义设定值
    float ActualVoltage;	//定义实际值
    float err;			    //定义偏差值
    float err_last;		  	//定义上一个偏差值
    float Kp,Ki,Kd;		  	//定义比例、积分、微分系数
    float result;		    //pid计算结果
    float voltage;		  	//定义电压值（控制执行器的变量）0-5v右转 5-10v左转
    float integral;		  	//定义积分值
}pid_v;

typedef struct
{
    float SetCurrent;
    float ActualCurrent;
    float err;
    float err_last;
    float Kp,Ki,Kd;
    float result;
    float current;
    float integral;
}pid_i;

void VPID_init( void);
void IPID_init( void);
float VPID_realize( float v, float v_r);
float IPID_realize( float i, float i_r);

#endif
