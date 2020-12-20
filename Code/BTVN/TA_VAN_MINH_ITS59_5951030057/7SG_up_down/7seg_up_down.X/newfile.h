/* 
 * File:   newfile.h
 * Author: tamin
 *
 * Created on November 28, 2020, 10:22 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

#include <pic.h>
#define _XTAL_FREQ 2000000
unsigned short i, j, num, dk; // Khai bao bien
// khai bao thu ham led 7 doan
void delay(int n){
    for(int i ; i<n;i++);
}
unsigned short mask(unsigned short num) {
    switch (num) {
        case 0: return 0x3F;
        case 1: return 0x06;
        case 2: return 0x5B;
        case 3: return 0x4F;
        case 4: return 0x66;
        case 5: return 0x6D;
        case 6: return 0x7D;
        case 7: return 0x07;
        case 8: return 0x7F;
        case 9: return 0x6F;
    }
}

void setup() {
    TRISD0=TRISD1=1;
    TRISD2=0;
    TRISB = TRISC= 0x00; // chan D output h?t 
}



int main() {
    int dem = 0;
    setup();
    while (1) {

        if(RD0==1){
            dem++;
            RC0=1;RC1=0;
            PORTB=mask(dem%10);
        }
        else {
            RD2=0;
        }

//        for(int a = 5; a<7; a++){
//        for (int b = 0; b <10; b++) {
//          RC0= 0; RC1=1; 
//            PORTB = mask(a % 10);
//            __delay_ms(500);
//             RC0=1; RC1=0; 
//            PORTB = mask(b % 10);
//            __delay_ms(500);
//        }
//    } 
            
           
            

        }
      


    }
