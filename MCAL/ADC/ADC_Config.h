/*
 * ADC_Config.h
 *
 *  Created on: Jun 6, 2025
 *      Author: Ahmed
 */

#ifndef ADC_ADC_CONFIG_H_
#define ADC_ADC_CONFIG_H_

/* ADC regular sequence register 1 (ADC_SQR1) */
/* ADC regular sequence length (L[3:0] in ADC_SQR1) */
/* These define the number of conversions in the regular group MINUS ONE */

#define ADC_REG_CONV_1				0b0000  // 1 conversion
#define ADC_REG_CONV_2				0b0001  // 2 conversions
#define ADC_REG_CONV_3				0b0010  // 3 conversions
#define ADC_REG_CONV_4				0b0011  // 4 conversions
#define ADC_REG_CONV_5				0b0100  // 5 conversions
#define ADC_REG_CONV_6				0b0101  // 6 conversions
#define ADC_REG_CONV_7				0b0110  // 7 conversions
#define ADC_REG_CONV_8				0b0111  // 8 conversions
#define ADC_REG_CONV_9				0b1000  // 9 conversions
#define ADC_REG_CONV_10				0b1001  // 10 conversions
#define ADC_REG_CONV_11				0b1010  // 11 conversions
#define ADC_REG_CONV_12				0b1011  // 12 conversions
#define ADC_REG_CONV_13				0b1100  // 13 conversions
#define ADC_REG_CONV_14				0b1101  // 14 conversions
#define ADC_REG_CONV_15				0b1110  // 15 conversions
#define ADC_REG_CONV_16				0b1111  // 16 conversions

#define ADC_REG_CONVERSION			ADC_REG_CONV_6


#endif /* ADC_ADC_CONFIG_H_ */
