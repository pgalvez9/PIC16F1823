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
   int8 i = 0;
   set_tris_A(1);
   set_tris_C(0);
   PortA = 1;
   PortC = 0;
   delay_ms(100);
   bit_clear(PortC,0);
   bit_clear(PortC,1);
   bit_clear(PortC,2);
   bit_clear(PortC,3);
   
   for(;;) {
   
      if(!bit_test(PortA,0)){
         if(bit_test(PortA,2)){
            for(i=4; i>0; i--) {
               bit_clear(PortC,i-4);
               bit_clear(PortC,i);
               bit_set(PortC,i-1);
               delay_ms(100);
            }
         }
         else {
            for(i=0; i<4; i++){
               bit_clear(PortC,i-1);
               bit_clear(PortC,i+2);
               bit_set(PortC,i);
               delay_ms(100);
            }
         }
      }
      else {
         bit_clear(PortC,0);
         bit_clear(PortC,1);
         bit_clear(PortC,2);
         bit_clear(PortC,3);
      }
      
   }
   return 0;
}
