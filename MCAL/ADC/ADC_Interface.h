/*
 * ADC_Interface.h
 *
 *  Created on: Jun 6, 2025
 *      Author: Ahmed
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

#include "ADC_Config.h"
#include "ADC_Registers.h"

#define ADC ADC1

void ADC1_init(uint8_t JSWSTART, uint8_t  SWSTART);


void ADC1_disable(void);

#endif /* ADC_ADC_INTERFACE_H_ */
