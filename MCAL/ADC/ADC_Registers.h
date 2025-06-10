/*
 * ADC.Registers.h
 *
 *  Created on: Jun 6, 2025
 *      Author: Ahmed
 */

#ifndef ADC_ADC_REGISTERS_H_
#define ADC_ADC_REGISTERS_H_

#include <stdint.h>
#define ADC_BASEADDR		0x40012000U

typedef struct
{
	uint32_t SR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMPR1;
	uint32_t JOFR[4];
	uint32_t HTR;
	uint32_t LTR;
	uint32_t SQR1;
	uint32_t SQR2;
	uint32_t SQR3;
	uint32_t SQR;
	uint32_t JDR[4];
	uint32_t DR;
	uint32_t CSR;
	uint32_t CDR;
}ADC_RegDef_t;

#define ADC1 				((ADC_RegDef_t*)(ADC_BASEADDR + 0x000))
#define ADC2 				((ADC_RegDef_t*)(ADC_BASEADDR + 0x100))
#define ADC3 				((ADC_RegDef_t*)(ADC_BASEADDR + 0x200))


#endif /* ADC_ADC_REGISTERS_H_ */
