#include <16f877a.h>
#use delay(clock=20000000)
#byte portb=0x06
#byte portd=0x08
#INT_RB
rb_isr();
void dsjd()
{
portd=portb;
}


void main()
{
set_tris_b(0xF0);
set_tris_d(0x00);
enable_interrupts(INT_RB);
enable_interrupts(GLOBAL);
   while(TRUE)
   {
      //TODO: User Code
   }

}
