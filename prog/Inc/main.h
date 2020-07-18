/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void time_1mS(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RS485_1_Rs_Pin GPIO_PIN_1
#define RS485_1_Rs_GPIO_Port GPIOA
#define DIN_CH3_Pin GPIO_PIN_0
#define DIN_CH3_GPIO_Port GPIOB
#define DIN_CH4_Pin GPIO_PIN_1
#define DIN_CH4_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_12
#define B_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_13
#define G_GPIO_Port GPIOB
#define R_Pin GPIO_PIN_14
#define R_GPIO_Port GPIOB
#define DIN_CH1_Pin GPIO_PIN_4
#define DIN_CH1_GPIO_Port GPIOB
#define DIN_CH2_Pin GPIO_PIN_5
#define DIN_CH2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
