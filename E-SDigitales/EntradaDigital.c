#include <16f1823.h>
#fuses PUT, NOWDT

#use delay(int = 32Mhz)
//declaracion de registros c de acuerdo a la datasheet

#Byte trisa = 0x08c
#byte trisc = 0x08e
#byte porta = 0x00c
#byte portc = 0x00e
void main()
{
   trisa = 0;//todo el puerto A como salida
   trisc = 1;//todo el puerto C como entrada
   porta=0;
   while(true)
   {
      if(bit_test(portc,0)==1)//si el pin 0 esta encendido
      {
         bit_set(porta,0);//en alto puerto A pin 0
      }
      else
      {
         bit_clear(porta,0);//en bajo puerto A pin 0
      }
   }
}
