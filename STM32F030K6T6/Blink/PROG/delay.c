#include "stm32f030x6.h"
#include "delay.h"

void Delay_ms(int Vezes){
	int Ticks = Vezes;									//Variável

	//Sistema possui um preescaler de 1:8
	Ticks *= 1000;											//Calcula o tempo com base em ms (multiplica por 1000)
	SysTick ->LOAD = Ticks;									//Carrega o valor de Ticks;
	SysTick ->CTRL = SysTick_CTRL_ENABLE_Msk;				//Habilita o systick

	while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));	//Espera o tempo
	SysTick->CTRL = 0;										//Limpa o registrador inteiro
}
