
/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "led.h"
void Puerto_inicia() {
	Chip_GPIO_Init(LPC_GPIO_PORT);
}

void Led_inicia() {
	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4);
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4);

	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0);
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0);
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0);

	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,1<<0,1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,1<<1,1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,1<<2,1);

	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,1<<14,1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,1<<11,1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,1<<12,1);
}
void Led_defino_puerto(int color,int *port,int *pin) {
	switch(color)
	{
		case LED_1:
			*port = 0;
			*pin  = 14;
			break;
		case LED_2:
			*port = 1;
			*pin = 11;
			break;
		case LED_3:
			*port = 1;
			*pin = 12;
			break;
		case LED_R:
			*port = 5;
			*pin = 0;
			break;
		case LED_G:
			*port = 5;
			*pin = 1;
			break;
		case LED_B:
			*port = 5;
			*pin = 2;
			break;

		default:
			*port = 1;
			*pin = 12;
			break;
	}
}
void Led_invierte(int color) {
	int port,pin;
	Led_defino_puerto(color,&port,&pin);
	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,port,pin);
}
void Led_alto(int color) {
	int port,pin;
	Led_defino_puerto(color,&port,&pin);
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,port,pin);
}
void Led_bajo(int color) {
	int port,pin;
	Led_defino_puerto(color,&port,&pin);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,port,pin);
}

