/*
 * SYSTICK_Program.c
 *
 *  Created on: Mar 3, 2025
 *      Author: Ahmed
 */

#include "SYSTICK_Interface.h"

void Enable_SYSTICK(void)
{
	#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
		SYSTICK->CTRL |= (1 << 2);
	#else
		SYSTICK->CTRL &= ~(1 << 2);
	#endif
}

void SYSTICK_voidDelayMilliSec(u32 ms)
{
	/* Reload value */
	/* We multipule the number of the given MicorSeconds by 16 since it takes 16 clock cylcse to complete one Microsecond. CLOCK_FREQUENCY = 16, which is the clock frequcny (16 MHz). */
	while(ms > 0)
	{
		if(ms > 1000)
		{
			SYSTICK->LOAD = (CLOCK_FREQUENCY * 1000000) - 1;
			ms -=1000;
		}
		else
		{
			SYSTICK->LOAD = (CLOCK_FREQUENCY * ms * 1000) - 1;
			ms = 0;
		}

		/* Enable Counter */
		SYSTICK->CTRL |= (1<<0);

		/* Wait until count flag is raised */
		while(!((SYSTICK->CTRL >> 16) & 1));

		/* Disable Counter */
		SYSTICK->CTRL &= ~(1<<0);
	}
}

void SYSTICK_voidDelayMicroSec(u32 us)
{
	/* Reload value */
	/* We multipule the number of the given MicorSeconds by 16 since it takes 16 clock cylcse to complete one Microsecond. CLOCK_FREQUENCY = 16, which is the clock frequcny (16 MHz). */
	while(us > 0)
	{
		if(us > 1000000)
		{
			SYSTICK->LOAD = (CLOCK_FREQUENCY * 1000000) - 1;
			us -=1000000;
		}
		else
		{
			SYSTICK->LOAD = (CLOCK_FREQUENCY * us) - 1;
			us = 0;
		}

		/* Enable Counter */
		SYSTICK->CTRL |= (1<<0);

		/* Wait until count flag is raised */
		while(!((SYSTICK->CTRL >> 16) & 1));

		/* Disable Counter */
		SYSTICK->CTRL &= ~(1 << 0);
	}
}

u32 SYSTICK_u32GetElapsedTime(void)
{
	return (SYSTICK->LOAD - SYSTICK->VAL);
}

u32 SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL;
}

/****** Interrupt Functions Implementation ******/

/* This function pointer (Call_Function) is used to point to a function  that will be executed in the SYSTICK handler (e.g., toggling an LED). */
void (*Call_Function)(void);

void SYSTICK_EnableInterrupt(void)
{
	SYSTICK->CTRL |= (1 << 1);
}

void SYSTICK_DisableInterrupt_and_Counter(void)
{
	SYSTICK->CTRL &= ~(1 << 1);
	SYSTICK->CTRL &= ~(1 << 0);
}

void SYSTICK_voidStartCountMilliSeconds(u32 ms, void(*ptr)(void))
{
	/* Assign the function pointer (Call_Function) to point to the function 'ptr', which we want to be executed when the interrupt occurs.
	 * Later, in the SYSTICK handler, we can call this function via Call_Function.
	 */
	Call_Function = ptr;
	/* Reload value */
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * 1000 * ms) - 1;
	/* Enable Counter */
	SYSTICK->CTRL |= (1 << 0);
}

void SYSTICK_voidStartCountMicroSeconds(u32 us, void(*ptr)(void))
{
	Call_Function = ptr;
	/* Reload value */
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * us) - 1;
	/* Enable counter */
	SYSTICK->CTRL |= (1 << 0);
}

void SysTick_Handler(void)
{
	Call_Function();
	#if SYSTICK_INTERPUT == SYSTICK_PERIODIC
		SYSTICK->CTRL &= ~(1 << 0);
	#endif
}


