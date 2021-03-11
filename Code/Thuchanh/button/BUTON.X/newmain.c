/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on December 23, 2020, 8:48 PM
 */
//#include<htc.h>
//#include<pic.h>
//__CONFIG(0x377A);

//void interrupt ISR(void);
//void main (void)
//{
//   
//     OPTION_REG=0X00;	//falling edge int @ enable pullup portb
//
//INTCON|=0Xd0; 	
//
//    
//    TRISD1 = 0;
//    TRISD0 =0;
//    PORTD = 0X00;
//    TRISB0=1;
//    TRISB1 =1;
//    
//     GIE = 1;
//    INTE = 1;
//   INTEDG = 1;
//    while(1)
//    {
//        if(RB1==1){
//            RD0=0;
//        
//        }
//        else{
//        
//        RD0=1;
//        }
//
//    } 
//}
//void interrupt ISR(void)
//{
//        if(INTF==1)
//        {
//            {
//                RD1 =!RD1;
//                INTF=0;
//            }
//        } 
//
//}
#include<pic.h>

#define LED PORTD
__CONFIG(0x377A);

void interrupt ISR(void)

{

unsigned int i,j;

LED=0Xff;

for(i=0;i<600;i++)

for(j=0;j<200;j++);

INTF=0;

}

void main(void)

{
   TRISB1 =1;
    TRISD1 = 0;
LED=0;

TRISB0=1;

TRISD=0;

OPTION_REG=0X00;	//falling edge int @ enable pullup portb

INTCON|=0Xd0; 	//  cho hai tr??ng h?p n?u sài song song có c? timer và ng?n 

while(1) {

 if(RB1==1){
          LED=0;
            }
       else{
       
      LED=1;
      }

}

}

