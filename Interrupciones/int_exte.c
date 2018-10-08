#include <16f1823.h>
#fuses  PUT, NOWDT
#use delay(int=8000000)
#use standard_io(C)
#use standard_io(A)

#INT_EXT
void ext()
{
 output_toggle(pin_c0);  
}

void main()
{ 
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   while(1)
   {
   
   }
}
