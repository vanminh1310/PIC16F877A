/*
 * File:   INT_RB0.c
 * Author: Dell
 * My blog http://xcvn.blogspot.com
 * Created on November 24, 2015, 8:31 PM
 */

#define _XTAL_FREQ 8000000
#include <xc.h>
void interrupt ISR(void);
void main (void)
{
    
    TRISD0= 0;
    RD0 = 0;
    TRISB0 = 1;
    PORTB = 0X00;
    GIE = 1;
    INTE = 1;
    INTEDG = 1;
    while(1)
    {
        
    } 
}
void interrupt ISR(void)
{
        if(INTF==1)
        {
            {
                RD0=!RD0;
                INTF=0;
            }
        } 
}