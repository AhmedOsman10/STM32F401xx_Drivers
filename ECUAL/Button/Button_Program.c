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
uint8_t Button_turnOn(Button_t *btn)
{
	// Basic debounce: delay before reading input
	SYSTICK_voidDelayMicroSec(1000); // ~1ms delay
	return GPIO_Input(btn->port, btn->pinNumber);
}
