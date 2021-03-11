/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on December 25, 2020, 8:51 AM
 */

#include<pic.h>
__CONFIG(0x377A);
// Ha?m ngat Timer0, ??m 250 xung

void interrupt timer0(void) {
    unsigned char i;
    unsigned int counter; // su kien ngat timer0
    if (T0IF & T0IE) { // neu co ngat Timer0 xay ra
        TMR0 = 6;
        T0IF = 0; // xoa co ngat,
        ++counter;
        if (counter == 500) {
            PORTD = (1 << i) + (1 << (7 - i));
            ++i;
            if (i == 8) i = 0;
            counter = 0;
        };
    };
}

void init(void) {
    // Khoi tao I/O cho cac port
    TRISD = 0x00; // PortD as output
    
    // Khoi tao cho cac thanh ghi
    OPTION_REG = 0x00; // dung prescaler cho timer0
   // voi ti le la 1 : 2
            // Khoi tao cho ngat Timer0
     GIE = 1; // cho phep ngat toan cuc
    T0IE = 1; // cho phep ngat timer0
    T0IF = 0; // xoa co ngat
    TMR0 = 6; // khoi tao gtri ban ?â?u
}
// Chuong trinh chinh

void main() {
    init();
    while (1){
        RD1=RD3=RD4 = RD2 = 1;
        for (int i = 0; i<5;i++);
        RD1=RD3=RD4 = RD2 =0;
        for (int i = 0; i<5;i++);
            
        }
        
    
   
}