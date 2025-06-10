/*
 * SYSCFG_Program.c
 *
 *  Created on: Jun 3, 2025
 *      Author: Ahmed
 */

#include "SYSCFG_Interface.h"

void SYSCFG_enableEXTILineX(SYSCFG_GPIO_Port_t port, uint8_t line)
{
	// Only valid EXTI lines are 0 to 15
	if(line > 15)
		return;
	// Clear old port selection bits for this EXTI line
	SYSCFG->EXTICR[line / 4] &= ~(0b1111 << (4 * (line % 4)));
	// Set new port bits for this EXTI line
	SYSCFG->EXTICR[line / 4] |= (port << (4 * (line % 4)));
}
