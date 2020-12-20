#include <pic.h>
#define _XTAL_FREQ 2000000
unsigned char Ma7Doan[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xFF};

void SEG7_OUT(unsigned char Dem);

void main()
{
   unsigned char Dem;   
   int t;

   while(TRUE)
   {
      //TODO: User Code
      for(Dem=0;Dem<100;Dem++)
      {
         t=0;
         while(t++<200)
         {
            SEG7_OUT(Dem);      
         }
      }
   }

}
//xay dung ham
void SEG7_OUT(unsigned char Dem)
{
   unsigned char HangChuc, DonVi;
   
   HangChuc = Dem/10;
   DonVi = Dem%10;
   
   HangChuc = Ma7Doan[HangChuc];
   DonVi = Ma7Doan[DonVi];
   
   PORTB(HangChuc);
   RC2(0);
   __delay_ms(1);
   RC2(1);
   
   PORTB(DonVi);
   RC3(0);
   __delay_ms(1);
   RC3(1);   
}


#include<pic.h>
#define _XTAL_FREQ 2000000
unsigned short i, j, num, dk; // Khai bao bien
// khai bao thu ham led 7 doan

unsigned short mask(unsigned short num) {
    switch (num) {
        case 0: return 0x3F;
        case 1: return 0x06;
        case 2: return 0x5B;
        case 3: return 0x4F;
        case 4: return 0x66;
        case 5: return 0x6D;
        case 6: return 0x7D;
        case 7: return 0x07;
        case 8: return 0x7F;
        case 9: return 0x6F;
    }
}
unsigned char mang[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void interrupt ISR(void)

{

unsigned int i,j;


    if(RB0==0){
        __delay_ms(1000);
        RB4 = 1;
        
    }
    else{
        RB4=0;
    }

INTF=0;


}


void main(){
TRISD=TRISC = 0x00;
TRISB0 = 1;
TRISB4 =0;

OPTION_REG=0X00;	//falling edge int @ enable pullup portb

INTCON|=0Xd0; 


while(1){
   
    RB4 = 0;
//    if(!RB0){
//        __delay_ms(1000);
//        RB4 = 1;
//        
//    }
//    else{
//        RB4=0;
//    }

    
    for(int a = 5; a<7; a++){
        for (int b = 0; b <10; b++) {
          RC2= 1; RC3=0; 
            PORTD = mask(a % 10);
            __delay_ms(500);
             RC3=1; RC2=0; 
            PORTD = mask(b % 10);
            
            __delay_ms(500);
        }
    } 
    
    
    
    
    for(int a =6 ; a>=5; a--){
        
        for (int b = 10; b >= 0; --b) {
          RC2= 1; RC3=0; 
            PORTD = mask(a % 10);
      __delay_ms(500);
        RC3=1; RC2=0;
            PORTD = mask(b % 10);
            
            __delay_ms(500);
        }
    }  

    
}

}