/*
 * SSD_Program.c
 *
 *  Created on: May 22, 2025
 *      Author: Ahmed
 */

#include "SSD_Interface.h"

void SSD_init(SSD_t *ssd)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		GPIO_Mode(ssd->port, ssd->pinNumber[i], GPIO_GENERAL_OUTPUT_PURPOSE);
		GPIO_Output_Type(ssd->port, ssd->pinNumber[i], GPIO_PUSH_PULL);
		GPIO_Speed(ssd->port, ssd->pinNumber[i], GPIO_LOW_SPEED);
		GPIO_Pull_Up_Pull_Down(ssd->port, ssd->pinNumber[i], GPIO_NO_PULL_UP_NO_PULL_DOWN);
	}
}

void SSD_DisplayNumber(SSD_t *ssd, uint8_t number)
{
	static uint8_t numbers[10] = {0b00111111, 0b00000110, 0b01011011,  0b01001111,  0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	for(uint8_t i = 0; i < 7; i++)
	{
		GPIO_Output_Data(ssd->port, ssd->pinNumber[i], (numbers[number] >> i) & 1);
	}
	SYSTICK_voidDelayMilliSec(500);
	for(uint8_t i = 0; i < 7; i++)
	{
		GPIO_Output_Data(ssd->port, ssd->pinNumber[i], GPIO_RESET);
	}
}

void SSD_DecimalPointTurnOn(SSD_t *ssd)
{
	GPIO_Output_Data(ssd->port, ssd->pinNumber[7], GPIO_SET);
}

void SSD_DecimalPointTurnOff(SSD_t *ssd)
{
	GPIO_Output_Data(ssd->port, ssd->pinNumber[7], GPIO_RESET);
}

