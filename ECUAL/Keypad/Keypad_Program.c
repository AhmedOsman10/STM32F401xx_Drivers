/*
 * Keypad_Program.c
 *
 *  Created on: May 25, 2025
 *      Author: Ahmed
 */

#include "../Keypad/Keypad_Interface.h"

static uint8_t Key_Number[16] = {'A', '3', '2', '1', 'B', '6', '5', '4', 'C', '9', '8', '7', 'D', '#', '0', '*'};

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
		}
	}
}

uint8_t Pressed_Key(Keypad_t *key)
{
	int Counter = 0;
	for(uint8_t column = 4; column < 8; column++)
	{
		GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_RESET);
		for(uint8_t raw = 0; raw < 4; raw++)
		{
			if(GPIO_Input(key->port, key->pinNumber[raw]) == 0)
			{
				GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_SET);
				return Key_Number[Counter];
			}
			else Counter++;
		}
		GPIO_Output_Data(key->port, key->pinNumber[column], GPIO_SET);
	}

	return 0;
}
