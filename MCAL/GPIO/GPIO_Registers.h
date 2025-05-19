/*
 * Registers.h
 *
 *  Created on: May 6, 2025
 *      Author: Ahmed
 */

#ifndef GPIO_GPIO_REGISTERS_H_
#define GPIO_GPIO_REGISTERS_H_

#include <stdint.h>

#define AHB1PERIPH_BASEADDR					0x40020000U

/*
 * Base addresses of GPIOs peripherals which are hanging on AHB1 bus.
 * Please note that there are some other peripherials hanging on the same Bus, not only the GPIOs.
 */
#define GPIOA_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR						(AHB1PERIPH_BASEADDR + 0x2000)

typedef struct
{
	 uint32_t MODER;                 /* GPIO port mode register. 						Address offset: 0x00 */
	 uint32_t OTYPER;				 /* GPIO port output type register. 				Address offset: 0x04 */
	 uint32_t OSPEEDR;				 /* GPIO port output speed register. 				Address offset: 0x08 */
	 uint32_t PUPDR;				 /* GPIO port pull-up/pull-down register. 			Address offset: 0x0C */
	 uint32_t IDR;					 /* GPIO port input data register. 					Address offset: 0x10 */
	 uint32_t ODR;					 /* GPIO port output data register. 				Address offset: 0x14 */
	 uint32_t BSRR;					 /* GPIO port bit set/reset register. 				Address offset: 0x18 */
	 uint32_t LCKR;					 /* GPIO port configuration lock register. 			Address offset: 0x1C */
	 uint32_t AFRL;				 	 /* GPIO alternate function low register. 			Address offset: 0X20 */
	 uint32_t AFRH;					 /* GPIO alternate function high register.			Address offset: 0x24 */
}GPIO_RegDef_t;

#define GPIOA					(GPIO_RegDef_t*)(GPIOA_BASEADDR)
#define GPIOB					(GPIO_RegDef_t*)(GPIOB_BASEADDR)
#define GPIOC					(GPIO_RegDef_t*)(GPIOC_BASEADDR)
#define GPIOD					(GPIO_RegDef_t*)(GPIOD_BASEADDR)
#define GPIOE					(GPIO_RegDef_t*)(GPIOE_BASEADDR)
#define GPIOF					(GPIO_RegDef_t*)(GPIOF_BASEADDR)
#define GPIOG					(GPIO_RegDef_t*)(GPIOG_BASEADDR)
#define GPIOH					(GPIO_RegDef_t*)(GPIOH_BASEADDR)
#define GPIOI					(GPIO_RegDef_t*)(GPIOI_BASEADDR)


#endif /* GPIO_GPIO_REGISTERS_H_ */
