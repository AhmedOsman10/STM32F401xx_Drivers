/*
 * ADC_Program.c
 *
 *  Created on: Jun 6, 2025
 *      Author: Ahmed
 */


#include "ADC_Interface.h"

void ADC1_init(uint8_t JSWSTART, uint8_t  SWSTART)
{
	/* Set or enable ADON */
	ADC->CR2 |= (1 << 0);
	/* Configure JSWSTART */
	ADC->CR2 |= (JSWSTART << 22);
	/* Configure SWSTART */
	ADC->CR2 |= (SWSTART << 30);

	/* Enable RCC of ADC1EN = 78, ADC2EN, ADC3EN, */

	/* Channel selection, configuration of the regular and injected? */
	ADC->SQR1 &= ~(0b1111 << 20);
	ADC->SQR1 |= (ADC_REG_CONVERSION << 20);  // For 5 conversions

}

