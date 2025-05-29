/*
 * NVIC_Program.c
 *
 *  Created on: May 28, 2025
 *      Author: Ahmed
 *
 *  Description:
 *      This file implements basic NVIC (Nested Vectored Interrupt Controller) operations
 *      for enabling, disabling, setting, and clearing interrupt requests (IRQs).
 */

#include "NVIC_Interface.h"

/*
 * @brief  Enables a specific interrupt line.
 * @param  IRQn: Interrupt Request number (0 to 239).
 *
 * The NVIC has 8 ISER registers, each 32 bits.
 * This calculates the register index using IRQn / 32, and sets the corresponding bit using (IRQn - 32 * (IRQn / 32)).
 */
void NVIC_EnableIRQn(NVIC_IRQn_t IRQn)
{
	// Enable the IRQ by setting the corresponding bit in the ISER register.
	// - IRQn / 32: selects the ISER register index (each ISER handles 32 IRQs)
	// - (IRQn - 32 * (IRQn / 32)): calculates the bit position within that ISER (equivalent to IRQn % 32)
	NVIC->ISER[IRQn / 32] |= (1 << (IRQn - (32 * (IRQn / 32))));

}

/*
 * @brief  Disables a specific interrupt line.
 * @param  IRQn: Interrupt Request number (0 to 239).
 *
 * Similar to enabling, this accesses the ICER register array and clears the corresponding IRQ bit.
 */
void NVIC_DisableIRQn(NVIC_IRQn_t IRQn)
{
	NVIC->ICER[IRQn / 32] |= (1 << (IRQn - (32 * (IRQn / 32))));
}

/*
 * @brief  Sets the pending flag for a given IRQ.
 * @param  IRQn: Interrupt Request number (0 to 239).
 *
 * This sets the interrupt as pending by writing to the ISPR register.
 */
void NVIC_SetPending(NVIC_IRQn_t IRQn)
{
	NVIC->ISPR[IRQn / 32] |= (1 << (IRQn - (32 * (IRQn / 32))));
}

/*
 * @brief  Clears the pending flag for a given IRQ.
 * @param  IRQn: Interrupt Request number (0 to 239).
 *
 * This clears the interrupt pending flag using the ICPR register.
 */
void NVIC_ClearPending(NVIC_IRQn_t IRQn)
{
	NVIC->ICPR[IRQn / 32] |= (1 << (IRQn - (32 * (IRQn / 32))));
}

/*
 * @brief Sets priority for a specific IRQ.
 * @param IRQn: Interrupt number (0–239).
 * @param priority: 8-bit value (only upper 4 bits used in STM32F4).
 *
 * Each IRQ has an 8-bit priority field; the value is left-shifted by 4 as only bits [7:4] are used. Bits [3:0] are reserved and not used.
 */
void NVIC_SetPriority(NVIC_IRQn_t IRQn, uint8_t priority)
{
	NVIC->IPR[IRQn] = (priority << 4);
}


