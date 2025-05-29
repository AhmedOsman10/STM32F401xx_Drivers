
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
    // Initialize system clock
    RCC_init();
    // Initialize SysTick timer (used for delays)
    SYSTICK_init();

    // Enable peripheral clocks for GPIOA and GPIOD
    RCC_Peri_Enable(GPIOA_EN);
    RCC_Peri_Enable(GPIOD_EN);

    // Declare and configure SSD and Keypad structures
    SSD_t ssd;
    Keypad_t key;

    // Assign GPIO ports to SSD and Keypad
    ssd.port = GPIOA;
    key.port = GPIOD;

    // Map SSD pins to GPIOA pins 0 to 7
    for (uint8_t i = 0; i < 8; i++)
    {
        ssd.pinNumber[i] = i;
    }

    // Map Keypad pins to GPIOD pins 0 to 7
    for (uint8_t i = 0; i < 8; i++)
    {
        key.pinNumber[i] = i;
    }

    // Initialize the 7-segment display and keypad
    SSD_init(&ssd);
    Keypad_init(&key);

    // Variable to store the key value
    uint8_t key_val;

    // Infinite loop to continuously check keypad input
    while (1)
    {
        // Wait while no key is pressed (Pressed_Key returns 0)
        while ((key_val = Pressed_Key(&key)) != 0)
        {
            // Check if the pressed key is a digit ('0' to '9')
            if (key_val >= '0' && key_val <= '9')
            {
                // Display the numeric value on the 7-segment display
                SSD_DisplayNumber(&ssd, key_val - '0');
                // Turn off the display after showing the number
                SSD_Off_Displaying(&ssd);
            }
            else
            {
                // If the key is not a digit, blink the decimal point
                SSD_DecimalPointTurnOn(&ssd);
                SYSTICK_voidDelayMilliSec(1000);  // Wait for 1 second
                SSD_DecimalPointTurnOff(&ssd);
                SYSTICK_voidDelayMilliSec(1000);  // Wait for 1 second
            }
        }
    }
}
