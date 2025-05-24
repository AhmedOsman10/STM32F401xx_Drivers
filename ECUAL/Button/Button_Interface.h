/*
 * Button_Interface.h
 *
 *  Created on: May 22, 2025
 *      Author: Ahmed
 */

#ifndef BUTTON_BUTTON_INTERFACE_H_
#define BUTTON_BUTTON_INTERFACE_H_

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"

/* Struct representing a push button configuration. */
typedef struct {
	GPIO_RegDef_t *port;        	// Pointer to the GPIO port connected to the push button
	uint8_t pinNumber;         	 	// GPIO pin number used for the push button
	GPIO_Pull_Up_Pull_Down_t pupd; 	// Pull-up or Pull-down configuration for the button pin
} Button_t;

/* Initializes the specified button. Configures the pin as input with the desired pull-up or pull-down setting. */
void Button_init(Button_t *btn);

/* Reads the current state of the button.Returns 1 if the button is pressed, 0 if not. */
uint8_t Button_turnOn(Button_t *btn);



#endif /* BUTTON_BUTTON_INTERFACE_H_ */
