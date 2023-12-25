#include<lpc214x.h>


void initPLL()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x00000000;
	while((PLL0STAT & 0x400)==0);
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x00;
	VPBDIV=0x01;
}

void delay(unsigned int microseconds)
{
	/*T0CTCR=0X00;
	T0TCR=0x00;
	T0PR=59999;
	T0TCR=0X01;
	T0TCR=0X02;
		while(T0TC < microseconds)
			T0TCR=0X00;
		T0TC=0;*/
	for(int i=0;i<microseconds;i++){
	for(int j=0;j<30000;j++)
	{}
	
}}

int main(void)
{
	IO0DIR&=~0x10;
	IO0DIR =0x0F;
//	initPLL();
	while(1)
	{
		IOSET0 =0X01;
		delay(100);
		IO0CLR=0x01;
		delay(100);
		IOSET0=0x02;
		delay(100);
		IO0CLR=0x02;
	}
	return 0;
}