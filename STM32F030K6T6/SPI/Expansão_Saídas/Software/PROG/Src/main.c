#include "stm32f030x6.h"

#include "EUSART.h"
#include "delay.h"
#include "configs.h"
#include "defines.h"
#include "SPI.h"

uint8_t uart_rd = 0, receive = 0;
uint16_t mili_seconds_counter = 0;

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

	// Habilita interrupções globais
	__enable_irq();

	LOW_MEMORIA();
	LOW_MOSTRA();

	while(1){
		if(uart_rd != 0){
			EUSART1_Write_Text_ln("Defina o caractere que deve ser enviado para o 74HC595:");
			do{
				if(receive == 1){
					SPI1_Write(uart_rd);
					LOW_MOSTRA();
					HIGH_MEMORIA();
					Delay_ms(1);
					HIGH_MOSTRA();
					LOW_MEMORIA();
					receive = 0;
					EUSART1_Write_Text_ln("Enviado!");
				}
				else{
					EUSART1_Write_Text_ln("Aguardando caractere ou tecle # para sair!");
					Delay_ms(2000);
				}
			}while(uart_rd != '#');
			uart_rd = 0;
		}
		else{

		}
		/*
		uart_rd = EUSART1_Read();
		SPI1_Write(uart_rd);
		LOW_MOSTRA();
		HIGH_MEMORIA();
		Delay_ms(1);
		HIGH_MOSTRA();
		LOW_MEMORIA();
		*/
	}
}
