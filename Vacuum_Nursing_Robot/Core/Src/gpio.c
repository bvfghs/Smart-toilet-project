/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, water_hot_Pin|vacuum_fan_Pin|hot_fan_Pin|fan_hot_Pin
                          |RO_pump_Pin|S_RO_pump_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, valve_7_Pin|valve_8_Pin|valve_9_Pin|valve_10_Pin
                          |air_fan_Pin|anion_Pin|valve_1_Pin|valve_2_Pin
                          |valve_3_Pin|valve_4_5_Pin|valve_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : water_hot_Pin vacuum_fan_Pin hot_fan_Pin fan_hot_Pin
                           RO_pump_Pin S_RO_pump_Pin */
  GPIO_InitStruct.Pin = water_hot_Pin|vacuum_fan_Pin|hot_fan_Pin|fan_hot_Pin
                          |RO_pump_Pin|S_RO_pump_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : valve_7_Pin valve_8_Pin valve_9_Pin valve_10_Pin
                           air_fan_Pin anion_Pin valve_1_Pin valve_2_Pin
                           valve_3_Pin valve_4_5_Pin valve_6_Pin */
  GPIO_InitStruct.Pin = valve_7_Pin|valve_8_Pin|valve_9_Pin|valve_10_Pin
                          |air_fan_Pin|anion_Pin|valve_1_Pin|valve_2_Pin
                          |valve_3_Pin|valve_4_5_Pin|valve_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
