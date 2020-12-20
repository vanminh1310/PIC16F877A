
#include<htc.h>

void delay() {
    unsigned int a;
    for (a = 0; a < 20000; a++);
}

void main() {
    TRISD = 0; //Port D is act as Output
    while (1) {
        PORTD = 0xFF; //Port D ON
        delay();
        PORTD = 0x00; //Port D OFF
        delay();
    }
}