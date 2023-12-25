#include<lpc214x.h>

#define LEDPIN_1 (1<<16)
#define LEDPIN_2 (1<<17)
#define LEDPIN_3 (1<<18)

#define BUTTONPIN_1 (1<<19)
#define BUTTONPIN_2 (1<<20)
#define BUTTONPIN_3 (1<<21)

void delay(unsigned int count)
{
	unsigned int i,j;
	for(i=0;i<count;i++){
		for(j=0;j<10000;j++){
		}
	}
}

int main(void)
{
	IO1DIR  = LEDPIN_1 | LEDPIN_2 | LEDPIN_3;
	
	IO1DIR &= ~(BUTTONPIN_1 | BUTTONPIN_2 | BUTTONPIN_3);
	
	while(1){
		if((IO1PIN & BUTTONPIN_1)==0){
			IO1PIN^= LEDPIN_1;
			delay(10000);
		}
		
		if ((IO1PIN & BUTTONPIN_2) == 0) {
			IO1PIN ^= LEDPIN_2;
			delay(10000);
		}
		
		if ((IO1PIN & BUTTONPIN_3) == 0) {
			IO1PIN ^= LEDPIN_3;
			delay(10000);
		}
	}
	return 0;
}