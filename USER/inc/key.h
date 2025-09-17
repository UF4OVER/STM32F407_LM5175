//
// Created by 33974 on 2025/9/17.
//
#include "main.h"

#ifndef STM32F407_LM5175_KEY_H
#define STM32F407_LM5175_KEY_H
/* USER CODE BEGIN PV */
// 按键引脚定义
#define FALSE_KEY   KEY_1_Pin
#define PAUSED_KEY  KEY_2_Pin
#define RECOVER_KEY KEY_3_Pin
#define RIGHT_KEY   KEY_4_Pin
#define LEFT_KEY    KEY_5_Pin
#define DOWN_KEY    KEY_6_Pin
#define UP_KEY      KEY_7_Pin
#define KEY_GPIO_PORT GPIOD

// 按键状态变量

extern volatile uint8_t FALSE_KEY_pressed;
extern volatile uint8_t PAUSED_KEY_pressed;
extern volatile uint8_t RECOVER_KEY_pressed;
extern volatile uint8_t RIGHT_KEY_pressed;
extern volatile uint8_t LEFT_KEY_pressed;
extern volatile uint8_t DOWN_KEY_pressed;
extern volatile uint8_t UP_KEY_pressed;
/* USER CODE END PV */
void process_key_events(void);
/* USER CODE END PFP */
#endif //STM32F407_LM5175_KEY_H
