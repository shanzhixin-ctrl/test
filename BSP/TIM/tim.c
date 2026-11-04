#include "./BSP/TIM/tim.h"
#include "./BSP/MONTOR/montor.h"
TIM_HandleTypeDef tim2;
TIM_HandleTypeDef tim1;

void tim_init(int ccr)
{//TIM2
tim2.Instance =TIM2;
	tim2.Init.AutoReloadPreload =DISABLE;
	tim2.Init.ClockDivision =TIM_CLOCKDIVISION_DIV1 ;
	tim2.Init.Period =999;
	tim2.Init.Prescaler =71;
	tim2.Init.RepetitionCounter =0;
	tim2.Init.CounterMode =TIM_COUNTERMODE_UP ;
	//TIM1
	
	
	tim1.Instance =TIM1;
	tim1.Init.AutoReloadPreload =DISABLE ;
	tim1.Init .ClockDivision =TIM_CLEARINPUTPRESCALER_DIV1 ;
	tim1.Init .CounterMode =TIM_COUNTERMODE_UP ;
	tim1.Init .Prescaler =0;
	tim1.Init.Period =65535;
	tim1.Init .RepetitionCounter =0;
	
	//PWM

TIM_OC_InitTypeDef pwm;
	pwm.Pulse =ccr;
	pwm.OCMode =TIM_OCMODE_PWM1;
	pwm.OCPolarity =TIM_OCPOLARITY_HIGH ;
HAL_TIM_PWM_ConfigChannel (&tim2,&pwm,TIM_CHANNEL_1 );
HAL_TIM_PWM_Init(&tim2);
	//ENCODER
	
	TIM_Encoder_InitTypeDef encoder;
	
	
	encoder.EncoderMode = TIM_ENCODERMODE_TI12 ;
	encoder.IC1Prescaler =TIM_ICPSC_DIV1;
	encoder.IC1Selection =TIM_ICSELECTION_DIRECTTI ;
	encoder.IC1Polarity =TIM_ICPOLARITY_RISING ;
	encoder.IC1Filter =0;
	
	encoder.IC2Filter =0;
	encoder.IC2Polarity =TIM_ICPOLARITY_RISING ;
	encoder.IC2Prescaler=TIM_ICPSC_DIV1 ;
	encoder.IC2Selection=TIM_ICSELECTION_DIRECTTI ; 
	
	
	//TIM2-UPDETA ------>montor_claude()
	//Msp----->montor_calude
	__HAL_TIM_ENABLE_IT (&tim2,TIM_IT_UPDATE);
	
	// ALL_START 
	
	
HAL_TIM_PWM_Start (&tim2,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Init (&tim1,&encoder);
	HAL_TIM_Encoder_Start (&tim1,TIM_CHANNEL_ALL);
}
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
if(htim->Instance ==TIM2)
{
__HAL_RCC_TIM2_CLK_ENABLE ();//ENABLE PA0
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio;
	gpio.Mode =GPIO_MODE_AF_PP;
	gpio.Pin =GPIO_PIN_0;
	gpio.Pull =GPIO_PULLUP;
	gpio.Speed =GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&gpio);
	HAL_NVIC_SetPriority ( TIM2_IRQn  ,1,1);
	HAL_NVIC_EnableIRQ ( TIM2_IRQn  );
	
}
	
	
}
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim)
{
//-------TIM1---------\\
//CHANNEL 1-----PA8
	//CAHNNEL 2----PA9

	
	if(htim->Instance ==TIM1)
	{
	GPIO_InitTypeDef gpio;
		__HAL_RCC_TIM1_CLK_ENABLE ();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		gpio.Mode=GPIO_MODE_AF_INPUT ;
		gpio.Pin =GPIO_PIN_8|GPIO_PIN_9;
		HAL_GPIO_Init (GPIOA,&gpio);
	
	}

}
void TIM2_IRQHandler ()
{
HAL_TIM_IRQHandler(&tim2);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
if(htim->Instance ==TIM2)
{
float montor_claude();

}
}


