#include <16F877a.h>
#device 16f877a*16ADC = 10
#use fast_io(b)
#FUSES NOWDT, HS, PUT, NOPROTECT,
#use DELAY(clock = 20000000)
#use rs232(baud = 9600, xmit = pin_c6, rcv = pin_c7)
#byte intcon = 0x000B
#bit RBIF = intcon .0 //dinh nghia co ngat RB
#bit RBIE = intcon .3 //dinh nghia bit cho phep ngat RB
const char mang[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

#define SH PIN_D3
#define DS PIN_D4
#define ST PIN_D5

#define tb1 PIN_B0
#define tb2 PIN_B1
#define tb3 PIN_B2
#define tb4 PIN_B3
#define btn PIN_B4

// traffic light
#define red PIN_D0
#define yl PIN_D1
#define gr PIN_D2


int8 a, a1, a2, a3, a4, a5 = 0;
int8 value;

int8 nData;
void autoo();
void manul();
void send();
void khoitao(void);
void dich_byte(int8 nData);
void chot_byte(int8 nData);
void OnLow2High(void);
void ghi_byte(int8 nData);

void red1();
void yl1();
void gr1();
void read_btn();
void traffic();
void delay_r(int8 a);
void delay_g(int8 b);
void delay_y(int8 c);
 char d1 ;
#int_RB
void ngat_RB()
{

  if ((RBIF) && (RBIE))
  {
    //Kiem tra sw1

    {
      if (input(btn) == 0)
      {
        output_high(tb1);
        output_high(tb2);
        output_high(tb3);
        output_high(tb4);
        a++;
        a1++;
        
       // printf("a");
        while (input(btn) == 0);
      }
      if (a == 2)
      {
        output_low(tb1);
        output_low(tb2);
        output_low(tb3);
        output_low(tb4);
        a = 0;
       // printf("o");
      }
    
    }
  }
    
}

//

#INT_RDA
void ngat_uart()
{
if(kbhit()){
output_high(PIN_B5);       
 }  
d1 = getc();
  switch (d1)
  {
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
  
 
  
}


void docADC() // khai bao adc
{
  setup_ADC(ADC_clock_internal);
  setup_ADC_ports(AN0);
  set_ADC_channel(0);
  delay_us(100);
}

void main()
{
  enable_interrupts(GLOBAL);
  enable_interrupts(INT_RDA);
  enable_interrupts(global);
  enable_interrupts(int_RB);
  ext_int_edge(H_to_L);
  SET_TRIS_B(0b00010000);
  SET_TRIS_D(0x00);
  output_b(0b11110000);
  output_d(0x00);
  docADC();
  output_low(PIN_B5);
  output_low(PIN_B6);

  khoitao();
  ghi_byte(0x90);
  Delay_ms(200);
  ghi_byte(0xC0);
  Delay_ms(200);
  nData = 0;

  while (true)
  {

autoo();
  if(d1=='j'){
  traffic();
  }
   if(d1=='f'){
  autoo();
  }
   

  
//!   if(d2=='m'){
//!      if(d2=='r'){
//!          output_high(red);
//!      }
//!      if(d2=='y'){
//!          output_high(yl);
//!      }
//!       if(d2=='g'){
//!          output_high(gr);
//!      }
//!      }
  

  //

  }
 

    
  
}

void red1()
{

  output_high(red);
  output_low(yl);
  output_low(gr);
}
void yl1()
{

  output_high(yl);
  output_low(red);
  output_low(gr);
}
void gr1()
{
  output_high(gr);
  output_low(yl);
  output_low(red);
}

void read_btn()
{
  if (input(btn) == 0)
  {
    output_high(tb1);
    output_high(tb2);
    output_high(tb3);
    output_high(tb4);
    a++;
    a1++;
    putc('a');
    while (input(btn) == 0)
      ;
  }
  if (a == 2)
  {
    output_low(tb1);
    output_low(tb2);
    output_low(tb3);
    output_low(tb4);
    a = 0;
    putc('o');
  }

  if (a1 == 3)
  {

    if (value >= 70)
    {
      output_high(tb1);
      output_high(tb2);
      output_high(tb3);
      output_high(tb4);
    }
    if (value <= 25)
    {
      output_low(tb1);
      output_low(tb2);
      output_low(tb3);
      output_low(tb4);
    }
  
  }
}

void delay_r(int8 a)
{
  for (a; a >= 0; a--)
  {
  // send();
    int a1 = (a) % 10;
    int b1 = (a) / 10;
    ghi_byte(mang[a1]);
    ghi_byte(mang[b1]);

    //!    ghi_byte1(mang[c]);
    //!    ghi_byte1(mang[v]);
    putc(a + 48);

    delay_ms(1000);
    if (a == 0)
    {
      putc('g');
      break;
    }
  }
}

void delay_g(int8 b)
{
  for (b; b >= 0; b--)
  {
    //putc('g');
     //send();
    int a1 = (b) % 10;
    int b1 = (b) / 10;
    ghi_byte(mang[a1]);
    ghi_byte(mang[b1]);
    putc(b + 48);
    delay_ms(1000);
    if (b == 0)
    {
      putc('y');
      break;
    }
  }
}

void delay_y(int8 c)
{
  for (c; c >= 0; c--)
  {
    //putc('y');
     //send();
    int a1 = (c) % 10;
    int b1 = (c) / 10;
    ghi_byte(mang[a1]);
    ghi_byte(mang[b1]);
    putc(c + 48);
    delay_ms(1000);
    if (c == 0)
    {
      putc('r');
      break;
    }
  }
}

void traffic()
{
   //send();
  red1();
  delay_r(2);

  gr1();

  delay_g(2);

  yl1();

  delay_y(1);
}

///
void khoitao(void)
{
  output_low(SH);
  output_low(DS);
  output_low(ST);
}

void dich_byte(int8 nData)
{
  int8 i, nMask;
  nMask = 0x80;

  for (i = 0; i < 8; i++)
  {
    output_low(SH);

    if (nData & nMask)
      output_high(DS); //DS=1
    else
      output_low(DS); // DS=0

    output_high(SH);
    Delay_us(1);
    output_low(SH);

    nMask = nMask >> 1;
  }
}

void ghi_byte(int8 nData)
{
  output_low(ST);
  dich_byte(nData);
  output_high(ST);
}

void send(){
value = read_adc()+48;
//printf ("%u",value);
if (value<100){
  output_high(tb1);
  output_high(tb2);
  output_high(tb3);
  output_high(tb4);
  output_low(PIN_B6);
}
else{
output_high(PIN_B6);
output_low(tb1);
output_low(tb2);
output_low(tb3);
output_low(tb4);
}

}

void autoo(){
value = read_adc()+48;
//printf ("%u",value);
if (value>120){
  output_high(tb1);
  output_high(tb2);
  output_high(tb3);
  output_high(tb4);
  output_low(PIN_B6);
   output_high(yl);
    delay_ms(500);
    output_low(yl);
    delay_ms(500);
 
}

else{
output_high(PIN_B6);
output_low(tb1);
output_low(tb2);
output_low(tb3);
output_low(tb4);
traffic();
}


}

