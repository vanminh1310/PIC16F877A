#include <16f877a.h>
#fuses NOWDT, HS, PUT, NOPROTECT
#use delay(clock = 20000000)
#use fast_io(A)

#define led PIN_B5 //khai bao led

const char mang[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
const char mang2[4] = {0xBF, 0x88, 0xC7, 0xC7};

int16 dem;
void hienthi(int16 uivalue);
void hienthisl(int8 value);
void hienthiall();
void ledblynk();
void main()
{
  SET_TRIS_A(0xFF);
  SET_TRIS_D(0x00); //cai dat PORTD la output=DATA
  SET_TRIS_B(0x00); //PORT C = DIEU KHIEN
  SET_TRIS_C(0x00);
  setup_timer_0(RTCC_DIV_2 | RTCC_EXT_L_TO_H);

  set_timer0(0); //cai dat cho timer dem tu 0
                 // TMR0_TOCS = 1; //thiet lap Timer0 o trang thai counter nhan xung ngoaiTM
                 // TMR0_TOSE = 0; //cho phep timer0 TAC DONG CANH XUONG
  dem = 0;
  output_high(led);
  while (1)
  { //x=input(PIN_A4);
    // if(x==0)//chong nhieu khi RA4=0 thi tu dong counter dem len 1

    //dong while ko co cung duoc
   
    int8 a, b;

 
    dem = get_timer0();

    hienthi(dem);

    a = dem / 5;
    hienthisl(a);

    if (a==1)
    {
      //OUTPUT_B(0b00000000);
      //OUTPUT_D(0xff);
       //hienthiall();
     
      ledblynk();
      
    
    }
    else
    {
      output_low(led);
      // delay_ms(1000);
    }
  }
}
void hienthiall()
{

  OUTPUT_D(0xBF);
  OUTPUT_B(0b00010000);
  delay_ms(1);
  OUTPUT_B(0b00000000);

  OUTPUT_D(0x88);
  OUTPUT_B(0b00001000);
  delay_ms(1);
  OUTPUT_B(0b00000000);

  OUTPUT_D(0xC7);
  OUTPUT_B(0b00000100);
  delay_ms(1);
  OUTPUT_B(0b00000100);

  OUTPUT_D(0xC7);
  OUTPUT_B(0b00000010);
  delay_ms(1);
  OUTPUT_B(0b00000010);
}

void hienthisl(int8 value)
{
  unsigned char chuc1, dv1;
  chuc1 = ((value % 1000) % 100) / 10;
  dv1 = ((value % 1000) % 100) % 10;

  OUTPUT_D(mang[chuc1]);
  OUTPUT_B(0b00010000);
  Delay_us(100);
  OUTPUT_B(0X00); //  TAT HET CAC LED, CHONG LEM

  OUTPUT_D(mang[dv1]);
  OUTPUT_B(0b00001000);
  Delay_us(100);
  OUTPUT_B(0X00);
}

void hienthi(int16 uivalue)
{
  unsigned char ngan, tram, chuc, dvi;
  //  ngan=uivalue/1000;
  // tram=(uivalue%1000)/100;
  chuc = ((uivalue % 1000) % 100) / 10;
  dvi = ((uivalue % 1000) % 100) % 10;

  // OUTPUT_D(mang[ngan]);
  //OUTPUT_B(0b00010000);
  //Delay_us(100);
  //OUTPUT_B(0X00);          //  TAT HET CAC LED, CHONG LEM

  //OUTPUT_D(mang[tram]);
  //OUTPUT_B(0b00001000);
  //Delay_us(100);
  //OUTPUT_B(0X00);         //  TAT HET CAC LED, CHONG LEM

  OUTPUT_D(mang[chuc]);
  OUTPUT_B(0b00000100);
  Delay_us(100);
  OUTPUT_B(0X00); //  TAT HET CAC LED, CHONG LEM

  OUTPUT_D(mang[dvi]);
  OUTPUT_B(0b00000010);
  Delay_us(100);
  OUTPUT_B(0X00); //  TAT HET CAC LED, CHONG LEM
}

void ledblynk()
{
  int8 i = 0;
 while (1)
   
 {
 hienthiall();
 
   i++;
    output_high(led);
   if(i/1000==1){
 
   }
  
   
  

  }
}
