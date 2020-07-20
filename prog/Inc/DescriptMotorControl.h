/*
  Описание команд для управления мотором
*/

#include "stm32f1xx_hal.h"

#define START 0x01
#define STOP  0x02
#define LEFT  0x03
#define RIGHT 0x04

//#define CW_RESET   HAL_GPIO_WritePin(CW1_GPIO_Port, CW1_Pin, GPIO_PIN_RESET);
                     //HAL_GPIO_WritePin(CW2_GPIO_Port, CW2_Pin, GPIO_PIN_RESET);
                     
#define CW_SET       HAL_GPIO_WritePin(START_GPIO_Port, START_Pin, GPIO_PIN_RESET);
                     //HAL_GPIO_WritePin(CW2_GPIO_Port, CW2_Pin, GPIO_PIN_SET);

//#define CCW_RESET   HAL_GPIO_WritePin(CCW1_GPIO_Port, CCW1_Pin, GPIO_PIN_RESET);
                    //HAL_GPIO_WritePin(CCW2_GPIO_Port, CCW2_Pin, GPIO_PIN_RESET);
                    
#define CCW_SET     HAL_GPIO_WritePin(START_GPIO_Port, START_Pin, GPIO_PIN_SET);
                    //HAL_GPIO_WritePin(CCW2_GPIO_Port, CCW2_Pin, GPIO_PIN_SET);
										

typedef enum 
{
	DIM = 3,
	On_Off = 4
}mode;

typedef enum 
{
  null_m = 0,
	On = 1,
	Off = 2
}move;

typedef struct 
{
  move Status;
  move CMD;
	mode Mode;
  uint32_t timeToOn;
	uint32_t time;
	//GPIO_TypeDef *Port;
	uint8_t Pin;
}motor_t;


