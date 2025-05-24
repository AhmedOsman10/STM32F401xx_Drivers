/*
    This C code is designed to display numbers from 0 to 9 on a 7-segment display connected to GPIOA.

    🧠 Core Idea:
    - Initializes the system clock and enables GPIOA.
    - Configures a 7-segment display where segments a through g are connected to GPIOA pins PA0 through PA6.
    - Uses the SysTick timer to introduce a 500-millisecond delay between number updates.
    - Continuously loops through numbers 0 to 9 and displays them on the 7-segment display.
*/

#include "../MCAL/RCC/RCC_Interface.h"     // Interface for system clock and peripheral clock control
#include "../ECUAL/SSD/SSD_Interface.h"    // Interface for controlling the 7-segment display

int main(void)
{
    RCC_init();                 // Initialize system clocks
    SYSTICK_init();             // Initialize SysTick timer for delay functionality
    RCC_Peri_Enable(GPIOA_EN);  // Enable clock for GPIOA peripheral

    // Configure the 7-segment display
    SSD_t ssd;
    ssd.port = GPIOA;           // Set GPIOA as the port for SSD segment control

    // Assign GPIOA pins PA0–PA6 to SSD segments a–g
    for (uint8_t i = 0; i < 7; i++)
    {
        ssd.pinNumber[i] = i;
    }

    SSD_init(&ssd);             // Initialize the SSD with the configured settings

    // Main loop: display numbers 0 through 9 continuously
    while (1)
    {
        for (uint8_t i = 0; i < 10; i++)
        {
            SSD_DisplayNumber(&ssd, i);         // Display current number on the SSD
            SYSTICK_voidDelayMilliSec(500);     // Wait for 500 milliseconds
        }
    }
}
