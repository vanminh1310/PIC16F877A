#include<pic.h>
#include"../../Libraries/timers.h"

#define LED PORTB

void chedo1(){
    for(int i = 0; i<3; i++){
        LED = 0xff;
        t0delay(11);
        LED = 0x00;
        t0delay(11);
    }
}
void chedo2(){
    for(int i = 0; i<8; i++ ){
        LED=(LED<<1)|0x01;}
        for(int i = 0; i<8; i++){
            LED = LED<<1;
          t0delay(11); 
        }
    
    
 }
void chedo3(){
    LED = 0xff;
    t0delay(21);
    LED = 0x00;
 
    
}
void chedo4(){
    for(int i = 0; i<8; i++){
            LED = LED<<1|0x01;
            t0delay(21);
        }
}



void main() {
    timer_int();
    TRISB = 0; //Port D is act as Output
    while (1) {
        chedo1();
        chedo2();
        chedo3();
        chedo4();
       
    }
}