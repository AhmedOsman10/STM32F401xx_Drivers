/*
 * GPIO_Program.c
 *
 *  Created on: May 6, 2025
 *      Author: Ahmed
 */

#ifndef GPIO_GPIO_PROGRAM_C_
#define GPIO_GPIO_PROGRAM_C_

#include "GPIO_Interface.h"


void GPIO_Mode(GPIO_RegDef_t *GPIO ,GPIO_Pin_Number_t N, GPIO_Mode_t M)
{
	GPIO->MODER &= ~(0b11 << (2 * N));
	GPIO->MODER |= (M << (2 * N));
}


void GPIO_Output_Type(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Output_Type_t O)
{
	GPIO->OTYPER &= ~(0b1 << N);
	GPIO->OTYPER |= (O << N);
}

void GPIO_Speed(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N,GPIO_Speed_t S)
{
	GPIO->OSPEEDR &= ~(0b11 << (2 * N));
	GPIO->OSPEEDR |= (S << (2 * N));
}

void GPIO_Pull_Up_Pull_Down(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N,GPIO_Speed_t P)
{
	GPIO->PUPDR &= ~(0b11 << (2 * N));
	GPIO->PUPDR |= (P << (2 * N));
}

int GPIO_Input(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N)
{
	return ((GPIO->IDR >> N) & 0b1);
}

void GPIO_Output_Data(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Output_Data_t O)
{
	GPIO->ODR &= ~(0b1 << N);
	GPIO->ODR |= (O << N);
}

void GPIO_Alternate_Function(GPIO_RegDef_t *GPIO, GPIO_Pin_Number_t N, GPIO_Alternate_Function_t F)
{
	if(N < 8)
	{
		GPIO->AFRL &= ~(0b1111 << (4 * N));
		GPIO->AFRL |= (F << (4 * N));
	}
	else
	{
		GPIO->AFRH &= ~(0b1111 << (4 * (N - 8)));
		GPIO->AFRH |= (F << (4 * (N - 8)));
	}
}


#endif /* GPIO_GPIO_PROGRAM_C_ */
