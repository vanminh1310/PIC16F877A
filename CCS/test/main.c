
#include <main.h>
#fuses NOWDT,HS,PUT,NOPROTECT

void sangdan(){
int8 i,temp;
temp = 0x00;
for(i=0;i<=8;i++){
   output_d(temp);
   temp<<=1;
   temp = temp|0x01;
   
   delay_ms(250);
   
}
}
void test(){
//output_d (0xff) ;
output_d(0xff);
delay_ms(1000);
output_d(0x00);
delay_ms(1000);
}

void main()
{
INT8 i;
set_tris_d(0x00);

//Example blinking LED program
WHILE (true)
{
test();
//sangdan();
//chedo3();
}
}

