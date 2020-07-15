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

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
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
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  __disable_irq ();
  
  
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
          case 0:
          {	
            // команды для отправки на мотор
            switch (*(pucRegBuffer+1))
            {
              case 0:
              {	

                break;
              }
              case 1:
              {	

                break;
              }
              case 2:
              {	

                break;
              }
              case 3:
              {	

                break;
              }
              default:
              {	

                break;
              }
            }
            break;
          }
          case 1:
          {	
            break;
          }
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
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
