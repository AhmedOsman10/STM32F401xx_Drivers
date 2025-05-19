/*
 * GPIO_Interface.h
 *
 *  Created on: May 6, 2025
 *      Author: Ahmed
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "GPIO_Registers.h"

typedef enum
{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_Pin_Number_t;

typedef enum
{
	GPIO_INPUT,
	GPIO_GENERAL_OUTPUT_PURPOSE,
	GPIO_ALTERNATE_FUNCTION,
	GPIO_ANALOG
}GPIO_Mode_t;

typedef enum
{
	GPIO_PUSH_PULL,
	GPIO_OPEN_DRAIN
}GPIO_Output_Type_t;

typedef enum
{
	GPIO_LOW_SPEED,
	GPIO_MEDUIM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VERY_HIGH_SPEED
}GPIO_Speed_t;

typedef enum
{
	GPIO_NO_PULL_UP_NO_PULL_DOWN,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
}GPIO_Pull_Up_Pull_Down_t;

typedef enum
{
	GPIO_RESET,
	GPIO_SET
}GPIO_Output_Data_t;

typedef enum
{
	GPIO_AF0,
	GPIO_AF1,
	GPIO_AF2,
	GPIO_AF3,
	GPIO_AF4,
	GPIO_AF5,
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15
}GPIO_Alternate_Function_t;

/* You can select the name of the desired GPIO port from the GPIO_Registers.h file */

void GPIO_Mode(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Mode_t M);
void GPIO_Output_Type(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Output_Type_t O);
void GPIO_Speed(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Speed_t S);
void GPIO_Pull_Up_Pull_Down(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Speed_t P);
int  GPIO_Input(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N);
void GPIO_Output_Data(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Output_Data_t O);
void GPIO_Alternate_Function(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Alternate_Function_t F);


#endif /* GPIO_GPIO_INTERFACE_H_ */
