#include <16F1823.h>
#fuses PUT, NOWDT

#use delay(int=32Mhz)
#use standard_io(A)
void main()
{
   Output_toggle(Pin_A0);
   delay_ms(100);
}
