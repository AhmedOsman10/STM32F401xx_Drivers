/*
 * SYSTICK_Config.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Ahmed
 */

#ifndef SYSTICK_SYSTICK_CONFIG_H_
#define SYSTICK_SYSTICK_CONFIG_H_


#define CLOCK_FREQUENCY		16 		// 16 MHZ

/* Clock Source */
#define SYSTICK_AHB_DIV1	0
#define SYSTICK_AHB_DIV8	1

#define SYSTICK_CLOCK_SOURCE 	SYSTICK_AHB_DIV8




#define SYSTICK_PERIODIC		0
#define SYSTICK_NON_PERIODIC	1

#define SYSTICK_INTERPUT	SYSTICK_PERIODIC




#endif /* SYSTICK_SYSTICK_CONFIG_H_ */
