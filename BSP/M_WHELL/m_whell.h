#ifndef _WHEEL_H
#define _WHEEL_H

#include "stm32f1xx_hal.h"

void wheel_update_fr(void);

void wheel_update_rl(void);
void wheel_update_rr(void);



void V_FL_Init();







void wheel_reset(int u);
void wheel_update();
#include "../BLUE/blue.h"
#include "../PID/pid.h"
#endif 




