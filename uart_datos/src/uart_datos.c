#include "uart_datos.h"       /* <= own header */
#include "led.h"
#include "teclas.h"
#include "uart.h"
#include "rti_daniel.h"
#include "adc.h"


unsigned char cadena[]="Hola Mundo\r\n\0";
int main(void)
{
Puerto_inicia();
Led_inicia();
InicializarTeclas();
UART_Init();
ADC_Init();

int tecla;
int old_tecla=0;
while(1) {
  tecla = EscanearTeclado();

  if(tecla!=old_tecla) {
  switch(tecla) {
	case 1:
			Led_invierte(LED_1);
			EnviarCadena();
			break;
			    }

  old_tecla=tecla;
  }

}
return 0;
}
void EnviarCadena() {
	int caracter=0;
	while(cadena[caracter]!=0) {
		UART_Send(cadena[caracter++]);
	}
}







void Timer_IRQ(void) {
	Borra_interrupcion_timer();
}

void ADC0_IRQ(void) {

}

