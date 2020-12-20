#include<pic.h>

void t1delay();

void main()
 {

    TRISB = 0;

    T1CON = 1; //Prescale value = 1:1, It using Internal clock, Timer 1 ON

    while (1) {

        PORTB = 0xff;

        t1delay();

        PORTB = 0;

        t1delay();

    }

}

void t1delay()
 {

    int i;

    for (i = 0; i < 42; i++) {

        TMR1H = TMR1L = 1;

        while (!TMR1IF);

        TMR1IF = 0;

    }

}
