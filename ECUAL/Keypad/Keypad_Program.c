/*
 * Keypad_Program.c
 *
 *  Created on: May 25, 2025
 *      Author: Ahmed
 */

#include "../Keypad/Keypad_Interface.h"

static uint8_t Key_Number[16] = {'1', '4', '7', '*', '2', '5', '8', '0', '3', '6', '9', '#', 'A', 'B', 'C', 'D'};

void Keypad_init(Keypad_t *key)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		GPIO_Speed(key->port, key->pinNumber[i], GPIO_LOW_SPEED);
		if(i < 4)
		{
			GPIO_Mode(key->port, key->pinNumber[i], GPIO_INPUT);
			GPIO_Pull_Up_Pull_Down(key->port, key->pinNumber[i], GPIO_PULL_DOWN);
		}
		else
		{
			GPIO_Mode(key->port, key->pinNumber[i], GPIO_GENERAL_OUTPUT_PURPOSE);
			GPIO_Output_Type(key->port, key->pinNumber[i], GPIO_PUSH_PULL);
			GPIO_Pull_Up_Pull_Down(key->port, key->pinNumber[i], GPIO_NO_PULL_UP_NO_PULL_DOWN);
			GPIO_Output_Data(key->port, key->pinNumber[i], GPIO_RESET);
		}
	}
}

uint8_t Pressed_Key(Keypad_t *key)
{
	int Counter = 0;
	for(uint8_t column = 4; column < 8; column++)
	{
		GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_SET);
		for(uint8_t raw = 0; raw < 4; raw++)
		{
			if(GPIO_Input(key->port, key->pinNumber[raw]) == 1)
			{
				GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_RESET);
				return Key_Number[Counter];
			}
			else Counter++;
		}
		GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_RESET);
	}

	return 0;
}
