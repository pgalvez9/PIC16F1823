#include <16F1823.H>
#fuses PUT, NOWDT, NOMCLR
#use fast_IO(A)
#use fast_IO(C)

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


/*
 *
 * Este .HEX se encargará de recibir las señales de los botones
 * y transmitirlas a los actuadores
 *
*/
int main(void) {

   set_tris_A(0x0f);
   set_tris_C(0x00);
   PortA = 1;
   PortC = 0;
   delay_ms(100);
   
   bit_clear(PortC,0);
   bit_clear(PortC,1);
   bit_clear(PortC,3);
   
   for(;;) {
      if(bit_test(PortA,0)) {
         bit_set(PortC,0);
      }
      else {
         bit_clear(PortC,0);
      }
      if(bit_test(PortA,1)) {
         bit_set(PortC,1);
         bit_clear(PortC,3);
      }
      else {
         bit_clear(PortC,1);
         bit_set(PortC,3);
      }
      if(bit_test(PortA,2)) {
         bit_set(PortC,2);
      }
      else {
         bit_clear(PortC,2);
      }
      
   }
   
   return 0;
}
