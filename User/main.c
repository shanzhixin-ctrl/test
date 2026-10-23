

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"
#include "./BSP/TIM/tim.h"
#include "./BSP/UART/uart.h"
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef tim1;
extern uint8_t rx[1];
int main(void)
{
    HAL_Init();                                
    sys_stm32_clock_init(RCC_PLL_MUL9);         
    delay_init(72);                             
    led_init();                                 
    uart_init();
	   tim_init (rx[0]);
	uint16_t arr;
   while(1)
	 {
	 HAL_UART_Receive (&huart1,(uint8_t*)&arr,1,50);
		__HAL_TIM_SET_AUTORELOAD (&tim1,arr);
		 __HAL_TIM_SET_COUNTER (&tim1,0);
	 }
}

