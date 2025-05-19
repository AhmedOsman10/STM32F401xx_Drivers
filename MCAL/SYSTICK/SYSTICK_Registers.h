/*
 * SYSTICK_Registers.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Ahmed
 */

#ifndef SYSTICK_SYSTICK_REGISTERS_H_
#define SYSTICK_SYSTICK_REGISTERS_H_

#define SYSTICK_BASE_ADDR 0xE000E010

typedef volatile struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}st_SYSTICK_RegDef_t;

#define SYSTICK		((st_SYSTICK_RegDef_t*) SYSTICK_BASE_ADDR)



#endif /* SYSTICK_SYSTICK_REGISTERS_H_ */
