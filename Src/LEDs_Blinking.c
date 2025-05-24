
#include "../MCAL/RCC/RCC_Interface.h"
#include "../ECUAL/LED/LED_Interface.h"

int main(void)
{
	/* Clock COngiuration */
	RCC_init();
	SYSTICK_init();
	RCC_Peri_Enable(GPIOA_EN);
	RCC_Peri_Enable(GPIOB_EN);
	RCC_Peri_Enable(GPIOC_EN);

	/* Hardware Components */
	LED_t red = {GPIOA, 0};
	LED_t green = {GPIOB, 1};
	LED_t yellow = {GPIOC, 7};

	/* Hardware initialization */
	LED_init(&red);
	LED_init(&green);
	LED_init(&yellow);

	while(1)
	{
		LED_blink(&red, 1000);
		LED_blink(&green, 1000);
		LED_blink(&yellow, 1000);
	}
}


