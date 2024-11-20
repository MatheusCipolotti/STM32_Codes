#include "stm32f030x6.h"

#include "EUSART.h"
#include "delay.h"
#include "configs.h"

int main(){
	OscInit();								//Configura o microcontrolador para funcionar em 8MHz
	EUSART1_Init(9600);							//Configura a UART com BaudRate em 9600

	while(1){
		char uart_rx = EUSART1_Read();

		if(uart_rx != 0x00){
			EUSART1_Write_Text_ln("RECEBIDO:");
			EUSART1_Write_ln(uart_rx);

			uart_rx = 0x00;
		}
	}
}

