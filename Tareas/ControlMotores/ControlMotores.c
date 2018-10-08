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

// Pseudo interrupcion por software
boolean i_ant = False, j_ant = False, k_ant = False;
boolean motorSelector = false;   // false - DC motor, true - BiStepper Motor 
boolean Sentido = false;   // false - izq, true - der
boolean intensidad = false;  // Define la intensidad del giro

int DC() {
   if(motorSelector == False) {
      bit_clear(PortC,2);
      bit_clear(PortC,3);
      if(Sentido) {
         bit_clear(PortC,1);
         bit_set(PortC,0);
      }
      else {
         bit_clear(PortC,0);
         bit_set(PortC,1);
      }
   }

   return 0;
}

int BiStr() {
   int u;
   if(motorSelector == True) {
      bit_clear(PortC,0);
      bit_clear(PortC,1);
      if(Sentido == False) {
         for(u = 0; u < 4; u++) {
            bit_set(PortC,u+2);
            bit_clear(PortC,u+1);
         }
      }
      else {
         for(u = 4; u > 0; u--) {
            bit_set(PortC,u+1);
            bit_clear(PortC,u+2);
         }
      }
   }
   
   return 0;
}

int main(void) {
// Se definen los puertos como entradas o salidas
   set_tris_C(0);
   set_tris_A(1);
   PortA = 1;
   PortC = 0;
   bit_set(PortC,0);
   
   for(;;) {
      if(bit_test(PortA,0) == True && i_ant == False) {
         motorSelector = !motorSelector;
      }
      if(bit_test(PortA,1) == True && j_ant == False) {
         Sentido = !Sentido;
      }
      if(bit_test(PortA,2) == True && k_ant == False) {
         intensidad = !intensidad;
      }      
      i_ant = bit_test(PortA,0);
      j_ant = bit_test(PortA,1);
      k_ant = bit_test(PortA,2);
      DC();
      BiStr();
   }   
   return (0);
}
