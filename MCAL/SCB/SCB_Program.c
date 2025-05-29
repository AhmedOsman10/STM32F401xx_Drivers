/*
 * SCB_Program.c
 *
 *  Created on: May 29, 2025
 *      Author: Ahmed
 */

#include "SCB_Interface.h"

void SCB_InterruptPriorityConfig(void)
{
	*SCB_AIRCR &= ~(0b111 << 8);
	*SCB_AIRCR |= (Group_Priority << 8);
}
