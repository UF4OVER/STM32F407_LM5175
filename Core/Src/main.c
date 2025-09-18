/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dac.h"
#include "dma.h"
#include "gpio.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ina226.h"
#include "key.h"
#include "lv_port_disp.h"
#include "st7789.h"
#include "uf4power.h"
#include "ui.h"
#include "ui_Screen1.h"
#include "usbd_cdc_if.h" // 里面有 CDC_Transmit_FS
#include <stdio.h>       // 重定向 printf
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
int _write(int file, char *ptr, int len)
{
    CDC_Transmit_FS((uint8_t *)ptr, len); // USB 虚拟串口发出去
}

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern DAC_HandleTypeDef hdac; // 使用 CubeMX 生成的 DAC 句柄

/* ========== 全局变量 ========== */
float target_voltage = 12.0f; // 目标电压 (V)
float target_current = 5.0f;  // 目标电流 (A)

uint16_t DAC_voltage = 0; // DAC 通道2控制电压
uint16_t DAC_current = 0; // DAC 通道1控制电流

int digit_index = 0; // 当前正在修改哪一位（通过左右键选择）

/* DAC 映射函数 */
static inline uint16_t VoltageToDac(float v)
{
    // 0 → 26.5V, 4095 → 0V
    if (v > 26.5f)
        v = 26.5f;
    if (v < 0.0f)
        v = 0.0f;
    return (uint16_t)((26.5f - v) * 4095.0f / 26.5f);
}

static inline uint16_t CurrentToDac(float i)
{
    // 0 → 0A, 4095 → 10A
    if (i > 10.0f)
        i = 10.0f;
    if (i < 0.0f)
        i = 0.0f;
    return (uint16_t)(i * 4095.0f / 10.0f);
}
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#define MAX_VOLTAGE 26.5f
#define DAC_MAX 4095.0f
#define voltage_to_dac(v) ((uint32_t)roundf((1.0f - (v / MAX_VOLTAGE)) * DAC_MAX))

// 当前设定电压
float V_setpoint = 12.0f;
int edit_pos = 0; // 0=十位,1=个位,2=小数

// 按键处理函数，和你的 process_key_events() 保持一致
extern void process_key_events(void);

// DAC 写函数
extern DAC_HandleTypeDef hdac;
static void dac_write_voltage(uint32_t value)
{
    if (value > 4095)
        value = 4095;
    HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, value);
}

// 调整设定值函数
static void edit_voltage_by_delta(int delta) // 存在同名函数，会冲突 libo6
{
    int tens = ((int)floorf(V_setpoint)) / 10;
    int ones = ((int)floorf(V_setpoint)) % 10;
    int tenths = (int)roundf((V_setpoint - floorf(V_setpoint)) * 10.0f) % 10;

    if (edit_pos == 0)
        tens += delta;
    else if (edit_pos == 1)
        ones += delta;
    else
        tenths += delta;

    int new_int = tens * 10 + ones;
    float new_v = new_int + tenths * 0.1f;
    if (new_v < 0.0f)
        new_v = 0.0f;
    if (new_v > MAX_VOLTAGE)
        new_v = MAX_VOLTAGE;
    V_setpoint = new_v;
}

// 左右移动编辑位
static void move_edit_pos(int dir)
{
    if (dir > 0)
        edit_pos = (edit_pos + 1) % 3;
    else
        edit_pos = (edit_pos + 2) % 3; // 左移
}

// 简单循环测试按键调节 DAC 输出
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{ // LVGL心跳与刷新
    if (htim->Instance == htim6.Instance)
    {
        lv_tick_inc(1);
    }
}

static void update_labels_cb(lv_timer_t *timer)
{
    float Vout = INA226_BusVoltage();
    static char buf[16];
    snprintf(buf, sizeof(buf), "%05.2f", Vout);
    lv_label_set_text(VoutLabel, buf);

    float Iout = INA226_Current();
    static char buf2[16];
    snprintf(buf2, sizeof(buf2), "%05.2f", Iout);
    lv_label_set_text(IoutLabel, buf2);

    float Pout = INA226_Power();
    static char buf3[16];
    snprintf(buf3, sizeof(buf3), "%05.2f", Pout);
    lv_label_set_text(PoutLabel, buf3);

    printf("Vout: %05.2f V\n", Vout);
    printf("Iout: %05.2f A\n", Iout);
    printf("Pout: %05.2f W\n", Pout);
}

void ui_task_init(void)
{

    lv_timer_t *t = lv_timer_create(update_labels_cb, 500, NULL);
    if (t == NULL)
        printf("Timer create failed!\n");
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_TIM6_Init();
    MX_TIM7_Init();
    MX_SPI1_Init();
    MX_I2C1_Init();
    MX_I2C2_Init();
    MX_USB_DEVICE_Init();
    MX_DAC_Init();
    MX_TIM2_Init();
    /* USER CODE BEGIN 2 */
    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_Base_Start_IT(&htim7);

    ST7789_Init();
    //    ST7789_Test();
    HAL_Delay(100); // 10ms循环

    lv_init();
    lv_port_disp_init();
    HAL_Delay(100); // 10ms循环
    ui_init();
    HAL_Delay(100); // 10ms循环

    //    VPID_init();
    //    IPID_init();

    ui_task_init();
    HAL_Delay(100); // 10ms循环
                    //    Control_Init();  //？未启用pid？libo1

    HAL_DAC_Start(&hdac, DAC_CHANNEL_1); // 电流
    HAL_DAC_Start(&hdac, DAC_CHANNEL_2); // 电压

    //    HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2, DAC_ALIGN_12B_R, 4095);
    /* USER CODE END 2 */
    OUTPUT_ENABLE();
    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        process_key_events(); // 扫描按键

        // 按键处理
        if (UP_KEY_pressed)
        {
            edit_voltage_by_delta(+1);
            UP_KEY_pressed = 0;
        }
        if (DOWN_KEY_pressed)
        {
            edit_voltage_by_delta(-1);
            DOWN_KEY_pressed = 0;
        }
        if (RIGHT_KEY_pressed)
        {
            move_edit_pos(+1);
            RIGHT_KEY_pressed = 0;
        }
        if (LEFT_KEY_pressed)
        {
            move_edit_pos(-1);
            LEFT_KEY_pressed = 0;
        }

        // 写 DAC
        uint32_t dacv = voltage_to_dac(V_setpoint);
        dac_write_voltage(dacv);

        // 打印调试
        printf("Setpoint: %.2f V -> DAC: %lu\n", V_setpoint, dacv);

        lv_timer_handler(); // 让 LVGL 和定时器跑起来
        HAL_Delay(5);
        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
