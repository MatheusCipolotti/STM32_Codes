#include "stm32f030x6.h"
#include "PWM.h"

void PWM_TIM1_Config(void){
	//Ativa clock para TIM1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//Configura prescaler para definir a frequência do temporizador
	TIM1->PSC = 7999; 													//Prescaler para dividir o clock

	//Configura o ARR (Auto-Reload Register) para definir a frequência do PWM
	TIM1->ARR = 1000; 													//Define o período (PWM de 1kHz por exemplo)

	//Configura o CH1 em modo PWM1
	TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M_Msk); // Limpar bits OC1M
	TIM1->CCMR1 |= (0b110 << TIM_CCMR1_OC1M_Pos) | TIM_CCMR1_OC1PE;  	//PWM no CH1

	//Ativa saída do canal 1 (CH1)
	TIM1->CCER |= TIM_CCER_CC1E;   										//Habilita CH1

	//Configura valor de comparação (duty cycle)
	TIM1->CCR1 = 500; 													//Duty cycle 50% para CH1

	//Ativa o contador e a saída principal
	TIM1->BDTR |= TIM_BDTR_MOE;    // Ativar saídas principais
	TIM1->CR1 |= TIM_CR1_CEN;      // Ativar contador
}
