#define _XTAL_FREQ 8000000 // m?c ??nh 

#include <xc.h>


// ph?n n�y khai b�o m?c ??nh 


//END CONFIG
//void delay(int a){
//    int i;
//    for(i=0;i<a;i++){
//        while(!T0IF);
//        T0IF=0;
//        
//    }
//}

int main()
 {

    TRISB1 = 0; //RB0 la chan ngo ra khai b�o ch�n nh? b�nh th??ng 

    while (1)
 {

        RB1 = 1; // LED SANG m?c 1 th� ?�n s�ng 
        __delay_ms(1000); // Delay 1 giay

        RB1 = 0; // LED TAT  m?c 0 th� ?�n t?t 
        __delay_ms(1000); // Delay 1 giay
    }

    return 0;

}