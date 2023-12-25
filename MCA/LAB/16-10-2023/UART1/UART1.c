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

void tx(unsigned char c)
{
  while((U0LSR&(1<<5))==0);
  U0THR=c;
}

char rx()
{
  unsigned char a;
  while((U0LSR&(1<<0))==0);
  a=U0RBR;
  return a;
}

int main(void)
{
	int i;
  unsigned char b[50]="hello";
	unsigned char c[50];
  pll();
  ser_int();
	tx(b);
  while(1) {
    //b=rx();
		for(i=0;i<50;i++){
    tx(b[i]);
			c[i]=rx();
		}
  }
	return 0;
}