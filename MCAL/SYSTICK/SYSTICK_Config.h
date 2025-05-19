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

#define SYSTICK_CLOCK_SOURCE 	SYSTICK_AHB_DIV1


/*
 * Controls whether the reload counter stops or continues after reaching zero. Refer to the interrupt handler implementation for more details.
 * Note: The interrupt may still trigger if the clock is not disabled.
 */
#define SYSTICK_PERIODIC		0
#define SYSTICK_NON_PERIODIC	1

#define SYSTICK_INTERPUT		SYSTICK_NON_PERIODIC




#endif /* SYSTICK_SYSTICK_CONFIG_H_ */
