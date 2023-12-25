#include<lpc214x.h>
#define LED_PIN (1<<6)

void initPLL()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x00000000;
	while((PLL0STAT & 0x400)==0);
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x00000000;
	VPBDIV=0x01;
}

void delay(unsigned int microseconds)
{
	T0CTCR=0X00;
	T0PR=60000-1;
	T0TCR=0X01;
		while(T0TC <microseconds)
			T0TCR=0X00;
	
}

int main(void)
{
int i;
IO0DIR |= (0xffffffff);//we can also give (0xff000000)
IO0DIR &= ~LED_PIN;
//IO0SET |=LED_PIN;
initPLL();
PINSEL0=0;
while(1)
{
if((IO0PIN & LED_PIN)==0){
//for(i=0;i<32;i++){
IO0SET |=(0x01<<12); //set p0.0 to high
delay(100); //delay of 100 ms
}
//else{
IO0CLR |=(0x01<<12); // set p0.0 to low
delay(100); //delay of 100 ms
}
return 0;
}