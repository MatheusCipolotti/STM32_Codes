#include "stm32f030x6.h"

#include "EUSART.h"
#include "delay.h"
#include "configs.h"

unsigned char uart_rd = 0x00;

int main(){
	OscInit();											//Configura o microcontrolador para funcionar em 8MHz
	GPIO();
	EUSART1_Init(9600);									//Configura a UART com BaudRate em 9600

	while(1){
		GPIOB->ODR |= GPIO_ODR_0;  						//Seta PB0 em 1
		EUSART1_Write_Text_ln("TESTE - BOARDLED = 1");
		Delay_ms(500);
		GPIOB->ODR &= ~GPIO_ODR_0;  					//Seta PB0 em 0
		EUSART1_Write_Text_ln("TESTE - BOARDLED = 0");
		Delay_ms(500);
	}
}
