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
#include "DescriptMotorControl.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct 
{
	uint32_t Ch1;
	uint32_t Ch1_DIM;
		
	uint32_t Ch2;
	uint32_t Ch2_DIM;
	
	uint32_t Ch3;
	uint32_t Ch3_DIM;
	
	uint32_t Ch4;
	uint32_t Ch4_DIM;
	
	uint32_t BaudRate;
	uint32_t SlaveAddress;

}settings_t;

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
//void time_1mS(void);

//uint32_t flash_read(uint32_t address);
void flash_write(uint32_t address,uint32_t data);
//void flash_write_d(uint32_t address,double *data);
//double flash_read_d(uint32_t address);
void Flash_ReadParams(settings_t *params, uint32_t source_adr);
void FLASH_WriteSettings(settings_t params, uint32_t pageAdr);


void flash_lock(void);
void flash_unlock(void);
void flash_erase_page(uint32_t address);
uint8_t flash_ready(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RS485_1_Rs_Pin GPIO_PIN_1
#define RS485_1_Rs_GPIO_Port GPIOA
#define B_Pin GPIO_PIN_12
#define B_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_13
#define G_GPIO_Port GPIOB
#define R_Pin GPIO_PIN_14
#define R_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

// адреса для сохранения во flash
#define StartSettingsAddres 0x0803fc00

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
