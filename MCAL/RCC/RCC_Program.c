/*
 * RCC_Program.c
 *
 *  Created on: Feb 25, 2025
 *      Author: Ahmed
 */


#include "RCC_Interface.h"

void RCC_init(void)
{
	/* Cofigure the Prescalers and External Clocks for MCO1 and MCO2 */
	RCC_External_Clock_MCO1();
	RCC_External_Clock_MCO2();

	/* Choose System Clock */
	#if(RCC_SYSTEM_CLOCK == RCC_HSI)
		// Enable HSI
		RCC->CR |= (1 << 0);
		//wait HSI To be ready
		while(! ((RCC->CR >> 1) & 1) );
	#elif(RCC_SYSTEM_CLOCK == RCC_HSE)
		#if(RCC_HSE_TYPE == RCC_HSE_NOT_BYPASSED)
			RCC->CR &= ~(1 << 18);
		#elif(RCC_HSE_TYPE == RCC_HSE_BYPASSED)
			RCC->CR |= (1 << 18);
		#endif
		// Enable HSE
		RCC->CR |= (1 << 16);
		//wait HSE To be ready
		while(! ((RCC->CR >> 17) & 1) );
	#elif(RCC_SYSTEM_CLOCK == RCC_PLL)
		/* PLL Configuration */

		// Enable PLL
		RCC->CR |= (1 << 24);
		//wait PLL To be ready
		while(! ((RCC->CR >> 25) & 1) );
	#endif

	/* Choose Clock as System  Clock */
	RCC->CFGR &= ~(0b11 << 0); // clear those 2 bits
	RCC->CFGR |= (RCC_SYSTEM_CLOCK << 0); // set those 2 bits
	// Wait until the clock is chosen
	while(! (((RCC->CFGR >> 2) & 0b11) == RCC_SYSTEM_CLOCK));


	/* Clock Security System */

	/* Bus prescalers */
	// Configure AHB Bus
	RCC->CFGR &= ~(0b1111 << 4); // Clear the bits first
	RCC->CFGR |=  (RCC_AHB_PRESCALER << 4); // Set the the Prescaler value
	// Configure APB1 Bus
	RCC->CFGR &= ~(0b111 << 10);
	RCC->CFGR |=  (RCC_APB1_PRESCALER << 10);
	// Configure APB2 Bus //
	RCC->CFGR &= ~(0b111 << 13);
	RCC->CFGR |=  (RCC_APB2_PRESCALER << 13);

	/* Enable MCO1 and MCO2 Clocks */
	#if(External_Clock_MCO1 != RCC_SYSTEM_CLOCK)
		#if(External_Clock_MCO1 == RCC_HSI)
			// Enable HSI
			RCC->CR |= (1 << 0);
			//wait HSI To be ready
			while(! ((RCC->CR >> 1) & 1) );
		#elif(External_Clock_MCO1 == RCC_HSE)
			#if(RCC_HSE_TYPE == RCC_HSE_NOT_BYPASSED)
				RCC->CR &= ~(1 << 18);
			#elif(RCC_HSE_TYPE == RCC_HSE_BYPASSED)
				RCC->CR |= (1 << 18);
			#endif
			// Enable HSE
			RCC->CR |= (1 << 16);
			//wait HSE To be ready
			while(! ((RCC->CR >> 17) & 1) );
		#elif(External_Clock_MCO1 == RCC_PLL)
			/* PLL Configuration */

			// Enable PLL
			RCC->CR |= (1 << 24);
			//wait PLL To be ready
			while(! ((RCC->CR >> 25) & 1) );
		#endif
	#endif

	#if(External_Clock_MCO2 != RCC_SYSTEM_CLOCK)
		#if(External_Clock_MCO2 == RCC_HSI)
			// Enable HSI
			RCC->CR |= (1 << 0);
			//wait HSI To be ready
			while(! ((RCC->CR >> 1) & 1) );
		#elif(External_Clock_MCO2 == RCC_HSE)
			#if(RCC_HSE_TYPE == RCC_HSE_NOT_BYPASSED)
				RCC->CR &= ~(1 << 18);
			#elif(RCC_HSE_TYPE == RCC_HSE_BYPASSED)
				RCC->CR |= (1 << 18);
			#endif
			// Enable HSE
			RCC->CR |= (1 << 16);
			//wait HSE To be ready
			while(! ((RCC->CR >> 17) & 1) );
		#elif(External_Clock_MCO2 == RCC_PLL)
			/* PLL Configuration */

			// Enable PLL
			RCC->CR |= (1 << 24);
			//wait PLL To be ready
			while(! ((RCC->CR >> 25) & 1) );
		#endif
	#endif
}

void RCC_Peri_Enable(RCC_Preipherals P)
{
	if(P < 31)
		RCC->AHB1ENR |= (1 << P);
	else if(P < 39)
		RCC->AHB2ENR |= (1 << (P - 31));
	else if(P == 39)
		RCC->AHB3ENR |= (1 << (P - 39));
	else if(P < 70)
		RCC->APB1ENR |= (1 << (P - 40));
	else if(P < 79)
		RCC->APB2ENR |= (1 << (P - 70));
	else if(P < 118)
		RCC->AHB1LPENR |= (1 << (P - 89));
	else if(P < 126)
		RCC->AHB2LPENR |= (1 << (P - 118));
	else if(P == 126)
		RCC->AHB3LPENR |= (1 << (P - 126));
	else if(P <= 166)
		RCC->APB1LPENR |= (1 << (P - 127));
	else if(P <= 175)
		RCC->APB2LPENR |= (1 << (P - 146));
}

void RCC_Peri_Disable(RCC_Preipherals P)
{
	if(P < 31)
		RCC->AHB1ENR &= ~(1 << P);
	else if(P < 39)
		RCC->AHB2ENR &= ~(1 << (P - 31));
	else if(P == 39)
		RCC->AHB3ENR &= ~(1 << (P - 39));
	else if(P < 70)
		RCC->APB1ENR &= ~(1 << (P - 40));
	else if(P < 79)
		RCC->APB2ENR &= ~(1 << (P - 70));
	else if(P < 118)
		RCC->AHB1LPENR &= ~(1 << (P - 89));
	else if(P < 126)
		RCC->AHB2LPENR &= ~(1 << (P - 118));
	else if(P == 126)
		RCC->AHB3LPENR &= ~(1 << (P - 126));
	else if(P <= 166)
		RCC->APB1LPENR &= ~(1 << (P - 127));
	else if(P <= 175)
		RCC->APB2LPENR &= ~(1 << (P - 146));
}

void RCC_External_Clock_MCO1(void)
{
	/* Configure MCO1 prescaler */
	RCC->CFGR &= ~(0b111 << 24);
	RCC->CFGR |= (MCO1_PRESCALER << 24);
	/* Choose MCO1 clock */
	RCC->CFGR &= ~(0b11 << 21);
	RCC->CFGR |= (EXTERNAL_CLOCK_MCO1 << 21);
}

void RCC_External_Clock_MCO2(void)
{
	/* Configure MCO2 prescaler */
	RCC->CFGR &= ~(0b111 << 27);
	RCC->CFGR |= (MCO2_PRESCALER << 27);
	/* Choose MCO2 clock */
	RCC->CFGR &= ~(0b11 << 30);
	RCC->CFGR |= (EXTERNAL_CLOCK_MCO2 << 30);
}
