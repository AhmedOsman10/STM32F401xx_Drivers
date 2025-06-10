/*
 * RCC_Registers.h
 *
 *  Created on: Feb 25, 2025
 *      Author: Ahmed
 */

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

#include <stdint.h>
#define RCC_BASEADDR				(0x40020000U + 0x3800)

typedef struct
{
	 uint32_t CR;					 /* RCC clock control register.						 Address offset: 0x00 */
	 uint32_t PLLCFGR; 				 /* RCC PLL configuration register. 			     Address offset: 0x04 */
	 uint32_t CFGR;					 /* RCC clock configuration register. 			     Address offset: 0x08 */
	 uint32_t CIR;					 /* RCC clock interrupt register. 			     	 Address offset: 0x0C */
	 uint32_t AHB1RSTR;              /* RCC AHB1 peripheral reset register. 			 Address offset: 0x10 */
	 uint32_t AHB2RSTR;				 /* RCC AHB2 peripheral reset register. 			 Address offset: 0x14 */
	 uint32_t AHB3RSTR;				 /* RCC AHB3 peripheral reset register. 			 Address offset: 0x18 */
	 uint32_t RESERVED;				 /* RESERVED. 										 Address offset: 0x1C */
	 uint32_t APB1RSTR;				 /* RCC APB1 peripheral reset register.				 Address offset: 0x20 */
	 uint32_t APB2RSTR;				 /* RCC APB2 peripheral reset register.				 Address offset: 0x24 */
	 uint32_t RESERVED1[2];			 /* RESERVED1							 			 Addresses offsets: 0x28 & 0x2C */
	 uint32_t AHB1ENR;				 /* RCC AHB1 peripheral clock enable register.		 Address offset: 0x30 */
	 uint32_t AHB2ENR; 				 /* RCC AHB2 peripheral clock enable register.		 Address offset: 0x34 */
	 uint32_t AHB3ENR;               /* RCC AHB3 peripheral clock enable register.		 Address offset: 0x38 */
	 uint32_t RESERVED2; 			 /* RESERVED2. 										 Address offset: 0x3C */
	 uint32_t APB1ENR; 				 /* RCC APB1 peripheral clock enable register.		 Address offset: 0x40 */
	 uint32_t APB2ENR; 				 /* RCC APB2 peripheral clock enable register.		 Address offset: 0x44 */
	 uint32_t RESERVED3[2];			 /* RESERVED3.							 			 Addresses offsets: 0x48 & 0x4C */
	 uint32_t AHB1LPENR;			 /* RCC AHB1 peripheral clock enable in low power mode register.		 Address offset: 0x50 */
	 uint32_t AHB2LPENR; 			 /* RCC AHB2 peripheral clock enable in low power mode register.		 Address offset: 0x54 */
	 uint32_t AHB3LPENR;             /* RCC AHB3 peripheral clock enable in low power mode register.		 Address offset: 0x58 */
	 uint32_t RESERVED4; 			 /* RESERVED4. 										 Address offset: 0x5C */
	 uint32_t APB1LPENR; 			 /* RCC APB1 peripheral clock enable in low power mode register.		 Address offset: 0x60 */
	 uint32_t APB2LPENR; 			 /* RCC APB2 peripheral clock enabled in low power mode register.		 Address offset: 0x64 */
	 uint32_t RESERVED5[2];			 /* RESERVED5.							 			 Addresses offsets: 0x68 & 0x6C */
	 uint32_t BDCR; 				 /* RCC Backup domain control register.		         Address offset: 0x70 */
	 uint32_t CSR; 					 /* RCC clock control & status register.		     Address offset: 0x74 */
	 uint32_t RESERVED6[2];			 /* RESERVED6.							 			 Addresses offsets: 0x78 & 0x7C */
	 uint32_t SSCGR;				 /* RCC spread spectrum clock generation register.   Address offset: 0x80 */
	 uint32_t PLLI2SCFGR;			 /* RCC PLLI2S configuration register.               Address offset: 0x84 */
}RCC_RegDef_t;


#define RCC	 						 ((RCC_RegDef_t*)RCC_BASEADDR)


#endif /* RCC_RCC_REGISTERS_H_ */
