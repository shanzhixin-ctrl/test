#include "./BSP/PID/pid.h"

typedef struct {

	float Ki,Kp,Ke;
	float set;
	float err,last_err;
	float inv;
	
	
	
}PID;

void pin_init(PID*p,float Ki,float Kp,float Ke)
{
p->Ke =Ke;
	p->Ki =Ki;
	p->Kp=Kp;
	p->last_err=0;
	p->err=0;
	p->inv =0;
	p->set =0;

}
float pid_update(PID*p,float measure,float tim)
{
p->err=p->set-measure ;
	
	p->inv+=p->err;
	
	
	float out=p->Kp*p->err+p->Ki*p->inv+p->Ke*((p->err-p->last_err )/tim);
	p->last_err =p->err; 
	
	return out;

}








