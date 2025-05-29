
/*
    This C code is designed to read input from a 4x4 keypad and display digits (0–9) on a 7-segment display.

    🧠 Core Idea:
    - Initializes system clock and SysTick timer.
    - Enables GPIOA and GPIOD for SSD and Keypad respectively.
    - Configures a 7-segment display with pins connected to GPIOA (PA0–PA7).
    - Configures a 4x4 keypad with pins connected to GPIOD (PD0–PD7).
    - Continuously checks for key presses:
        - If a numeric key ('0' to '9') is pressed, the corresponding number is shown on the SSD.
        - If a non-numeric key is pressed, the SSD blinks its decimal point to indicate invalid input.
*/

// Include necessary header files for RCC, SSD, Button, and Keypad modules
#include "../MCAL/RCC/RCC_Interface.h"
#include "../ECUAL/SSD/SSD_Interface.h"
#include "../ECUAL/Button/Button_Interface.h"
#include "../ECUAL/Keypad/Keypad_Interface.h"

int main(void)
{
    /* Initialize System Clock
    RCC_init();

     Enable Peripheral Clocks

     Interrupt Configurations
    SCB_InterruptPriorityConfig();
    NVIC_SetPriority(IRQn, priority);

     Interrupt Enable
    NVIC_EnableIRQn(IRQn);

     Enable Peripheral Interrupt

    while(1)
    {

    }*/
}
