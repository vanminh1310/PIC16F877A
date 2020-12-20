/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on November 13, 2020, 9:59 PM
 */
#include<pic.h>
#include <stdio.h>
#include <stdlib.h>
#include"timer.h"

/*
 * 
 */
void setup() {
    TRISB = 0x00;

}

void led1() {
    timer0(42);
    RB0 = 1;
    timer0(42);
    RB0 = 0;
}

void led2() {
    timer1(84);
    RB3 = 1;
    timer1(84);
    RB3 = 0;
}

void led3() {
    timer2(675);
    RB6 = 1;
    timer2(675);
    RB6 = 0;
} 
void ledoff(){
    RB0=0;
    RB3=0;
    RB6=0;
}

void main() {
    setup();
    while (1) {
        ledoff();
        led1();
        led2();
        led3();
    }
}