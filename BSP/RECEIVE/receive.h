#ifndef _RE_H
#define _RE_H

#include "stm32f1xx_hal.h"
#include "../BLUE/blue.h"
#include "../M_WHELL/m_whell.h"
void bt_start();
extern TIM_HandleTypeDef htim1;



void uart_receive_start();
void uart_receive ();



#endif