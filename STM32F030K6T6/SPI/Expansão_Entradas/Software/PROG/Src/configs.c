#include "stm32f030x6.h"

#include "configs.h"
#include "defines.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 	//Espera até o HSE ser selecionado
}

void GPIO_Init(void){
	//Habilita o clock para o GPIOB (Bit 18 do RCC_AHBENR)
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//===================================PB0========================================
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_0;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR0_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR0_1 | GPIO_OSPEEDR_OSPEEDR0_0);

	//===================================PB5========================================
	//Configura o pino PB5 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER5;  						//Limpa bits 0 e 1 para PB5
	GPIOB->MODER |= GPIO_MODER_MODER5_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_5;

	//Define o valor de PB5 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR5_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR5_1 | GPIO_OSPEEDR_OSPEEDR5_0);

	//===================================PB6========================================
	//Configura o pino PB6 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER6;  						//Limpa bits 0 e 1 para PB6
	GPIOB->MODER |= GPIO_MODER_MODER6_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_6;

	//Define o valor de PB6 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR6_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR6_1 | GPIO_OSPEEDR_OSPEEDR6_0);
}

void TIM3_Init(void){
	// Habilita o clock do Timer 3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Configuração do Timer 3
	TIM3->PSC = 7;  												// Prescaler: 8MHz/8 = 1MHz
	TIM3->ARR = 999;   												// Auto-reload: overflow a cada 1000 contagens (1kHz = 1ms)

	// Configuração do modo de interrupção por estouro
	TIM3->DIER |= TIM_DIER_UIE;  									// Habilita a interrupção de estouro do timer

	//Habilita o Timer 3
	TIM3->CR1 |= TIM_CR1_CEN;

	NVIC_EnableIRQ(TIM3_IRQn);      								// Habilita a interrupção do TIM3 no NVIC
	NVIC_SetPriority(TIM3_IRQn, 2); 								// Define a prioridade (um valor entre 0 e 3, onde 0 é a mais alta)
}

void EXTI_Config(void){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;  							// Ativa clock GPIOA
    GPIOA->MODER &= ~(3 << (0 * 2));    							// PA0 como entrada

    // Configura PA0 como EXTI0
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;  					// EXTI0 mapeado para PA0
    EXTI->IMR |= EXTI_IMR_IM0;          							// Desmascara EXTI0
    EXTI->RTSR |= EXTI_RTSR_TR0;                					// Rising edge enable
    EXTI->FTSR &= ~EXTI_FTSR_TR0;               					// Falling edge disable

    NVIC_EnableIRQ(EXTI0_1_IRQn);       							// Habilita interrupção EXTI0/1 no NVIC
}
