#include "stm32f030x6.h"

#include "EUSART.h"
#include "delay.h"
#include "configs.h"
#include "defines.h"
#include "SPI.h"

uint8_t uart_rd = 0, receive = 0;
uint16_t mili_seconds_counter = 0;

void EXTI0_1_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) {
    	Delay_ms(100);
        EXTI->PR |= EXTI_PR_PR0;  // Limpa flag da interrupção EXTI0

    	LOW_MEMORIA();
    	Delay_ms(1);
    	HIGH_MEMORIA();
    	LOW_MOSTRA();

        uart_rd = SPI1_Read(); // Função que faz a leitura via SPI
        HIGH_MOSTRA();
        EUSART1_Write_ln(uart_rd);
    }
}

void USART1_IRQHandler(void){
	if((USART1->ISR & USART_ISR_RXNE)){
		uart_rd = USART1->RDR;
		receive = 1;
	}
}

void TIM3_IRQHandler(void){
	if (TIM3->SR & TIM_SR_UIF){ 								// Verifica o flag de atualização (overflow)
		TIM3->SR &= ~TIM_SR_UIF; 								// Limpa o flag

		mili_seconds_counter++;
		if(mili_seconds_counter == 1000){
			mili_seconds_counter = 0;
			TOGGLE_LED_ON_BOARD();								//LED ON BOARD Keep Alive
		}
	}
}

int main(void){
	OscInit();													//Configura o microcontrolador para funcionar em 8MHz
	EUSART1_Init(BAUDRATE);										//Configura a UART com BaudRate em 9600
	SPI1_Init();
	GPIO_Init();
	TIM3_Init();
	EXTI_Config();

	// Habilita interrupções globais
	__enable_irq();

	HIGH_MEMORIA();
	HIGH_MOSTRA();

	while(1){

	}
}
