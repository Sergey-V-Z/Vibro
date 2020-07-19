/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
settings_t Settings;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_CAN_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	Flash_ReadParams(&Settings, StartSettingsAddres);

// если настройки пусты
	if((Settings.BaudRate == 0) | (Settings.BaudRate == 0xFFFFFFFF))
	{
		Settings.Ch1 = 0;
		Settings.Ch1_DIM = 0;
		Settings.Ch2 = 0;
		Settings.Ch2_DIM = 0;
		Settings.Ch3 = 0;
		Settings.Ch3_DIM = 0;
		Settings.Ch4 = 0;
		Settings.Ch4_DIM = 0;
		Settings.BaudRate = 115200;
		Settings.SlaveAddress = 0x0C;
		FLASH_WriteSettings(Settings, StartSettingsAddres);
	}
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init(); 
  /* Start scheduler */
  osKernelStart();
 
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL14;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void FLASH_WriteSettings(settings_t params, uint32_t pageAdr) {

	uint8_t i;

	// Опеределим, сколько блоков памяти у нас определено под параметры
	// Это необходимо для определения количества циклов чтения/записи параметров
	uint32_t PARAMS_WORD_CNT =	sizeof(settings_t) / sizeof(uint32_t); // Расчитывается исходя из размера структуры в памяти МК деленного на размер блока (4 байта)

	uint32_t *source_adr = (void *)&params;

	flash_unlock();                                                                 // Разблокируем память для записи
	flash_erase_page(pageAdr);                                                       // Очистим страницу памяти параметров №0

	for (i = 0; i < PARAMS_WORD_CNT; ++i) {
                flash_write((uint32_t)(pageAdr + i*4), *(source_adr + i));        // Запишем новое значение памяти
        }

	flash_lock();                                                                   // Заблокируем Flash

}
void Flash_ReadParams(settings_t *params, uint32_t adr) {

	uint32_t *dest_adr = (void *)params; 
	uint32_t *source_adr = (uint32_t *)adr;
	// Определяем адрес, куда будем писать
	// Опеределим, сколько блоков памяти у нас определено под параметры
	// Это необходимо для определения количества циклов чтения/записи параметров
	uint32_t PARAMS_WORD_CNT =	sizeof(settings_t) / sizeof(uint32_t); // Расчитывается исходя из размера структуры в памяти МК деленного на размер блока (4 байта)

	for (uint16_t i=0; i < PARAMS_WORD_CNT; ++i) {                                  // В цикле производим чтение
		*(dest_adr + i) = *(__IO uint32_t*)(source_adr + i);                    // Само чтение
	}
}

uint8_t flash_ready(void) {
	return !(FLASH->SR & FLASH_SR_BSY);
}

//void flash_erase_all_pages(void) {
//    FLASH->CR |= FLASH_CR_MER;
//    FLASH->CR |= FLASH_CR_STRT;
//    while(!flash_ready())
//    	;
//    FLASH->CR &= FLASH_CR_MER;
//}

void flash_erase_page(uint32_t address) {
    FLASH->CR|= FLASH_CR_PER;
    FLASH->AR = address;
    FLASH->CR|= FLASH_CR_STRT;
    while(!flash_ready())
    	;
    FLASH->CR&= ~FLASH_CR_PER;
}


void flash_unlock(void) {
	  FLASH->KEYR = FLASH_KEY1;
	  FLASH->KEYR = FLASH_KEY2;
}

void flash_lock(void) {
	FLASH->CR |= FLASH_CR_LOCK;
}


void flash_write(uint32_t address,uint32_t data) {

	FLASH->CR |= FLASH_CR_PG;
	while(!flash_ready())
		;
    *(__IO uint16_t*)address = (uint16_t)data;
	while(!flash_ready())
		;
	address+=2;
	data>>=16;
    *(__IO uint16_t*)address = (uint16_t)data;
	while(!flash_ready())
		;
    FLASH->CR &= ~(FLASH_CR_PG);
}

/* USER CODE END 4 */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM7 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM7) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
	if (htim->Instance == TIM3) {
		time_1mS();
	}
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
