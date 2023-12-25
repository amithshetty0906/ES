#include<lpc214x.h>
#include<stdint.h>
int count;

void PLLinit()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	VPBDIV=0x01;
}


void isr(void) __irq
{
	long int Temp;
  Temp = EXTINT;
if((Temp&0x01)==1)
{
if(count>10)
IO0SET |=0X02000000;
else
	 count++;
IO0CLR |=0X02000000;
}


EXTINT =Temp;
VICVectAddr=0x00;
}
	


void initInterrupt(void)
{
	VICIntEnable |=0x01<<14;
	VICVectCntl0=(0x01<<5)|14;
	VICVectAddr0=(unsigned)isr;
	
	PINSEL0=0x0c;
	EXTMODE|=0x01;
	EXTPOLAR|=0x00;
}


int main()
{
	return 0;
}
