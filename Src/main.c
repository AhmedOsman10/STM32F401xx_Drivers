#include "../MCAL/RCC/RCC_Interface.h"
#include "../ECUAL/SSD/SSD_Interface.h"
#include "../ECUAL/Button/Button_Interface.h"
#include "../ECUAL/Keypad/Keypad_Interface.h"

int main(void)
{
    RCC_init();
    SYSTICK_init();
    RCC_Peri_Enable(GPIOA_EN);
    RCC_Peri_Enable(GPIOD_EN);

    SSD_t ssd;
    Keypad_t key;
    ssd.port = GPIOA;
    key.port = GPIOD;

    for (uint8_t i = 0; i < 8; i++)
    {
        ssd.pinNumber[i] = i;
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        key.pinNumber[i] = i;
    }

    SSD_init(&ssd);
    Keypad_init(&key);
    SSD_DecimalPointTurnOn(&ssd);
    uint8_t key_val;

	for (uint8_t i = 0; i < 10; i++)
	{
		SSD_DisplayNumber(&ssd, i);
	}
	SSD_Off_Displaying(&ssd);

    while (1)
    {
    	key_val = Pressed_Key(&key);
		// Only display digits '0' to '9'
		if (key_val >= '0' && key_val <= '9')
		{
		   SSD_DisplayNumber(&ssd, key_val - '0');
		}
		else
		{
			SSD_DecimalPointTurnOn(&ssd);
			SYSTICK_voidDelayMilliSec(1000);
			SSD_DecimalPointTurnOff(&ssd);
			SYSTICK_voidDelayMilliSec(1000);
		}
    }
}
