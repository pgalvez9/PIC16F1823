/*
   Código fuente para Maestro de I2C
*/
#include <16F1823.h>

#fuses NOWDT, NOMCLR, PUT
#use delay (int = 32 MHz)
#use RS232(baud = 9600, XMIT = pin_c4, RCV = pin_c5)
#use I2C(Master, SDA = pin_c1, SCL = pin_c0, FORCE_HW, STREAM = Master) // Maestro-esclavo
#define slv1_w 0x50  //byte 50 a slv1 : escribir
#define slv1_r 0x51  //byte 51 a slv1 : leer
#define slv2_w 0x60  //byte 60 a slv2 : escribir
#define slv2_r 0x61  //byte 61 a slv2 : leer

//Las direcciones 0xnn no deben exceder 7 bits (128 direcciones disponibles)
int b1 = 0, b2 = 0;
char s1 = 0, s2 = 0;


int main(void) {
   while(true) {
      I2C_start(Master);   // Iniciar stream-comunicacion
      b1 = I2C_WRITE(Master, slv1_r);  // Master escribirá a partir de la lectura de slv1
      delay_ms(100);
      s1 = I2C_READ(slv1_r);        // Si se pone 1 aún espera datos, con 0 la lectura está terminada
      delay_ms(100);
      I2C_STOP(Master);
      printf("Dato: %c", s1);
   }

   return 0;
}
