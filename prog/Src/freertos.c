/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "mb.h"
#include "mbport.h"

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
/* USER CODE BEGIN Variables */
extern settings_t Settings;

extern TIM_HandleTypeDef htim3;

									//Status,	CMD,	Mode,				time_mS,	Start_time_mS
motor_t Out[4] = {{Off,			Off,	On_Off,			0,				0},
									{Off,			Off,	On_Off,			0,				0},
									{Off,			Off,	On_Off,			0,				0},
									{Off,			Off,	On_Off,			0,				0}};

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
double map(double x, double in_min, double in_max, double out_min, double out_max);
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	
  eMBErrorCode eStatus = eMBInit( MB_RTU, Settings.SlaveAddress, 3, Settings.BaudRate, MB_PAR_NONE );
  eStatus = eMBEnable();
	HAL_TIM_Base_Start_IT(&htim3);
  /* Infinite loop */
  for(;;)
  {
    eStatus = eMBPoll();		
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
// В этой функции производится обнуление таймера для синхронизации с сетью и выключение симисторов
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  __disable_irq ();
  
        HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
        HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
        HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
        HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	
  __enable_irq ();
}


/*description https://www.freemodbus.org/api/group__modbus__registers.html*/
//0x04
eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    if(usAddress == 0 ){}
    else{usAddress--;} 

    eMBErrorCode    eStatus = MB_ENOERR;
//    int             iRegIndex;

//    if( ( usAddress >= RECEIV_INPUT_START ) && ( usAddress + usNRegs >= RECEIV_INPUT_START + RECEIV_INPUT_NREGS ) )
//    {
//        iRegIndex = ( int )( usAddress - ReceivInputStart );
//		
//        osMutexWait(mutex_modbusHandle, 10);
//        while( usNRegs > 0 )
//        {
//			// проверить правилность упаковки байтов
//            *pucRegBuffer++ = ( unsigned char )( ReceivInputBuf[iRegIndex] >> 8 );
//            *pucRegBuffer++ = ( unsigned char )( ReceivInputBuf[iRegIndex] & 0xFF );
//            iRegIndex++;
//            usNRegs--;
//        }
//        osMutexRelease(mutex_modbusHandle);		
//	//HAL_GPIO_TogglePin(User_LED_GPIO_Port, User_LED_Pin);
//    }
//    else
    {
	//HAL_GPIO_TogglePin(User_LED_GPIO_Port, User_LED_Pin);
        eStatus = MB_ENOREG;			
    }

    return eStatus;
}
//0x03 0x06 0x10
eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
    //uint8_t CMD[5] = {0};
    volatile HAL_StatusTypeDef status;

    if(usAddress == 0 ){}
    else{usAddress--;} 

    eMBErrorCode    eStatus = MB_ENOERR;


    // переключатель чтение запись
    switch (eMode)
    {
      case MB_REG_READ:
      {	
        break;
      }
      case MB_REG_WRITE:
      {	
        //переключатель по адресам регистра
        switch (usAddress)
        {
          case 0: // канал CH1 режим
          {	
            // команды для отправки на мотор
            switch (*(pucRegBuffer+1))
            {
              case 0:
              {	
								Out[0].Mode = On_Off;
                break;
              }
              case 1:
              {	
								Out[0].Mode = DIM;
                break;
              }
							default:
              {	
								Out[0].Mode = On_Off;
                break;
              }
            }
            break;
          }
          case 1: // канал CH1 процент димирования
          {	
						uint32_t dimTik = (uint32_t)map(*(pucRegBuffer+1), 0x00, 0x64, 9000, 0);
						__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, dimTik);
            break;
          }
					case 2: // канал CH2 режим
          {	
            // команды для отправки на мотор
            switch (*(pucRegBuffer+1))
            {
              case 0:
              {	
								Out[1].Mode = On_Off;
                break;
              }
              case 1:
              {	
								Out[1].Mode = DIM;
                break;
              }
							default:
              {	
								Out[1].Mode = On_Off;
                break;
              }
            }
            break;
          }
          case 3: // канал CH2 процент димирования
          {	
						uint32_t dimTik = (uint32_t)map(*(pucRegBuffer+1), 0x00, 0x64, 9000, 0);
						__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, dimTik);
            break;
          }
					case 4: // канал CH3 режим
          {	
            // команды для отправки на мотор
            switch (*(pucRegBuffer+1))
            {
              case 0:
              {	
								Out[2].Mode = On_Off;
                break;
              }
              case 1:
              {	
								Out[2].Mode = DIM;
                break;
              }
							default:
              {	
								Out[2].Mode = On_Off;
                break;
              }
            }
            break;
          }
          case 5: // канал CH3 процент димирования
          {	
						uint32_t dimTik = (uint32_t)map(*(pucRegBuffer+1), 0x00, 0x64, 9000, 0);
						__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, dimTik);
            break;
          }
					case 6: // канал CH4 режим
          {	
            // команды для отправки на мотор
            switch (*(pucRegBuffer+1))
            {
              case 0:
              {	
								Out[3].Mode = On_Off;
                break;
              }
              case 1:
              {	
								Out[3].Mode = DIM;
                break;
              }
							default:
              {	
								Out[3].Mode = On_Off;
                break;
              }
            }
            break;
          }
          case 7: // канал CH4 процент димирования
          {	
						uint32_t dimTik = (uint32_t)map(*(pucRegBuffer+1), 0x00, 0x64, 9000, 0);
						__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, dimTik);
            break;
          }
//          case 8: 
//          {	
//            break;
//          }
//          case 9: 
//          {	
//            break;
//          }
//          case 10: 
//          {	
//            break;
//          }
//          case 11: 
//          {	
//            break;
//          }
//          case 12: 
//          {	
//            break;
//          }
//          case 13: 
//          {	
//            break;
//          }
//          case 14: 
//          {	
//            break;
//          }
//          case 15: 
//          {	
//            break;
//          }
//          case 16: 
//          {	
//            break;
//          }

          default:
          {	
            eStatus = MB_ENOREG;
            break;
          }
        }

        break;
      }
      default:
      {	
        eStatus = MB_EINVAL;
        break;
      }
    }
    
    return eStatus;
}

// 0x01 0x0f 0x05
eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
    if(usAddress == 0 ){}
    else{usAddress--;} 

    return MB_ENOREG;
}
//0x02
eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    if(usAddress == 0 ){}
    else{usAddress--;} 

    return MB_ENOREG;
}  

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
