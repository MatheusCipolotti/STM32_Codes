#include "stm32f030x6.h"
#include "configs.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 			//Espera até o HSE ser selecionado
}

void GPIO(void){
	//Ativa o clock para o GPIOA
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	//Configura o PA7 como saida alternativa para o TIM1_CH1N (AF2)
	GPIOA->MODER &= ~(GPIO_MODER_MODER7);
	GPIOA->MODER |= (GPIO_MODER_MODER7_1); 						//PA7 em modo função alternativa
	GPIOA->AFR[0] |= (0x02 << GPIO_AFRH_AFRH7_Pos); 				//AF2 para PA7

	//Configura o PA8 como saida alternativa para o TIM1_CH1 (AF2)
	GPIOA->MODER &= ~(GPIO_MODER_MODER8);
	GPIOA->MODER |= (GPIO_MODER_MODER8_1); 						//PA8 em modo função alternativa
	GPIOA->AFR[1] |= (0x02 << GPIO_AFRH_AFRH0_Pos); 				//AF2 para PA8

	//Configura o PA9 como saida alternativa para  o TIM1_CH2 (AF2)
	GPIOA->MODER &= ~(GPIO_MODER_MODER9);
	GPIOA->MODER |= (GPIO_MODER_MODER9_1); 						//PA9 em modo função alternativa
	GPIOA->AFR[1] |= (0x02 << GPIO_AFRH_AFRH1_Pos); 				//AF2 para PA9

	//Configura o PA10 como saida alternativa para o TIM1_CH3 (AF2)
	GPIOA->MODER &= ~(GPIO_MODER_MODER10);
	GPIOA->MODER |= (GPIO_MODER_MODER10_1); 					//PA10 em modo função alternativa
	GPIOA->AFR[1] |= (0x02 << GPIO_AFRH_AFRH2_Pos); 				//AF2 para PA10

	//Ativa o clock para o GPIOB
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Configura o PB0 como saida alternativa para o TIM1_CH2N (AF2)
	GPIOB->MODER &= ~(GPIO_MODER_MODER0);
	GPIOB->MODER |= (GPIO_MODER_MODER0_1); 						//PB0 em modo função alternativa
	GPIOB->AFR[0] |= (0x02 << GPIO_AFRH_AFRH0_Pos); 				//AF2 para PB0

	//Configura o PB1 como saida alternativa para o TIM1_CH3N (AF2)
	GPIOB->MODER &= ~(GPIO_MODER_MODER1);
	GPIOB->MODER |= (GPIO_MODER_MODER1_1); 						//PB1 em modo função alternativa
	GPIOB->AFR[0] |= (0x02 << GPIO_AFRH_AFRH1_Pos); 				//AF2 para PB1	
}
