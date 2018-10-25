#include <16F1823.H>
#use fast_IO(A)
#use fast_IO(C)
#fuses PUT, NOWDT, NOMCLR

#use delay(int = 32 MHz)
#BYTE TrisA = 0x08c
#BYTE TrisC = 0x08e
#byte PortA = 0x00c
#BYTE PortC = 0x00e

   /*
      bit_set(Port,x)
      bit_clear(Port,x)
      bit_test(Port,x)
   */ 

int main(void) {

   set_tris_A(1);
   set_tris_C(0);
   PortA = 1;
   PortC = 0;
   delay_ms(100);
   
   for(;;) {
   
      if(bit_test(PortA,0)){
         bit_clear(PortC,0);
      }
      else {
         bit_set(PortC,0);
      }
      
   }
   return 0;
}