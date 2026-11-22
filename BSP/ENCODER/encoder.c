#include "encoder.h"
#define pi 3.1415
static  float last_speed;
extern TIM_HandleTypeDef htim2;

float montor_claude(float r,float tim)
{

int16_t encoder_ccr=__HAL_TIM_GET_COUNTER (&htim2);
__HAL_TIM_SET_COUNTER(&htim2,0);
	float s=((float)encoder_ccr/(11*20*2))*2*pi*r;
	float speed=s/tim;
	last_speed=speed;
return speed;
	
	
}
