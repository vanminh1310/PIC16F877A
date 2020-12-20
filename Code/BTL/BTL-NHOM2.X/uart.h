/* 
 * File:   uart.h
 * Author: taminh
 *
 * Created on December 3, 2020, 2:28 PM
 */


#define Thachanh 11059200

char uart_init(const long int baudrate) // toc ?? truyen

{
	unsigned int x;
	x = (Thachanh - baudrate*64)/(baudrate*64);
	if(x>255)
	{
		x = (Thachanh - baudrate*16)/(baudrate*16);
		BRGH = 1; // toc do truyen cao
	}
	if(x<256)
	{
	  SPBRG = x;
	  SYNC = 0; // mode chon bit / che do khong dong bo
	  SPEN = 1; // che do  dong bo
          TRISC7 = 1;
          TRISC6 = 1;
          CREN = 1; // cho phep nhan du lieu lien tuc 
          TXEN = 1; //  kich hoat bit truyen 
	  return 1;
	}
	return 0;
}
void UART_Write(char data)
{
  while(!TRMT);
  TXREG = data;
}

void uart_write(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}

char UART_Read()
{
 
  while(!RCIF);
  return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length)
{
	unsigned int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}