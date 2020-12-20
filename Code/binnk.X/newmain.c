#define _XTAL_FREQ 8000000 // m?c ??nh 

#include <xc.h>


// ph?n này khai báo m?c ??nh 


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

    TRISB1 = 0; //RB0 la chan ngo ra khai báo chân nh? bình th??ng 

    while (1)
 {

        RB1 = 1; // LED SANG m?c 1 thì ?èn sáng 
        __delay_ms(1000); // Delay 1 giay

        RB1 = 0; // LED TAT  m?c 0 thì ?èn t?t 
        __delay_ms(1000); // Delay 1 giay
    }

    return 0;

}