/*
 * SYSTICK_Program.c
 *
 *  Created on: Mar 3, 2025
 *      Author: Ahmed
 */

#include "SYSTICK_Interface.h"

void SYSTICK_voidInit(void)
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
	while(ms > 1000)
	{
		Extended_Delay(1000000);
		ms -= 1000;
	}
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * 1000 * ms) - 1;

	/* Enable counter */
	SYSTICK->CTRL |= (1<<0);

	/* Wait until count flag is raised */
	while(!((SYSTICK->CTRL>>16) & 1));

	/* Disable Counter */
	SYSTICK->CTRL &= ~(1<<0);
}

void SYSTICK_voidDelayMicroSec(u32 us)
{
	/* Reload value */
	while(us > 1000000)
	{
		Extended_Delay(1000000);
		us -= 1000000;
	}
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * us) - 1;   /* We multipule the number of the given MicorSeconds by 16 since it takes 16 clock cylcse
													to complete one Microsecond. CLOCK_FREQUENCY = 16, which is the clock frequcny (16 MHz). */
	/* Enable counter */
	SYSTICK->CTRL |= (1<<0);

	/* Wait until count flag is raised */
	while(!((SYSTICK->CTRL>>16) & 1));

	/* Disable Counter */
	SYSTICK->CTRL &= ~(1<<0);
}

void SYSTICK_voidEnableInterrupt(void)
{
	SYSTICK->CTRL |= (1 << 1);
}
void SYSTICK_voidStartCountMilliSeconds(u32 ms, void(*ptr)(void))
{

}
void SYSTICK_voidStartCountMicroSeconds(u32 us, void(*ptr)(void))
{
	/* Reload value */
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * us) - 1;

	/* Enable counter */
	SYSTICK->CTRL |= (1<<0);
}

/*void SysTick_Handler(void)
{
	SYSTICK_CallBack();
	#if SYSTICK_INTERPUT == SYSTICK_NON_PERIODIC
		SYSTICK->CTRL &= ~(1 << 0);
	#endif
}*/

u32 SYSTICK_u32GetElapsedTime(void)
{
	return (SYSTICK->LOAD - SYSTICK->VAL);
}

u32 SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL;
}

void Extended_Delay(u32 d)
{
	/* Reload value */
	SYSTICK->LOAD =  (CLOCK_FREQUENCY * d);

	/* Enable counter */
	SYSTICK->CTRL |= (1<<0);

	/* Wait until count flag is raised */
	while(!((SYSTICK->CTRL>>16) & 1));
}
