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
   
   while (true) {
      output_bit(Pin_C0,bit_test(PortA,0));
      output_bit(Pin_C1,bit_test(PortA,1));
      output_bit(Pin_C2,bit_test(PortA,2));
      output_bit(Pin_C3,bit_test(PortA,3));      
   }
   
   return 0;
   
}
