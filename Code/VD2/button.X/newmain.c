#include<htc.h>
#define sw RD0	//Switch is connected at PORTD.0
#define _XTAL_FREQ 2000000
void delay()	
{	
unsigned int a;	
for(a=0;a<10000;a++);
}	
void main()	
{	
TRISB0=0;	//Port B act as Output
TRISD0=1;	//Port D act as Input
while(1) {	
    
if(!sw) {	
 __delay_ms(1000);
RB0=1;	//LED ON
} else	
RB0=0;	//LED OFF
}	
}	
