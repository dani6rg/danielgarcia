#include "led_parpadea.h"       /* <= own header */
#include "led.h"

int main(void)
{
   Puerto_inicia();
   Led_inicia();

   while(1) {
	  int i=0;
	  for(i=0;i<1000000;i++) {
	     asm("nop");
	  }
	  Led_invierte(LED_1);
   }

   return 0;


}
