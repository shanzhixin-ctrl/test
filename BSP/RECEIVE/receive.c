#include "receive.h"
#include <stdint.h>
#include <string.h>
uint8_t g_rx_buffer[1];

extern UART_HandleTypeDef  huart2;

float fr_speed;
float rl_speed;
float rr_speed;













uint8_t buf_speed_receive[12];
static uint8_t counter;


static void speed_feed(uint8_t byte)
{
static uint8_t speed_type=0;

switch (speed_type)
{
	case 0:
		if(byte==0x5A)
		{
			counter=0;
			speed_type=1;
		}
		break;
	case 1:
		
	buf_speed_receive [counter++]=byte;
	if(counter==sizeof(buf_speed_receive ))
	{
	speed_type =2;
	}
	break;
	case 2:
	
	    counter = 0;
    speed_type = 0;
	
		if(byte==0x5A)
		{

			speed_type =1;
		}
	else if(byte==0xFF){
	float speeds[3];
		  
                memcpy(speeds, buf_speed_receive , sizeof(speeds));

                fr_speed = speeds[0];
                rl_speed = speeds[1];
                rr_speed = speeds[2];
	}
	
		
	break;
	
		



}




}








static uint8_t byte_2;




void uart_receive_start()
{
HAL_UART_Receive_IT (&huart2 , &byte_2,1);
 
}


extern UART_HandleTypeDef huart1;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

if(huart->Instance ==USART1 )
{

bt_feed(g_rx_buffer[0]);     

        HAL_UART_Receive_IT(&huart1 , g_rx_buffer, 1);


}



else if(huart->Instance==USART2 )
{

uint8_t byte=byte_2;
	HAL_UART_Receive_IT (&huart2 ,&byte_2 ,1);
	speed_feed(byte);
	
	}
}





void bt_start(void)
{
    HAL_UART_Receive_IT(&huart1, g_rx_buffer, 1);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

if(htim->Instance ==TIM1)
{
wheel_update();
	 wheel_update_fr();
	 wheel_update_rl();	
	wheel_update_rr();	

}


}






















