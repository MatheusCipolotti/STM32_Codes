#include "stm32f030x6.h"
#include "PWM.h"

void PWM_TIM1_Config(void){
	//Ativa clock para TIM1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//Configura prescaler para definir a frequência do temporizador
	TIM1->PSC = 7; 												//Prescaler para dividir o clock

	//Configura o ARR (Auto-Reload Register) para definir a frequência do PWM
	TIM1->ARR = 999; 											//Define o período (PWM de 1kHz por exemplo)

	//Configura cada canal para modo PWM1
	//Canal 1
	TIM1->CCMR1 &= ~(TIM_CCMR1_OC1M_Msk);
	TIM1->CCMR1 |= (0b110 << TIM_CCMR1_OC1M_Pos) | TIM_CCMR1_OC1PE;

	//Canal 2
	TIM1->CCMR1 &= ~(TIM_CCMR1_OC2M_Msk);
	TIM1->CCMR1 |= (0b110 << TIM_CCMR1_OC2M_Pos) | TIM_CCMR1_OC2PE;

	//Canal 3
	TIM1->CCMR2 &= ~(TIM_CCMR2_OC3M_Msk);
	TIM1->CCMR2 |= (0b110 << TIM_CCMR2_OC3M_Pos) | TIM_CCMR2_OC3PE;

	//Ativa as saídas PWM
	TIM1->CCER |= TIM_CCER_CC1E;   										//Habilita CH1
	TIM1->CCER |= TIM_CCER_CC1NE;  										//Habilita CH1N
	TIM1->CCER |= TIM_CCER_CC2E;										//Habilita CH2
	TIM1->CCER |= TIM_CCER_CC2NE;										//Habilita CH2N
	TIM1->CCER |= TIM_CCER_CC3E;										//Habilita CH3
	TIM1->CCER |= TIM_CCER_CC3NE;										//Habilita CH3N

	//Configura valor de comparação (duty cycle)
	TIM1->CCR1 = 500; 											//Duty cycle 50% para CH1
	TIM1->CCR2 = 500; 											//Duty cycle 50% para CH2
	TIM1->CCR3 = 500; 											//Duty cycle 50% para CH3

	//Ativa o contador e a saída principal
	TIM1->BDTR |= TIM_BDTR_MOE;    										//Ativa as saídas principais
	TIM1->CR1 |= TIM_CR1_CEN;      										//Ativa o contador
}
