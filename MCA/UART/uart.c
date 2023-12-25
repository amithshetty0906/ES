#include<lpc214x.h>

void pll()
{
  PLL0CON=0X01;
  PLL0CFG=0X24;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  while((PLL0STAT&(1<<10))==0);
  PLL0CON=0X03;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  VPBDIV=0x01;             //pclk=60mhz
}

void ser_int()
{
  PINSEL0=0X05;
  U0LCR=0X83;
  U0DLL=0x87;
  U0DLM=0x1;
  U0LCR=0X03;
}

void tx(unsigned char a)
{
  while((U0LSR&(1<<5))==0);
  U0THR=a;
}

char rx()
{
  unsigned char a;
  while((U0LSR&(1<<0))==0);
  a=U0RBR;
  return a;
}

void print(unsigned char a[])
{
	int i=0;
	while(a[i]!='\0'){
		tx(a[i]);
		i++;
	}
}

void delay(unsigned int micro)
{
	for(int i=0;i<micro;i++){
	for(int j=0;j<30000;j++){
	}}
}

int main(void)
{
  ser_int();
  while(1) {
    print("hell");
		tx(13);
		
		rx(10);
		delay(100);
	}
	return 0;
}