#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR //No watch dog timer, power up timer, no master clear
#use delay(int=32MHZ)   
#use RS232(baud=9600,XMIT=pin_c4,RCV=pin_c5)
#use I2C(master,SDA=pin_c1,SCL=pin_c0, FORCE_HW, STREAM=MASTER, fast)//maestro o esclavo,cuál pin es SDA, , forzar a que sea hw
#define slv1_w 0x50 //byte 50 a slv 1
#define slv1_r 0x51 
#define slv2_w 0x60
#define slv2_r 0x61

void main()
{  
   int b1=0;
   int b2=0; 
   char s1= 'b';
   int s2=0;
   while(true)
   {
      I2C_START();//Iniciar comunicación
      delay_ms(100);
      b1=I2C_WRITE(0x61);
      printf("%u",b1);
      delay_ms(100);
      s1=I2C_READ(0);
      delay_ms(100);
      I2C_STOP();
      printf("Dato: %c \r",s1);
      delay_ms(100);
   }
   
}
