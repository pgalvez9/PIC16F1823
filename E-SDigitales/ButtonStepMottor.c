#include <16f1823.h>
#fuses PUT, NOWDT

#use delay(int = 32Mhz)
//declaracion de registros c de acuerdo a la datasheet
void s();
#Byte trisa = 0x08c
#byte trisc = 0x08e
#byte porta = 0x00c
#byte portc = 0x00e
void main()
{
   trisa = 1;//todo el puerto A como salida
   trisc = 0;//todo el puerto C como entrada
   portc=0;
   int1 aux = 0;
   
   while(true)
   {
      if(bit_test(porta,0)==1)//si el pin 0 esta encendido
      {
         delay_ms(200);
         aux = !aux;
      }
      if(aux==1)
      {
      s();
      }
   }
}
void s()
{
      portc = 0b001100;
      delay_ms(100);
      portc = 0b001001;
      delay_ms(100);
      portc = 0b000011;
      delay_ms(100);
      portc = 0b000110;
      delay_ms(100);
}
