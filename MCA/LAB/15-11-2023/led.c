//led is connected to P0.5 and P0.8 when siwtch is pressed each time second led should glow double speed of first.

//Delay.h 
#include <LPC214X.h>

#ifndef _DELAY_H_ 

#define _DELAY_H_ 

  

#include <stdint.h> 

  

void delay_ms(uint32_t ms); 

  

void delay_us(uint32_t us); 

  

#endif //_DELAY_H_ 

 

//Delay.c 

 

//#include "delay.h" 

  

void delay_ms(uint32_t ms) 

{ 

T1CTCR =0x00; 

T1TCR =0x00; 

T1TC =0; 

T1PC =0; 

T1PR = 59999; 

T1TCR =0x01; 

while(T1TC<ms); 

T1TCR =0x00; 

} 

  

void delay_us(uint32_t us) 

{ 

T1CTCR =0x00; 

T1TCR =0x00; 

T1TCR =0x02; 

T1PR = 59; 

T1TC =0; 

T1TCR =0x01; 

while(T1TC<us); 

T1TCR =0x00; 

} 

//Extint.h 

#ifndef _EXT_INT_H_ 

#define _EXT_INT_H_ 

  

  

void InterruptInit(void); 

 

#endif //_EXT_INT_H_ 

//Extint.c 

#include <lpc214x.h> 

  

__irq void myExtISR (void) 

{ 

EXTINT |= 2; // clear FLAG 

 

VICVectAddr = 1; 

} 

void InterruptInit(void) 

{ 

EXTMODE |= 2;// ENI1  GPIO Port 0.14 

EXTPOLAR = 0; 

PINSEL0 |= 0x20000000; //  GPIO Port 0.14 

VICVectCntl0 = 0x20 | 15; 

VICVectAddr0 = (unsigned long) myExtISR; 

VICIntEnable |= 1<<15; 

} 

//Lcd.h 

#ifndef _LCD_H_ 

#define _LCD_H_ 

  

void LCD_CMD(char command); 

void LCD_CHAR (char msg); 

void LCD_INIT(void); 

  

#endif 

//Lcd.c 

 

#include <lpc214x.h> 

//#include "delay.h" 

  

// LCD Data pins D4-D7 are connected to pins P0.8-P0.11 of Port 0. 

  

// LCD control pins RS, RW and EN are connected to P0.4, P0.5 P0.6 respectively. 

 

void LCD_CMD(char command) 

{ 

IO0PIN = ( (IO0PIN & 0xFFFFF0FF) | ((command & 0xF0)<<4) ); /* Upper nibble of command */ 

IO0SET = 0x00000040; /* EN = 1 */ 

IO0CLR = 0x00000030; /* RS = 0, RW = 0 */ 

delay_ms(5); 

IO0CLR = 0x00000040; /* EN = 0, RS and RW unchanged(i.e. RS = RW = 0)	 */ 

delay_ms(5); 

IO0PIN = ( (IO0PIN & 0xFFFFF0FF) | ((command & 0x0F)<<8) ); /* Lower nibble of command */ 

IO0SET = 0x00000040; /* EN = 1 */ 

IO0CLR = 0x00000030; /* RS = 0, RW = 0 */ 

delay_ms(5); 

IO0CLR = 0x00000040; /* EN = 0, RS and RW unchanged(i.e. RS = RW = 0)	 */ 

delay_ms(5);	 

} 

  

void LCD_CHAR (char msg) 

{ 

IO0PIN = ( (IO0PIN & 0xFFFF00FF) | ((msg& 0xF0)<<8) ); 

IO0SET = 0x00000050; /* RS = 1, EN = 1 */ 

IO0CLR = 0x00000020; /* RW = 0 */ 

delay_ms(2); 

IO0CLR = 0x00000040; /* EN = 0, RS and RW unchanged(i.e. RS = 1, RW = 0) */ 

delay_ms(5); 

IO0PIN = ( (IO0PIN & 0xFFFF00FF) | ((msg& 0x0F)<<12) ); 

IO0SET = 0x00000050; /* RS = 1, EN = 1 */ 

IO0CLR = 0x00000020; /* RW = 0 */ 

delay_ms(2); 

IO0CLR = 0x00000040; /* EN = 0, RS and RW unchanged(i.e. RS = 1, RW = 0) */ 

delay_ms(5); 

} 

  

void LCD_INIT(void) 

{ 

IO0DIR = 0x0000FFF0; /* P0.12 to P0.15 LCD Data. P0.4,5,6 as RS RW and EN */ 

delay_ms(20); 

LCD_CMD(0x02);  /* Initialize lcd in 4-bit mode */ 

LCD_CMD(0x28);  /* 2 lines */ 

LCD_CMD(0x0C);   /* Display on cursor off */ 

LCD_CMD(0x06);  /* Auto increment cursor */ 

LCD_CMD(0x01);   /* Display clear */ 

LCD_CMD(0x80);  /* First line first position */ 

} 

#ifndef _PLL_INIT_H_ 

#define _PLL_INIT_H_ 

  

void PLL_Configure(void); 

  

#endif //_PLL_INIT_H_ 

 

#include <LPC214X.h> 

  

void PLL_Configure(void) 

{ 

PLL0CON = 0x01; 

PLL0CFG = 0x24; 

PLL0FEED = 0xAA; 

PLL0FEED = 0x55; 

while((PLL0STAT&0x400)==0); 

PLL0CON = 0x03; 

VPBDIV = 0x01; 

PLL0FEED = 0xAA; 

PLL0FEED = 0x55; 

} 

#include <lpc214x.h> 

//#include "uart.h" 

void uart_init(void) 

{ 

  PINSEL0 	= 0x00000005;			/* Enable RxD0 and TxD0              */  

  U0LCR 	= 0x00000083;				/* 8 bits, no Parity, 1 Stop bit     */ 

  U0DLL 	= (390&0xff);				/* 9600 Baud Rate @ 60MHz VPB Clock  */ 

  U0DLM 	= (390&0xff00)>>8;	/* 9600 Baud Rate @ 60MHz VPB Clock  */ 

  U0LCR 	= 0x00000003;				/* DLAB = 0                          */ 

} 

  

  

void uart_send(uint8_t byte) 

{ 

  while (!(U0LSR & 0x20)); 

  U0THR = byte; 

} 

int16_t uart_read(void) 

{ 

  if (U0LSR & 0x01) 

return (U0RBR); 

else  

return -1; 

} 

#ifndef __UART_H_ 

#define __UART_H_ 

  

#include <stdint.h> 

  

void uart_init(void); 

void uart_send(uint8_t byte); 

int16_t uart_read(void); 

  

#endif // __UART_H_ 

#include <lpc214x.h> 

#include <stdint.h> 

  

//#include "pll_init.h" 

//#include "uart.h" 

//#include "ext_int.h" 

//#include "delay.h" 

//#include "lcd.h" 

  

int number = 100; 

int delay = 10; 

int temp_delay = 0; 

volatile uint32_t ms = 0; 

void ProcessSerial(uint8_t c); 

  

int main(void) 

{ 

PLL_Configure(); 

uart_init(); 

InterruptInit(); 

LCD_INIT(); 

IO0DIR |=(1<<2); // P0.2 

while(1) 

{ 

int16_t c = uart_read(); 

IO0CLR |=(1<<2); 

delay_us(delay); 

IO0SET |=(1<<2); 

delay_us(delay); 

if(c!=-1) 

{ 

ProcessSerial(c); 

} 

 

} 

} 

  

void ProcessSerial(uint8_t c) 

{ 

if(c=='\r'||c=='\n') 

{ 

delay= temp_delay!=0?temp_delay:10; 

uart_send('\r'); 

uart_send('\n'); 

uart_send(((delay/10000)%10)+'0'); 

uart_send(((delay/1000)%10)+'0'); 

uart_send(((delay/100)%10)+'0'); 

uart_send(((delay/10)%10)+'0'); 

uart_send((delay%10)+'0'); 

uart_send('\r'); 

uart_send('\n'); 

temp_delay = 0; 

}else if((c<='9')&&(c>='0')){ 

c= c-'0'; 

temp_delay =( temp_delay*10) +c; 

} 

} 