/*
 * SSD_Interface.h
 *
 *  Created on: May 22, 2025
 *      Author: Ahmed
 */

#ifndef SSD_SSD_INTERFACE_H_
#define SSD_SSD_INTERFACE_H_

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"

typedef struct{
	GPIO_RegDef_t *port;
	uint8_t pinNumber[8];	/* {a, b, c, d, e, f, g, dp} */
}SSD_t;

void SSD_init(SSD_t *ssd);
void SSD_DisplayNumber(SSD_t *ssd, uint8_t number);
void SSD_DecimalPointTurnOn(SSD_t *ssd);
void SSD_DecimalPointTurnOff(SSD_t *ssd);


#endif /* SSD_SSD_INTERFACE_H_ */
