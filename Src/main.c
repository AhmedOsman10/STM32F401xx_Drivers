#include "../MCAL/RCC/RCC_Interface.h"
#include "../ECUAL/SSD/SSD_Interface.h"
#include "../ECUAL/Button/Button_Interface.h"

int main(void)
{
    RCC_init();
    SYSTICK_init();
    RCC_Peri_Enable(GPIOA_EN);

    Button_t btn = {GPIOA, 10, GPIO_PULL_UP};
    SSD_t ssd;
    ssd.port = GPIOA;

    for (uint8_t i = 0; i < 8; i++)
    {
        ssd.pinNumber[i] = i;
    }

    Button_init(&btn);
    SSD_init(&ssd);
    SSD_DecimalPointTurnOn(&ssd);

    while (1)
    {
    	if (Button_turnOn(&btn) == 0)
    	{
			for (uint8_t i = 0; i < 10; i++)
			{
				SSD_DisplayNumber(&ssd, i);
			}
    	}
    }
}
