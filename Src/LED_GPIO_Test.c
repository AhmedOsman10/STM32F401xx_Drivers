
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"


int main(void)
{

	RCC_Peri_Enable(GPIOD_EN);
	GPIO_Mode(GPIOD, GPIO_PIN_14, GPIO_GENERAL_OPUTPUT_PURPOSE);
	GPIO_Output_Type(GPIOD, GPIO_PIN_14, GPIO_PUSH_PULL);
	GPIO_Speed(GPIOD, GPIO_PIN_14, GPIO_LOW_SPEED);
	GPIO_Pull_Up_Pull_Down(GPIOD, GPIO_PIN_14, GPIO_NO_PULL_UP_NO_PULL_DOWN);

	SYSTICK_voidInit();

    while (1)
    {
    	GPIO_Output_Data(GPIOD, GPIO_PIN_14, GPIO_SET);
    	SYSTICK_voidDelayMicroSec(5000000);

    	GPIO_Output_Data(GPIOD, GPIO_PIN_14, GPIO_RESET);
    	SYSTICK_voidDelayMicroSec(5000000);
    }
}


