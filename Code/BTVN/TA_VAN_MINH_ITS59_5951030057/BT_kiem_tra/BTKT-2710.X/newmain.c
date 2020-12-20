/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on November 28, 2020, 2:59 PM
 */

#include<pic.h>
#define _XTAL_FREQ 2000000
unsigned int mang[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xFF};

void main(){
    int dem = 50;
    TRISD0=TRISD1=1;
    TRISD2=0;
    TRISB=TRISC= 0;
    while(1){
      
            
        for(dem; dem<71; dem++){
                int dv=dem%10;
                int chuc=dem/10;
                PORTC=mang[dv];
                PORTB=mang[chuc];
                __delay_ms(200);
               
                
                
                }
          
          
            
        }
        
        
        
     
        
    }

