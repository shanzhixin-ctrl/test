#include "pid.h"



void pid_init_fl(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out)
{
p->Kd =Kd;
	p->Ki =Ki;
	p->Kp=Kp;
	p->set =0;
	p->last_err =0;
	p->inv =0;
p->out_max_out =out_max_out ;
	p->inv_max_out =inv_max_out ;
}
 float pid_update_fl(PID *p, float measured, float dt)
 {
	 
	 
	 float old_inv;
	 float d_out;
	 if(p==0)
	 {
	 return 0;}
	 if(dt<=0)
	 {
	 
	 return 0;}
	 
	 
 p->err =p->set -measured ;
	 old_inv =p->inv;
	 p->inv +=p->err*dt;
	 
	 if(p->inv>p->inv_max_out )
	 {
	 
	 p->inv=p->inv_max_out ;
	 
	 }
	  else if (p->inv < -p->inv_max_out)
    {
        p->inv = -p->inv_max_out;
    }
		d_out=p->Kd *((p->err -p->last_err )/dt);
		
	 
	 p->out =p->err *p->Kp+p->Ki*p->inv+p->Kd*((p->err -p->last_err )/dt);
	 
		 if ((p->out >  p->out_max_out && p->err > 0.0f) ||
        (p->out < -p->out_max_out && p->err < 0.0f))
    {
        p->inv = old_inv;

      
        p->out = p->Kp * p->err
               + p->Ki * p->inv
               + d_out;
    }
		
		if(p->out>p->out_max_out )
	 {
	 
	 p->out=p->out_max_out ;
	 }
	  else if (p->out < -p->out_max_out)
    {
        p->out = -p->out_max_out;
    }
	 p->last_err =p->err ;
 return p->out;
 }




void pid_init_fr(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out)
{
p->Kd =Kd;
	p->Ki =Ki;
	p->Kp=Kp;
	p->set =0;
	p->last_err =0;
	p->inv =0;
p->out_max_out =out_max_out ;
	p->inv_max_out =inv_max_out ;
}
 float pid_update_fr(PID *p, float measured, float dt)
 {
	 
	 
	 float old_inv;
	 float d_out;
	 if(p==0)
	 {
	 return 0;}
	 if(dt<=0)
	 {
	 
	 return 0;}
	 
	 
 p->err =p->set -measured ;
	 old_inv =p->inv;
	 p->inv +=p->err*dt;
	 
	 if(p->inv>p->inv_max_out )
	 {
	 
	 p->inv=p->inv_max_out ;
	 
	 }
	  else if (p->inv < -p->inv_max_out)
    {
        p->inv = -p->inv_max_out;
    }
		d_out=p->Kd *((p->err -p->last_err )/dt);
		
	 
	 p->out =p->err *p->Kp+p->Ki*p->inv+p->Kd*((p->err -p->last_err )/dt);
	 
		 if ((p->out >  p->out_max_out && p->err > 0.0f) ||
        (p->out < -p->out_max_out && p->err < 0.0f))
    {
        p->inv = old_inv;

      
        p->out = p->Kp * p->err
               + p->Ki * p->inv
               + d_out;
    }
		
		if(p->out>p->out_max_out )
	 {
	 
	 p->out=p->out_max_out ;
	 }
	  else if (p->out < -p->out_max_out)
    {
        p->out = -p->out_max_out;
    }
	 p->last_err =p->err ;
 return p->out;
 }



void pid_init_rl(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out)
{
p->Kd =Kd;
	p->Ki =Ki;
	p->Kp=Kp;
	p->set =0;
	p->last_err =0;
	p->inv =0;
p->out_max_out =out_max_out ;
	p->inv_max_out =inv_max_out ;
}
 float pid_update_rl(PID *p, float measured, float dt)
 {
	 
	 
	 float old_inv;
	 float d_out;
	 if(p==0)
	 {
	 return 0;}
	 if(dt<=0)
	 {
	 
	 return 0;}
	 
	 
 p->err =p->set -measured ;
	 old_inv =p->inv;
	 p->inv +=p->err*dt;
	 
	 if(p->inv>p->inv_max_out )
	 {
	 
	 p->inv=p->inv_max_out ;
	 
	 }
	  else if (p->inv < -p->inv_max_out)
    {
        p->inv = -p->inv_max_out;
    }
		d_out=p->Kd *((p->err -p->last_err )/dt);
		
	 
	 p->out =p->err *p->Kp+p->Ki*p->inv+p->Kd*((p->err -p->last_err )/dt);
	 
		 if ((p->out >  p->out_max_out && p->err > 0.0f) ||
        (p->out < -p->out_max_out && p->err < 0.0f))
    {
        p->inv = old_inv;

      
        p->out = p->Kp * p->err
               + p->Ki * p->inv
               + d_out;
    }
		
		if(p->out>p->out_max_out )
	 {
	 
	 p->out=p->out_max_out ;
	 }
	  else if (p->out < -p->out_max_out)
    {
        p->out = -p->out_max_out;
    }
	 p->last_err =p->err ;
 return p->out;
 }



void pid_init_rr(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out)
{
p->Kd =Kd;
	p->Ki =Ki;
	p->Kp=Kp;
	p->set =0;
	p->last_err =0;
	p->inv =0;
p->out_max_out =out_max_out ;
	p->inv_max_out =inv_max_out ;
}
 float pid_update_rr(PID *p, float measured, float dt)
 {
	 
	 
	 float old_inv;
	 float d_out;
	 if(p==0)
	 {
	 return 0;}
	 if(dt<=0)
	 {
	 
	 return 0;}
	 
	 
 p->err =p->set -measured ;
	 old_inv =p->inv;
	 p->inv +=p->err*dt;
	 
	 if(p->inv>p->inv_max_out )
	 {
	 
	 p->inv=p->inv_max_out ;
	 
	 }
	  else if (p->inv < -p->inv_max_out)
    {
        p->inv = -p->inv_max_out;
    }
		d_out=p->Kd *((p->err -p->last_err )/dt);
		
	 
	 p->out =p->err *p->Kp+p->Ki*p->inv+p->Kd*((p->err -p->last_err )/dt);
	 
		 if ((p->out >  p->out_max_out && p->err > 0.0f) ||
        (p->out < -p->out_max_out && p->err < 0.0f))
    {
        p->inv = old_inv;

      
        p->out = p->Kp * p->err
               + p->Ki * p->inv
               + d_out;
    }
		
		if(p->out>p->out_max_out )
	 {
	 
	 p->out=p->out_max_out ;
	 }
	  else if (p->out < -p->out_max_out)
    {
        p->out = -p->out_max_out;
    }
	 p->last_err =p->err ;
 return p->out;
 }



 
 




