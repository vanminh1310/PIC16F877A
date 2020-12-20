/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on November 28, 2020, 9:21 AM
 */

#include<pic.h>
#include "key.h"
#include "7seg.h"

void main(){
    TRISB=TRISD=0x00;
    keyinit();
  unsigned int b;
    while(1){
        b=key();
        PORTD=mask(b%10);
    }
}
