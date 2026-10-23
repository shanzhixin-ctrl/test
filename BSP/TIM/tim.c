#include "./BSP/TIM/tim.h"

TIM_HandleTypeDef tim1;
void tim_init(uint16_t arr)
{
	tim1.Instance=TIM2;
	
tim1.Init.Prescaler =	36000;
	tim1.Init.CounterMode=TIM_COUNTERMODE_UP;                 ;
	tim1.Init.Period =arr;
	
HAL_TIM_Base_Init(&tim1);
	HAL_TIM_Base_Start_IT(&tim1);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
if (htim->Instance==TIM2 )
{
__HAL_RCC_TIM2_CLK_ENABLE ();
	HAL_NVIC_SetPriority ( TIM2_IRQn ,1,1);
	HAL_NVIC_EnableIRQ ( TIM2_IRQn );
}
}
void TIM2_IRQHandler()
{
HAL_TIM_IRQHandler(&tim1);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
if (htim->Instance ==TIM2)
{
HAL_GPIO_TogglePin (GPIOC,GPIO_PIN_13);
}
}