#ifndef _BLUE_H


#define _BLUE_H
#define BIT_MAX 40

#include <stdbool.h>
#include "stm32f1xx_hal.h"
#include <string.h>
typedef struct {

int side;
	int up_down;
	int circle;
int goz;
	
}work_state;
void bt_feed(uint8_t bit);/* bit----->buf[] */

bool get_bit(work_state *work);
#endif