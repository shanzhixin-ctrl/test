
#include "./BSP/LED/led.h"
GPIO_InitTypeDef gpio1;
void led_init()
{
	__HAL_RCC_GPIOC_CLK_ENABLE();
	gpio1.Pin =GPIO_PIN_13;
	gpio1.Mode=GPIO_MODE_OUTPUT_OD ;
	gpio1.Speed =GPIO_SPEED_FREQ_HIGH;
	gpio1.Mode =GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC,&gpio1);
	HAL_GPIO_WritePin (GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
}
