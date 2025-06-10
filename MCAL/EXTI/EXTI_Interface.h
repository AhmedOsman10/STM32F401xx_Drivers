/*
 * Interface_EXTI.h
 *
 *  Created on: May 30, 2025
 *      Author: Ahmed
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#include "EXTI_Registers.h"
#include "EXTI_Config.h"

#define	ENABLE		1
#define	DISABLE		0

void EXTI_enableInterruptHardware(uint8_t EXTI_line, uint8_t RTSR, uint8_t FTSR, void(*ptr)(void));
void EXTI_enableInterruptSoftware(uint8_t EXTI_line, void(*ptr)(void));
void EXTI_triggerInterruptSoftware(uint8_t EXTI_line);

void EXTI_enableEventHardware(uint8_t EXTI_line, uint8_t RTSR, uint8_t FTSR);
void EXTI_enableEventSoftware(uint8_t EXTI_line);

#endif /* EXTI_EXTI_INTERFACE_H_ */
