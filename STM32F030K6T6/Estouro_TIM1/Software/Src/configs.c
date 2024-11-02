#include "stm32f030x6.h"
#include "configs.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 	//Espera até o HSE ser selecionado
}

void GPIO(void){
	//Ativa o clock para o GPIOB
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  						//Limpar bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   						//Setar bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_0;
}

void TIM1_Init(void){
	//Habilita o clock para TIM1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//Configura o prescaler e o valor de auto-reload
	TIM1->PSC = 7999;       									//Prescaler para reduzir a frequência (ex.: 8MHz/8000 = 1kHz)
	TIM1->ARR = 1000 - 1;   									//Valor de Auto-reload para estourar a cada 1 segundo (1 kHz / 1000)

	//Habilita a interrupção de atualização (overflow)
	TIM1->DIER |= TIM_DIER_UIE;

	//Habilita o TIM1
	TIM1->CR1 |= TIM_CR1_CEN;

	//Configura a interrupção do TIM1 no NVIC
	NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
}
