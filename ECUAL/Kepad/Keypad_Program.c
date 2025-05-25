/*
 * Keypad_Program.c
 *
 *  Created on: May 25, 2025
 *      Author: Ahmed
 */

#include "Keypad_Interface.h"

void Keypad_init(Keypad_t *key)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		GPIO_Mode(key->port, key->pinNumber[i], GPIO_INPUT);
		GPIO_Speed(key->port, key->pinNumber[i], GPIO_LOW_SPEED);
		if(i < 4)
			GPIO_Pull_Up_Pull_Down(key->port, key->pinNumber[i], GPIO_PULL_UP);
		else
			GPIO_Pull_Up_Pull_Down(key->port, key->pinNumber[i], GPIO_PULL_DOWN);
	}
}
