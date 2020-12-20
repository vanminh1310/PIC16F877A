/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on December 18, 2020, 8:32 AM
 */

#include<htc.h>
#include<pic.h>
__CONFIG(0x377A);



#define LED PORTD
#define btn TRISB1
void delay(){
    for(int i = 0; i<5000;i++);
}

void chedo1(){
    for(int i = 0; i<3; i++){
        LED = 0xff;
        delay();
        LED = 0x00;
        delay();
    }
}
void chedo2(){
    for(int i = 0; i<8; i++ ){
        LED=(LED<<1)|0x01;}
        for(int i = 0; i<8; i++){
            LED = LED<<1;
            delay();
        }
    
    
 }
void chedo3(){
    LED = 0xff;
    delay();
    LED = 0x00;
 
    
}
void chedo4(){
    for(int i = 0; i<8; i++){
            LED = LED<<1|0x01;
            delay();
        }
}
void chedo5(){
  for(int i = 8; i>0; i--){
            LED = LED>>1|0x01;
            delay();
        }
}
void chedo6(){
    
     for(int i = 8; i>0; i-- ){
        LED=(LED>>1)|0x01;}
        for(int i = 8; i>0; i--){
            LED = LED<<1;
            delay();
        }

}
void btn1(){
    if(btn==0){
        LED = 0xff;
        delay();
        
    }
}
void main(){
    TRISD = 0;
    TRISB1=1;
    
    while(1){
        chedo1();
        chedo2();
        chedo3();
        chedo4();
        chedo5();
        chedo6();
      
    }
}