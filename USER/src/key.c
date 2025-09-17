//
// Created by 33974 on 2025/9/17.
//

#include "key.h"
#include "stdio.h"
#include "main.h"
#include "misc/lv_anim.h"
#include "core/lv_obj.h"
#include "ui_Screen1.h"

/* USER CODE BEGIN 4 */

volatile uint8_t FALSE_KEY_pressed;
volatile uint8_t PAUSED_KEY_pressed;
volatile uint8_t RECOVER_KEY_pressed;
volatile uint8_t RIGHT_KEY_pressed;
volatile uint8_t LEFT_KEY_pressed;
volatile uint8_t DOWN_KEY_pressed;
volatile uint8_t UP_KEY_pressed;
/**
  * @brief  EXTI line detection callbacks
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    {
        switch (GPIO_Pin){
        case FALSE_KEY:
            FALSE_KEY_pressed = 1;
            break;
        case PAUSED_KEY:
            PAUSED_KEY_pressed = 1;
            break;
        case RECOVER_KEY:
            RECOVER_KEY_pressed = 1;
            break;
        case RIGHT_KEY:
            RIGHT_KEY_pressed = 1;
            break;
        case LEFT_KEY:
            LEFT_KEY_pressed = 1;
            break;
        case DOWN_KEY:
            DOWN_KEY_pressed = 1;
            break;
        case UP_KEY:
            UP_KEY_pressed = 1;
            break;
        default:
            break;
    }
}
}


/**
  * @brief  处理按键事件
  * @retval None
  */
void process_key_events(void)
{
    static uint32_t last_key_time = 0;
    uint32_t current_time = HAL_GetTick();
    // 简单的消抖处理，至少间隔20ms才处理下一次按键
    if (current_time - last_key_time < 20) {
        return;
    }

    if (FALSE_KEY_pressed)
    {
        FALSE_KEY_pressed = 0;
        last_key_time = current_time;

        int is_checked = lv_obj_has_state(ui_Switch1, LV_STATE_CHECKED);
        printf("Current switch state: %s\n", is_checked ? "ON" : "OFF");

        if (is_checked) {
            lv_obj_clear_state(ui_Switch1, LV_STATE_CHECKED);
            HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_RESET);
            printf("Switch turned OFF\n");
        } else {
            lv_obj_add_state(ui_Switch1, LV_STATE_CHECKED);
            HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_SET);
            printf("Switch turned ON\n");
        }
        printf("FALSE_KEY pressed\n");

    }

    if (PAUSED_KEY_pressed)
    {
        PAUSED_KEY_pressed = 0;
        last_key_time = current_time;
        printf("PAUSED_KEY pressed\n");
        // 添加KEY2的处理逻辑
    }

    if (RECOVER_KEY_pressed)
    {
        RECOVER_KEY_pressed = 0;
        last_key_time = current_time;
        printf("RECOVER_KEY pressed\n");
        // 添加KEY3的处理逻辑
    }
}


