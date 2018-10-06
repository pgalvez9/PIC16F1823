#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR

// NOWDT - 
// PUT - Power UpTime
// NOMCLR - No Master Clear : Libera el puerto A3 de ser RESET y se le puede usar como cualquier otro PIN

#use fast_io(C)
#use delay(int = 32 000 000)

int main (void) {
   set_tris_C(0);
   
   for (;;) {
   output_high(pin_c0);
   delay_ms(100);
   output_low(pin_c0);
   delay_ms(100);
   }

   return (0);
}
