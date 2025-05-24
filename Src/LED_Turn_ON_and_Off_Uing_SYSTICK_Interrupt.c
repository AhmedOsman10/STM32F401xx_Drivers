/*
  	This C code is designed to blink an LED connected to pin PD14 of the microcontroller using the SysTick timer and interrupts.
  	Here's a concise explanation of the core idea and how it works:

	🧠 Core Idea:
	The program initializes GPIO pin PD14 as a digital output (for the LED).
	It sets up the SysTick timer to generate an interrupt every 1000 milliseconds (1 second).
	Each time the SysTick interrupt fires, it calls the toggle() function, which toggles the LED state (Disable the SYSTICK Interrupt and Counter).
 */

#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

int counter = 0;

void func(void)
{
	/* Trun on the LED */
	if(counter == 0)
	{
		GPIO_Output_Data(GPIOD, GPIO_PIN_14, GPIO_SET);
		counter++;
	}
	/* Trun off the LED */
	else if(counter == 1)
	{
		GPIO_Output_Data(GPIOD, GPIO_PIN_14, GPIO_RESET);
		counter++;
	}
	/* Disable the SYSTICK Interrupt and Counter */
	else if(counter == 2)
	{
		SYSTICK_DisableInterrupt_and_Counter();
	}
}

int main(void)
{
	/* Configure and enable the GPIO peripheral and pin */
	RCC_Peri_Enable(GPIOD_EN);
	GPIO_Mode(GPIOD, GPIO_PIN_14, GPIO_GENERAL_OUTPUT_PURPOSE);
	GPIO_Output_Type(GPIOD, GPIO_PIN_14, GPIO_PUSH_PULL);
	GPIO_Speed(GPIOD, GPIO_PIN_14, GPIO_LOW_SPEED);
	GPIO_Pull_Up_Pull_Down(GPIOD, GPIO_PIN_14, GPIO_NO_PULL_UP_NO_PULL_DOWN);

	/* Configure and enable the SYSTICK Clock and its Interrupt */
	Enable_SYSTICK();
	SYSTICK_EnableInterrupt();
	SYSTICK_voidStartCountMilliSeconds(1000, func);

	while(1);
}

