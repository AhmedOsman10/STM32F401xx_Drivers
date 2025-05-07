/*
 * RCC_Config.h
 *
 *  Created on: Feb 25, 2025
 *      Author: Ahmed
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_


/* Choose System Clock */
#define RCC_HSI	0b00
#define RCC_HSE	0b01
#define RCC_PLL	0b10

#define RCC_SYSTEM_CLOCK	RCC_HSI


/* Choose HSE Type */
#define RCC_HSE_NOT_BYPASSED	 0        // Oscillator (Crystal - Resenator)
#define RCC_HSE_BYPASSED	     1		  // External Clock

#define RCC_HSE_TYPE   RCC_HSE_NOT_ BYPASS


/* Choose Clock Security System */


/* Choose AHB prescaler */
#define RCC_AHB_PRESCALER1			0b0000
#define RCC_AHB_PRESCALER2			0b1000
#define RCC_AHB_PRESCALER4			0b1001
#define RCC_AHB_PRESCALER8			0b1010
#define RCC_AHB_PRESCALER16			0b1011
#define RCC_AHB_PRESCALER64			0b1100
#define RCC_AHB_PRESCALER128		0b1101
#define RCC_AHB_PRESCALER256		0b1110
#define RCC_AHB_PRESCALER512		0b1111

#define RCC_AHB_PRESCALER   		RCC_AHB_PRESCALER1


/* Choose APB1 prescaler */
#define RCC_APB1_PRESCALER1			0b000
#define RCC_APB1_PRESCALER2			0b100
#define RCC_APB1_PRESCALER4			0b101
#define RCC_APB1_PRESCALER8			0b110
#define RCC_APB1_PRESCALER16		0b111

#define RCC_APB1_PRESCALER 	        RCC_APB1_PRESCALER1


/* Choose APB2 prescaler */
#define RCC_APB2_PRESCALER1			0b000
#define RCC_APB2_PRESCALER2			0b100
#define RCC_APB2_PRESCALER4			0b101
#define RCC_APB2_PRESCALER8			0b110
#define RCC_APB2_PRESCALER16		0b111

#define RCC_APB2_PRESCALER			RCC_APB2_PRESCALER1


/* MCO1 External_Clock */
#define MCO1_HSI					0b00
#define MCO1_LSE					0b01
#define MCO1_HSE					0b10
#define MCO1_PLL					0b11

#define EXTERNAL_CLOCK_MCO1			MCO1_HSI

/* MCO2 External_Clock */
#define MCO2_HSI					0b00
#define MCO2_LSE					0b01
#define MCO2_HSE					0b10
#define MCO2_PLL					0b11

#define EXTERNAL_CLOCK_MCO2			MCO2_HSI


/* Choose MCO1 prescaler */
#define MCO1_PRESCALER1				0b000
#define MCO1_PRESCALER2				0b100
#define	MCO1_PRESCALER3				0b101
#define MCO1_PRESCALER4				0b110
#define MCO1_PRESCALER5				0b111

#define MCO1_PRESCALER				MCO1_PRESCALER1


/* Choose MCO2 prescaler */
#define MCO2_PRESCALER1				0b000
#define MCO2_PRESCALER2				0b100
#define	MCO2_PRESCALER3				0b101
#define MCO2_PRESCALER4				0b110
#define MCO2_PRESCALER5				0b111

#define MCO2_PRESCALER				MCO2_PRESCALER1






#endif /* RCC_RCC_CONFIG_H_ */
