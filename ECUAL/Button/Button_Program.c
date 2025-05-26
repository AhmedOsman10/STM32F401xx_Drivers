/*
 * Button_Program.c
 *
 *  Created on: May 22, 2025
 *      Author: Ahmed
 */

#include "Button_Interface.h"

/*
 * Configures the pin as a GPIO input with the desired speed and pull-up/pull-down setting.
 * @param btn Pointer to a Button_t structure containing button configuration.
 */
void Button_init(Button_t *btn)
{
	GPIO_Mode(btn->port, btn->pinNumber, GPIO_INPUT);
	GPIO_Speed(btn->port, btn->pinNumber, GPIO_LOW_SPEED);
	GPIO_Pull_Up_Pull_Down(btn->port, btn->pinNumber, btn->pupd);
}

/*
 * Reads the GPIO pin, waits briefly, and reads again to ensure a stable value.
 * @param btn Pointer to a Button_t structure.
 * @return uint8_t 1 if the button is pressed, 0 if not.
 */
uint8_t Button_Read(Button_t *btn)
{
	return GPIO_Input(btn->port, btn->pinNumber);
}

uint8_t Button_Read_Debounce(Button_t *btn)
{
	uint8_t val1, val2;
	val1 = GPIO_Input(btn->port, btn->pinNumber);
	SYSTICK_voidDelayMicroSec(6);
	val2 = GPIO_Input(btn->port, btn->pinNumber);

	while(val1 != val2)
	{
		val1 = val2;
		SYSTICK_voidDelayMicroSec(6);
		val2 = GPIO_Input(btn->port, btn->pinNumber);
	}
	return val2;
}
