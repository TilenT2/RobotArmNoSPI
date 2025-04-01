/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENABLE7_Pin GPIO_PIN_13
#define ENABLE7_GPIO_Port GPIOC
#define ENABLE6_Pin GPIO_PIN_0
#define ENABLE6_GPIO_Port GPIOC
#define ENABLE5_Pin GPIO_PIN_1
#define ENABLE5_GPIO_Port GPIOC
#define ENABLE4_Pin GPIO_PIN_2
#define ENABLE4_GPIO_Port GPIOC
#define ENABLE3_Pin GPIO_PIN_3
#define ENABLE3_GPIO_Port GPIOC
#define STEP1_Pin GPIO_PIN_0
#define STEP1_GPIO_Port GPIOA
#define STEP2_Pin GPIO_PIN_1
#define STEP2_GPIO_Port GPIOA
#define STEP3_Pin GPIO_PIN_2
#define STEP3_GPIO_Port GPIOA
#define STEP4_Pin GPIO_PIN_3
#define STEP4_GPIO_Port GPIOA
#define ENABLE1_Pin GPIO_PIN_4
#define ENABLE1_GPIO_Port GPIOA
#define HYSTERESIS_Pin GPIO_PIN_5
#define HYSTERESIS_GPIO_Port GPIOA
#define MICROSTEPP_Pin GPIO_PIN_7
#define MICROSTEPP_GPIO_Port GPIOA
#define CSN1_Pin GPIO_PIN_4
#define CSN1_GPIO_Port GPIOC
#define CSN2_Pin GPIO_PIN_5
#define CSN2_GPIO_Port GPIOC
#define CSN3_Pin GPIO_PIN_0
#define CSN3_GPIO_Port GPIOB
#define CSN4_Pin GPIO_PIN_1
#define CSN4_GPIO_Port GPIOB
#define CSN5_Pin GPIO_PIN_2
#define CSN5_GPIO_Port GPIOB
#define CSN6_Pin GPIO_PIN_10
#define CSN6_GPIO_Port GPIOB
#define CSN7_Pin GPIO_PIN_11
#define CSN7_GPIO_Port GPIOB
#define DIR1_Pin GPIO_PIN_12
#define DIR1_GPIO_Port GPIOB
#define DIR2_Pin GPIO_PIN_13
#define DIR2_GPIO_Port GPIOB
#define DIR3_Pin GPIO_PIN_14
#define DIR3_GPIO_Port GPIOB
#define DIR4_Pin GPIO_PIN_15
#define DIR4_GPIO_Port GPIOB
#define DIR5_Pin GPIO_PIN_6
#define DIR5_GPIO_Port GPIOC
#define DIR6_Pin GPIO_PIN_7
#define DIR6_GPIO_Port GPIOC
#define DIR7_Pin GPIO_PIN_8
#define DIR7_GPIO_Port GPIOC
#define ENABLE2_Pin GPIO_PIN_9
#define ENABLE2_GPIO_Port GPIOC
#define STEP5_Pin GPIO_PIN_8
#define STEP5_GPIO_Port GPIOA
#define STEP6_Pin GPIO_PIN_9
#define STEP6_GPIO_Port GPIOA
#define STEP7_Pin GPIO_PIN_10
#define STEP7_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
