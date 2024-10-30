#include "stm32f030x6.h"
#include "delay.h"

void Delay_ms(int Vezes){
	//Clock do sistema seja 8MHz
	int clock_freq = 8000000 / 8; 								//Frequência após o prescaler (1:8)
	int Ticks = (clock_freq / 1000) * Vezes; 					//Calcula ticks para milissegundos

	if (Ticks > 0xFFFFFF) Ticks = 0xFFFFFF;  					//Limita ao valor máximo de 24 bits

	SysTick->LOAD = Ticks - 1;               					//Carrega o valor de Ticks
	SysTick->VAL = 0;                        					//Limpa o valor atual do contador
	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk; 					//Habilita o SysTick

	//Espera o tempo terminar
	while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

	SysTick->CTRL = 0; 											//Desabilita o SysTick
}
