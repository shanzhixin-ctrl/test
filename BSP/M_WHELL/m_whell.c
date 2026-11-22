#include "m_whell.h"
#include "../ENCODER/encoder.h"
extern work_state work;
extern TIM_HandleTypeDef htim3;
PID pid_fl;
PID pid_fr;
PID pid_rr;
PID pid_rl;

float Vx_FL;
float Vy_FL;
float Vw_FL;
float V_FL;




float Vx_FR;
float Vy_FR;
float Vw_FR;
float V_FR;


float Vx_RL;
float Vy_RL;
float Vw_RL;
float V_RL;





float Vx_RR;
float Vy_RR;
float Vw_RR;
float V_RR;

extern  float fr_speed;
extern float rl_speed;
extern float rr_speed;


 float change_speed(int v)
{
float speed;
	float IspeedI;
if (v>100||v<-100)
{
return 0.0f;}
IspeedI=v<0 ?-v :v;
if (IspeedI<5.0f)
{
return 0;}
if(IspeedI>80.0f)
{
speed=400;

}
else {

speed=(IspeedI-5.0f)/75.0f*400;
}

return v<0   ? -speed  :speed;
}



void wheel_reset(int u)
{
	
	

	
	
    
    int limit;
  


    limit = (int)__HAL_TIM_GET_AUTORELOAD(&htim3);

    if (u > limit)  u = limit;
    if (u < -limit) u = -limit;

   
				
				if(u==0)
				{
			
    __HAL_TIM_SET_COMPARE(&htim3 ,TIM_CHANNEL_1,0);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
					return;
				
				}
  
 
    if (u > 0)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    }
    else if(u<0)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    }

    __HAL_TIM_SET_COMPARE(
        &htim3,
        TIM_CHANNEL_1,
        (uint32_t)(u > 0 ? u : -u)
    );

 

}



void wheel_update()
{
	static bool stop=true;;
	
	float meaure= montor_claude(5,0.1f);
Vx_FL =change_speed(work.side );
	Vy_FL =change_speed(work.up_down );
	Vw_FL =change_speed (work.circle );
	V_FL=Vx_FL +Vy_FL+Vw_FL  ;
	
	
	if(V_FL>600)
	{
	V_FL=600;
	}
	if(V_FL<-600)
	{
	V_FL=-600;
	}
	
	
	pid_fl.set =V_FL;
	
	
	if(V_FL >-0.5f&&V_FL <0.5f)
	{
	 pid_fl.set = 0.0f;
        pid_fl.inv = 0.0f;
        pid_fl.last_err = 0.0f;
        pid_fl.out = 0.0f;
stop=true;
        wheel_reset(0);
     
        return;
	
	}
	
	


	
	
if(stop){
pid_fl .inv=0.0f;
	pid_fl.last_err =pid_fl.set-meaure ;
	stop=false;

}
		float speed=pid_update_fl(&pid_fl ,meaure ,0.1f);
wheel_reset (speed);
	
	
}
















 float change_speed_fr(int v)
{
float speed;
	float IspeedI;
if (v>100||v<-100)
{
return 0.0f;}
IspeedI=v<0 ?-v :v;
if (IspeedI<5.0f)
{
return 0;}
if(IspeedI>80.0f)
{
speed=400;

}
else {

speed=(IspeedI-5.0f)/75.0f*400;
}

return v<0   ? -speed  :speed;
}



void wheel_reset_fr(int u)
{
	
	

	
	
    int limit;
   


    limit = (int)__HAL_TIM_GET_AUTORELOAD(&htim3);

    if (u > limit)  u = limit;
    if (u < -limit) u = -limit;

   
if(u==0)
				{
			
    __HAL_TIM_SET_COMPARE(&htim3 ,TIM_CHANNEL_2,0);
				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
					return;
				
				}
   

    if (u > 0)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
    }

    __HAL_TIM_SET_COMPARE(
        &htim3,
        TIM_CHANNEL_2,
        (uint32_t)(u > 0 ? u : -u)
    );



}











void wheel_update_fr()
{
	static bool stop_fr=true;;
	
	float meaure=fr_speed ;
Vx_FR =change_speed(work.side );
	Vy_FR =change_speed(work.up_down );
	Vw_FR =change_speed_fr (work.circle );
	V_FR=-Vx_FR +Vy_FR-Vw_FR  ;
	
	
	if(V_FR>600)
	{
	V_FR=600;
	}
	if(V_FR<-600)
	{
	V_FR=-600;
	}
	
	
	pid_fr.set =V_FR;
	
	
	if(V_FR >-0.5f&&V_FR<0.5f)
	{
	 pid_fr.set = 0.0f;
        pid_fr.inv = 0.0f;
        pid_fr.last_err = 0.0f;
        pid_fr.out = 0.0f;
stop_fr=true;
        wheel_reset_fr(0);
     
        return;
	
	}
	
	


	
	
if(stop_fr){
pid_fr .inv=0.0f;
	pid_fr.last_err =pid_fr.set-meaure ;
	stop_fr=false;

}
		float speed=pid_update_fr(&pid_fr ,meaure ,0.1f);
wheel_reset_fr (speed);
	
	
}




















/*


PC13-------->SET--->+;
PB9--------->SET-->-;




*/










 float change_speed_rl(int v)
{
float speed;
	float IspeedI;
if (v>100||v<-100)
{
return 0.0f;}
IspeedI=v<0 ?-v :v;
if (IspeedI<5.0f)
{
return 0;}
if(IspeedI>80.0f)
{
speed=400;

}
else {

speed=(IspeedI-5.0f)/75.0f*400;
}

return v<0   ? -speed  :speed;
}



void wheel_reset_rl(int u)
{
	
	

	
	
    int limit;
   


    limit = (int)__HAL_TIM_GET_AUTORELOAD(&htim3);

    if (u > limit)  u = limit;
    if (u < -limit) u = -limit;

   
if(u==0)
				{
			
    __HAL_TIM_SET_COMPARE(&htim3 ,TIM_CHANNEL_3,0);
				  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
					return;
				
				}
 
    if (u > 0)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    }

    __HAL_TIM_SET_COMPARE(
        &htim3,
        TIM_CHANNEL_3,
        (uint32_t)(u > 0 ? u : -u)
    );



}











void wheel_update_rl()
{
	static bool stop_rl=true;;
	
	float meaure=rl_speed ;
Vx_RL =change_speed(work.side );
	Vy_RL =change_speed(work.up_down );
	Vw_RL =change_speed (work.circle );
	V_RL=-Vx_RL +Vy_RL +Vw_RL ;
	
	
	if(V_RL>600)
	{
	V_RL=600;
	}
	if(V_RL<-600)
	{
	V_RL=-600;
	}
	
	
	pid_rl.set =V_RL;
	
	
	if(V_RL >-0.5f&&V_RL<0.5f)
	{
	 pid_rl.set = 0.0f;
        pid_rl.inv = 0.0f;
        pid_rl.last_err = 0.0f;
        pid_rl.out = 0.0f;
stop_rl=true;
        wheel_reset_rl(0);
     
        return;
	
	}
	
	


	
	
if(stop_rl){
pid_rl .inv=0.0f;
	pid_rl.last_err =pid_rl.set-meaure ;
	stop_rl=false;

}
		float speed=pid_update_rl(&pid_rl ,meaure ,0.1f);
wheel_reset_rl(speed);
	
	
}













/*PB8----->+-->SET
PB7----->+--->SET



*/





 float change_speed_rr(int v)
{
float speed;
	float IspeedI;
if (v>100||v<-100)
{
return 0.0f;}
IspeedI=v<0 ?-v :v;
if (IspeedI<5.0f)
{
return 0;}
if(IspeedI>80.0f)
{
speed=400;

}
else {

speed=(IspeedI-5.0f)/75.0f*400;
}

return v<0   ? -speed  :speed;
}



void wheel_reset_rr(int u)
{
	
	

	
	
    int limit;
   


    limit = (int)__HAL_TIM_GET_AUTORELOAD(&htim3);

    if (u > limit)  u = limit;
    if (u < -limit) u = -limit;

   
if(u==0)
				{
			
    __HAL_TIM_SET_COMPARE(&htim3 ,TIM_CHANNEL_4,0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
					return;
				
				}
   
    if (u > 0)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
    }

    __HAL_TIM_SET_COMPARE(
        &htim3,
        TIM_CHANNEL_4,
        (uint32_t)(u > 0 ? u : -u)
    );



}











void wheel_update_rr()
{
	static bool stop_rr=true;;
	
	float meaure=rr_speed ;
Vx_RR =change_speed(work.side );
	Vy_RR =change_speed(work.up_down );
	Vw_RR=change_speed (work.circle );
	V_RR=Vx_RR +Vy_RR-Vw_RR  ;
	
	
	if(V_RR>600)
	{
	V_RR=600;
	}
	if(V_RR<-600)
	{
	V_RR=-600;
	}
	
	
	pid_rr.set =V_RR;
	
	
	if(V_RR >-0.5f&&V_RR<0.5f)
	{
	 pid_rr.set = 0.0f;
        pid_rr.inv = 0.0f;
        pid_rr.last_err = 0.0f;
        pid_rr.out = 0.0f;
stop_rr=true;
        wheel_reset_rr(0);
     
        return;
	
	}
	
	


	
	
if(stop_rr){
pid_rr .inv=0.0f;
	pid_rr.last_err =pid_rr.set-meaure ;
	stop_rr=false;

}
		float speed=pid_update_rr(&pid_rr ,meaure ,0.1f);
wheel_reset_rr(speed);
	
	
}




















