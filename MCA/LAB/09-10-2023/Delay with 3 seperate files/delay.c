#include<LPC214X.h>
#include "delay.h"

void delay_ms(uint32_t ms)
{
T0CTCR =0X00;
T0TCR = 0X00;
T0TC=0;
T0PR=59;
T0TCR=0X01;
while (T0TC<ms);
T0TCR=0x00;
}

void delay_us(uint32_t us)
{ 
	T0TCR = 0x00;
	T0CTCR = 0x00;
	T0TCR = 0x02;
	T0PR=59;
	T0TCR=0x01;
	while (T0TC <us);
	T0TCR = 0x00;
}
	