#include <16F877a.h>

#FUSES NOWDT, HS, PUT, NOPROTECT,
#use DELAY(clock=20000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7) 

#define tb1 PIN_B0
#define tb2 PIN_B1
#define tb3 PIN_B2
#define tb4 PIN_B3

#define btn1 PIN_B4
#define btn2 PIN_B5
#define btn3 PIN_B6
#define btn4 PIN_B7  

// traffic light 
#define red PIN_D0
#define yl PIN_D1
#define gr PIN_D2

char d1;
int8 a,b,c,d = 0;



#INT_RDA
void ngat_uart(){
d1 = getc();
if(kbhit()){
 if(d1=='p'){
    putc('w');
   }  

   switch(d1){
   case '1':
     output_high(tb1);
     break;
   case '2':
     output_high(tb2);
     break;
   case '3':
     output_high(tb3);
     break;
   case '4':
     output_high(tb4);
     break;
   case '0':
     output_low(tb1);
     break;
   case '7':
     output_low(tb2);
     break;
   case '8':
     output_low(tb3);
     break;
   case '9':
     output_low(tb4);
     break;
     
   }

//

    
    
   
} 

}


void red1();
void yl1();
void gr1();
void uart_test();
void traffic();
void delay_r(int8 a);
void delay_g(int8 b);
void delay_y(int8 c);



void main()
{
enable_interrupts(GLOBAL);

enable_interrupts(INT_RDA);

SET_TRIS_B(0b00001111);

SET_TRIS_D(0x00);

output_b(0b11110000);
output_d(0x00);
while(true)
{ 
  uart_test();
  while(d1=='f'){
 traffic();
  }
}
}

void red1(){
      output_high(red);
       output_low(yl);
        output_low(gr);
}
void yl1(){
      output_high(yl);
       output_low(red);
        output_low(gr);
}
void gr1(){
      output_high(gr);
       output_low(yl);
        output_low(red);
}

void uart_test(){
 if(input(btn1)==0){
    putc('a');
   
    output_high(tb1);
    a++;
    while(input(btn1)==0);
   }
   if(input(btn2)==0){
    putc('b');
    output_high(tb2);
    b++;
    while(input(btn2)==0);
   }
   if(input(btn3)==0){
    putc('c');
    output_high(tb3);
    c++;
    while(input(btn3)==0);
   }
   if(input(btn4)==0){
    putc('d');
    output_high(tb4);
    d++;
    while(input(btn4)==0);
   }
   
   //
   
    if(a==2){
    putc('A');
    output_low(tb1);
    a=0;
   }
   
    if(b==2){
    putc('B');
    output_low(tb2);
    b=0;
  
   }
   
    if(c==2){
    putc('C');
    output_low(tb3);
    c=0;
  
   }
   
    if(d==2){
    putc('D');
    output_low(tb4);
    d=0;
  
   }
}

void delay_r(int8 a){
for(a ;a>=0;a--){
putc('r');
putc(a+48);
delay_ms(1000);
if(a==0){
break;
}
}
}

void delay_g(int8 b){
for(b ;b>=0;b--){
	
putc(b+48);
delay_ms(1000);
if(b==0){
break;
}
}
}

void delay_y(int8 c){
for(c ;c>=0;c--){
putc('y');
putc(c+48);
delay_ms(1000);
if(c==0){
break;
}
}
}

void traffic(){

         red1();
            delay_r(8);
        
        gr1();
       
           delay_g(9);
        
        yl1();
        
           delay_y(9);
        


}
