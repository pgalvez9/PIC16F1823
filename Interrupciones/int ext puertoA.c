#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay(int=32000000)

#INT_RA
void interrupcion()
{
   if(input(pin_a0)==1)
   {
   output_toggle(pin_c1);
   }
   if(input(pin_a1)==1)
   {
   output_toggle(pin_c2);
   }
   
}

void main()
{
   enable_interrupts(INT_RA0);
   enable_interrupts(INT_RA1);
   enable_interrupts(GLOBAL);
   while(1)
   {  
      output_toggle(pin_c0);
      delay_ms(100);
   }
}

