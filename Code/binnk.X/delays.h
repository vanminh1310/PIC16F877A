#include "main.h"

void delay(int a){
    int i;
    for(i=0;i<a;i++){
        while(!T0IF);
        T0IF=0;
        
    }
}