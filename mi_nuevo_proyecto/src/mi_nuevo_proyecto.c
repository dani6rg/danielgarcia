#include "mi_nuevo_proyecto.h"       /* <= own header */
#include "led.h"
#include "teclas.h"
#include "rti_daniel.h"

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


void Timer_IRQ(void)
{
	Led_invierte(LED_B);
	Borra_interrupcion_timer();
}


int main(void)
{
	Puerto_inicia();
	Led_inicia();
	InicializarTeclas();
    timer_interrupcion(250);

while(1){

     //sin tocar el pulsador leer_tecla()-->0
	if( !LeerTecla(1) )
	{
		Led_bajo(LED_3);
	}
	else{
		Led_alto(LED_3);
	}


}
return 0;
}
