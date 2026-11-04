#include "./BSP/UART/uart.h"

void gpio_init()
	{
__HAL_RCC_GPIOC_CLK_ENABLE();
		GPIO_InitTypeDef gpio;
		gpio.Mode =GPIO_MODE_OUTPUT_OD ;
		gpio.Pin =GPIO_PIN_13;
gpio.Speed =GPIO_SPEED_FREQ_HIGH ;
		HAL_GPIO_Init(GPIOC,&gpio);
}
