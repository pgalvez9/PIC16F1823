#include <16f1823.h>
#fuses  PUT, NOWDT

#use delay(int = 32Mhz)
#BYTE trisa = 0x08c
#BYTE trisc = 0x08e
#BYTE porta = 0x00c
#BYTE portc = 0x00e

void main()
{
trisa = 0;
trisc = 0;
   while(1)
   {  portc = 0;
      porta = 1;
      delay_ms(500);
      while(porta!=32)
      {
         if(porta==4)
         {
         porta = 16;
         }
         else
         {
         porta <<= 1;
         }
      delay_ms(500);
      }

      porta = 0;
      portc = 1;
      delay_ms(500);
      while(portc!=32)
      {
        portc <<= 1;
        delay_ms(500);
      }
         porta = 0;
   portc = 32;
   delay_ms(500);
      while(portc!=0)
      {
        portc >>= 1;
        delay_ms(500);
      }
   
      portc = 0;
      porta = 32;
      delay_ms(500);
      while(porta!=0)
      {
         if(porta==16)
         {
         porta = 4;
         }
         else{
         porta >>= 1;
         }
        delay_ms(500);
      }
   }
   

}

