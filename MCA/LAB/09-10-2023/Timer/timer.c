#include<LPC214X.h>
#include "timer.h"

int main(void)
{
	IO0DIR	|= 0x01; // point port 0.0 to output
	
	while(1)
	{
		IO0SET |=0X01; //set po.o. as high
		Delay_us(100); //delay 100 us
		IO0CLR |= 0X01; //set 0.0 to low
		Delay_us(100); //delay 100 us
	}
	return 0;
	
	
}
void TimerInit()
{
	T0TCR = 0 ; //counters are disabled
	T0CTCR = 0; // select timer mode
	T0PR = 59;  // 1us
	T0TC = 0; //clear the timer count
	T0PC = 1; //reset the timer prescalar count
}

void Delay_us(uint32_t us)
{
	TimerInit();
	T0TCR=1;//start the timer
	while(T0TC<1);//check the timer count
	T0TCR=0;//diable the timer
}