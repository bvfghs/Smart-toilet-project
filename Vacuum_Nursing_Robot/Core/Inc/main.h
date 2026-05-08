/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "hmi.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define H_vacuum_fan_Pin GPIO_PIN_2
#define H_vacuum_fan_GPIO_Port GPIOB
#define water_hot_Pin GPIO_PIN_7
#define water_hot_GPIO_Port GPIOE
#define vacuum_fan_Pin GPIO_PIN_8
#define vacuum_fan_GPIO_Port GPIOE
#define hot_fan_Pin GPIO_PIN_9
#define hot_fan_GPIO_Port GPIOE
#define fan_hot_Pin GPIO_PIN_10
#define fan_hot_GPIO_Port GPIOE
#define RO_pump_Pin GPIO_PIN_13
#define RO_pump_GPIO_Port GPIOE
#define S_RO_pump_Pin GPIO_PIN_14
#define S_RO_pump_GPIO_Port GPIOE
#define debug_TX_Pin GPIO_PIN_10
#define debug_TX_GPIO_Port GPIOB
#define debug_RX_Pin GPIO_PIN_11
#define debug_RX_GPIO_Port GPIOB
#define valve_7_Pin GPIO_PIN_10
#define valve_7_GPIO_Port GPIOD
#define valve_8_Pin GPIO_PIN_11
#define valve_8_GPIO_Port GPIOD
#define valve_9_Pin GPIO_PIN_12
#define valve_9_GPIO_Port GPIOD
#define valve_10_Pin GPIO_PIN_13
#define valve_10_GPIO_Port GPIOD
#define air_fan_Pin GPIO_PIN_14
#define air_fan_GPIO_Port GPIOD
#define anion_Pin GPIO_PIN_15
#define anion_GPIO_Port GPIOD
#define HMI_TX_Pin GPIO_PIN_9
#define HMI_TX_GPIO_Port GPIOA
#define HMI_RX_Pin GPIO_PIN_10
#define HMI_RX_GPIO_Port GPIOA
#define valve_1_Pin GPIO_PIN_3
#define valve_1_GPIO_Port GPIOD
#define valve_2_Pin GPIO_PIN_4
#define valve_2_GPIO_Port GPIOD
#define valve_3_Pin GPIO_PIN_5
#define valve_3_GPIO_Port GPIOD
#define valve_4_5_Pin GPIO_PIN_6
#define valve_4_5_GPIO_Port GPIOD
#define valve_6_Pin GPIO_PIN_7
#define valve_6_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
