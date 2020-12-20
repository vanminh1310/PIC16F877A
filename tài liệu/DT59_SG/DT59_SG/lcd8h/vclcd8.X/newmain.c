/* 
 * File:   newmain.c
 * Author: BinhNGO
 *
 * Created on September 26, 2020, 7:19 AM
 */
#include<pic.h>
#include"lcd.h"

void main()
{
	lcd_init();
    TRISD=0;              //Port D is act as Output
    show("LCD uyfkuyg");
	PORTD=0x00;   //Port D ON
	while(1) {
      PORTD=0xff;   //Port D ON  
    }
}   
