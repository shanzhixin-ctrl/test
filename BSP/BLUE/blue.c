#include "blue.h"
#include <stdio.h>
static char buf[BIT_MAX]={0};

static uint8_t len=0;

static char finish_buf[BIT_MAX]={0};

static volatile bool sim;

work_state run;

void bt_feed(uint8_t bit)
{

if(bit=='[')
{
len=0;
	buf[len++]='[';
	return ;
}

if(len==0)
{
return ;}
if(bit==']')
{
	if(len>=BIT_MAX-1)
	{
	
	len=0;
	return ;
	}
	
	
	buf[len++]=']';
	buf[len]='\0';
	 if (sim == false)             
        {
            strcpy(finish_buf, buf);
            sim = true;
        }
len=0;
				return ;


}
 if (len >= BIT_MAX - 2)
    {
       
        len = 0;
        return;
    }

else if(len>0){

buf[len++]=(char)bit;
	
	//out-----

//re-----
uint8_t sim_len=len-1;
if(buf[sim_len ]=='[')
{
len=0;
	buf[len++]='[';
	
}

}


}
bool get_bit(work_state *work)
{if(sim==false)return false;
	
	char tmp[BIT_MAX];
	strcpy(tmp,finish_buf );
	int side;
	int up_down;
	int circle;
	int goz;
if(sscanf(tmp,"[joystick,%d,%d,%d,%d",&side,&up_down,&circle,&goz)==4){

	work->side =side;
	work->up_down =up_down ;
	work->circle =circle;
	work->goz=goz;
sim=false;
	
	return true;
}
else {
sim=false;
	return false;
}
}





