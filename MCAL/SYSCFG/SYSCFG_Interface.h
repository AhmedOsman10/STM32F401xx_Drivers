/*
 * SYSCFG_Interface.h
 *
 *  Created on: Jun 3, 2025
 *      Author: Ahmed
 */

#ifndef SYSCFG_SYSCFG_INTERFACE_H_
#define SYSCFG_SYSCFG_INTERFACE_H_

#include "SYSCFG_Registers.h"
#include "SYSCFG_Config.h"

/*
 * @brief Enum to represent GPIO ports used for EXTI configuration.
 * Each value corresponds to the binary encoding required by the SYSCFG EXTICR registers when selecting a GPIO port as the EXTI source.
 */
typedef enum {
    SYSCFG_GPIOA = 0b0000,
    SYSCFG_GPIOB = 0b0001,
    SYSCFG_GPIOC = 0b0010,
    SYSCFG_GPIOD = 0b0011,
    SYSCFG_GPIOE = 0b0100,
    SYSCFG_GPIOF = 0b0101,
    SYSCFG_GPIOG = 0b0110,
    SYSCFG_GPIOH = 0b0111,
    SYSCFG_GPIOI = 0b1000
} SYSCFG_GPIO_Port_t;

/*
 * @brief Configure the external interrupt (EXTI) line to use a specific GPIO port.
 * This function updates the SYSCFG EXTICR registers to link the EXTI line with the selected GPIO port.
 * @param port The GPIO port to be mapped to the EXTI line (use SYSCFG_GPIOx enum)
 * @param line The EXTI line number (0–15)
 */
void SYSCFG_enableEXTILineX(SYSCFG_GPIO_Port_t port, uint8_t line);

#endif /* SYSCFG_SYSCFG_INTERFACE_H_ */
