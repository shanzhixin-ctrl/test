#ifndef _PID_H

#define _PID_H

typedef struct {
float err;
float Kp,Ki,Kd;
	float last_err;
	float set;
	
	float inv;
	float inv_max_out;
	float out;
	float out_max_out;
}PID;
 float pid_update_fl(PID *p, float measured, float dt);

void pid_init_fl(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out);

float pid_update_fr(PID *p, float measured, float dt);

void pid_init_fr(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out);
float pid_update_rl(PID *p, float measured, float dt);

void pid_init_rl(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out);
float pid_update_rr(PID *p, float measured, float dt);

void pid_init_rr(PID*p,float Kp,float Ki,float Kd,float inv_max_out,float out_max_out);


#endif