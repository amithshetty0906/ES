#include<LPC214x.h>
#include "pll_init.h"
#include "delay.h"

int main(void)
{
	PLL_Configure();
	PINSEL0=0;
	IO0DIR |=1;
	while(1){
		IO0SET |= 0X01;
		delay_ms(10);
		IO0CLR |=0x01;
		delay_ms(10);
	}
	return 0;
}

