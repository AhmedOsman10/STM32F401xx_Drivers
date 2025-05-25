/*
 * Keypad_Interface.h
 *
 *  Created on: May 25, 2025
 *      Author: Ahmed
 */

#ifndef KEPAD_KEYPAD_INTERFACE_H_
#define KEPAD_KEYPAD_INTERFACE_H_

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"

typedef struct{
	GPIO_RegDef_t *port;
	uint8_t pinNumber[8];
}Keypad_t;

void Keypad_init(Keypad_t *key);


#endif /* KEPAD_KEYPAD_INTERFACE_H_ */
