#include "interrupcion_led.h"
#include "led.h"
#include "teclas.h"
#include "rti_daniel.h"

int secuencia[]={LED_B,LED_1,LED_2,LED_3};
int main(void)
{
	Puerto_inicia();
	Led_inicia();
	InicializarTeclas();
	timer_interrupcion(250);

   while(1) {
   }
   return 0;
}

void Timer_IRQ(void) {
	int led = 0;
	int direccion = 1;

	//if(EscanearTeclado()==1) direccion = 1;
	//if(EscanearTeclado()==2) direccion = -1;

	Led_bajo(secuencia[led]);

	led+=direccion;
	if(led>3) led=0;
	if(led<0) led=3;

	Led_alto(secuencia[led]);
	Borra_interrupcion_timer();
}

