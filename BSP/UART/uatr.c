#include "./BSP/UART/uart.h"
uint8_t rx[1];
UART_HandleTypeDef huart1;
void uart_init()
{

	huart1.Instance=USART1;
	huart1.Init.BaudRate=115200;
	huart1.Init.WordLength=UART_WORDLENGTH_8B;
	huart1.Init.StopBits=UART_STOPBITS_1; 
	huart1.Init.Parity=UART_PARITY_NONE;
	huart1.Init.Mode=UART_MODE_TX_RX;
	huart1.Init. HwFlowCtl=UART_HWCONTROL_NONE ;

	HAL_UART_Init(&huart1);

}
void HAL_UART_MspInit(UART_HandleTypeDef*huart)
{
if(huart->Instance==USART1)
{
__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin=GPIO_PIN_9;
	gpio_init.Mode=GPIO_MODE_AF_PP ;
	gpio_init.Speed=GPIO_SPEED_FREQ_LOW;
	
	HAL_GPIO_Init(GPIOA,&gpio_init);
	GPIO_InitTypeDef gpio_init1;
	gpio_init1.Mode=GPIO_MODE_AF_INPUT;
	gpio_init1.Pin=GPIO_PIN_10;
	gpio_init1.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA,&gpio_init1);


}

}	








