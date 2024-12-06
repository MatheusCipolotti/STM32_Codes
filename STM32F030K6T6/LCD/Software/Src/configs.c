#include "stm32f030x6.h"
#include "configs.h"

void Osc_Init(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 							//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 		//Espera até o HSE ser selecionado
}

void GPIO(void){
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Configura PB0, PB1, PB3, PB7 como saída (modo geral push-pull)
	GPIOB->MODER &= ~(GPIO_MODER_MODER0 | GPIO_MODER_MODER1 | GPIO_MODER_MODER3 | GPIO_MODER_MODER7);
	GPIOB->MODER |= (GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER3_0 | GPIO_MODER_MODER7_0);

	//Configura PB4 (RS) e PB5 (EN) como saída
	GPIOB->MODER &= ~(GPIO_MODER_MODER4 | GPIO_MODER_MODER5);
	GPIOB->MODER |= (GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0);

	//Configura os pinos como push-pull com velocidade baixa
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_0 | GPIO_OTYPER_OT_1 | GPIO_OTYPER_OT_3 | GPIO_OTYPER_OT_7 |
	             	 GPIO_OTYPER_OT_4 | GPIO_OTYPER_OT_5);
	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR3 |
	                 GPIO_OSPEEDER_OSPEEDR7 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5);

	//Desabilita pull-up/pull-down nos pinos
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR0 | GPIO_PUPDR_PUPDR1 | GPIO_PUPDR_PUPDR3 | GPIO_PUPDR_PUPDR7 |
	                 GPIO_PUPDR_PUPDR4 | GPIO_PUPDR_PUPDR5);
}
