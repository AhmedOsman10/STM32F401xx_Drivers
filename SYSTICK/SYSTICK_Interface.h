/*
 * SYSTICK_Interface.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Ahmed
 */

#ifndef SYSTICK_SYSTICK_INTERFACE_H_
#define SYSTICK_SYSTICK_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "SYSTICK_Registers.h"
#include "SYSTICK_Config.h"

void SYSTICK_voidInit(void);

void SYSTICK_voidDelayMilliSec(u32 ms);
/* This function can only take up to 1000,000 us ( 1 second). The register size is 24 bites. 16 clock cycle is needed for 1 us if the cloc surce is 16 MHz*/
void SYSTICK_voidDelayMicroSec(u32 us);
void Extended_Delay(u32 d);

u32 SYSTICK_u32GetElapsedTime(void);
u32 SYSTICK_u32GetRemainingTime(void);

void SYSTICK_voidEnableInterrupt(void);
void SYSTICK_voidStartCountMilliSeconds(u32 ms, void(*ptr)(void));
void SYSTICK_voidStartCountMicroSeconds(u32 us, void(*ptr)(void));

void SYSTICK_voidSetCallBackFunction( void(*ptr)(void) );

#endif /* SYSTICK_SYSTICK_INTERFACE_H_ */
