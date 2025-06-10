/*
 * Registers_EXTI.h
 *
 *  Created on: May 30, 2025
 *      Author: Ahmed
 */

#ifndef EXTI_EXTI_REGISTERS_H_
#define EXTI_EXTI_REGISTERS_H_

#include <stdint.h>
#define EXTI_BASEADDR		0x40013C00U

typedef struct
{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
}EXTI_RegDef_t;

#define EXTI			   ((EXTI_RegDef_t*)(EXTI_BASEADDR))


#endif /* EXTI_EXTI_REGISTERS_H_ */
