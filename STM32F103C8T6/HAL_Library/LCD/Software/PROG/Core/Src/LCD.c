#include <stdint.h>
#include "defines.h"
#include "LCD.h"
#include "stm32f1xx_hal.h"

//Função para enviar comandos ao LCD
void LCD_Send_Command(uint8_t cmd){

	//Envia os 4 bits mais significativos
	HAL_GPIO_WritePin(LCD_PORT, D4_PIN, (cmd >> 4) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D5_PIN, (cmd >> 5) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D6_PIN, (cmd >> 6) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D7_PIN, (cmd >> 7) & 0x01);

	HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET); 					//RS = 0 para comando
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_SET);						//EN = 1

	HAL_Delay(1); 															//Atraso 1ms
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_RESET);						//EN = 0
	HAL_Delay(1); 															//Atraso 1ms

	// Envia os 4 bits menos significativos
	HAL_GPIO_WritePin(LCD_PORT, D4_PIN, (cmd >> 0) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D5_PIN, (cmd >> 1) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D6_PIN, (cmd >> 2) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D7_PIN, (cmd >> 3) & 0x01);

	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_SET);						//EN = 1
	HAL_Delay(1); 															//Atraso 1ms
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_RESET);						//EN = 0
	HAL_Delay(3); 															//Atraso 3ms
}

//Função para inicializar o LCD
void LCD_Init(void){
	HAL_Delay(40); 															//Atraso 40ms
	LCD_Send_Command(0x02);													//Configura o LCD para modo de 4 bits.
	LCD_Send_Command(0x28);													//Configura o LCD para 2 linhas e matriz de 5x8 pontos.
	LCD_Send_Command(0x01);													//Limpa o display
	LCD_Send_Command(0x0C);													//Liga o display e desliga o cursor.
	LCD_Send_Command(0x06);													//Configura o incremento automático do cursor.
}

void LCD_Char(char dat){
	//Envia os 4 bits mais significativos
	HAL_GPIO_WritePin(LCD_PORT, D4_PIN, (dat >> 4) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D5_PIN, (dat >> 5) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D6_PIN, (dat >> 6) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D7_PIN, (dat >> 7) & 0x01);

	HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_SET); 						//RS = 1
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_SET);						//EN = 1
	HAL_Delay(1); 															//Atraso 1ms
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_RESET);						//EN = 0
	HAL_Delay(1); 															//Atraso 1ms

	// Envia os 4 bits menos significativos
	HAL_GPIO_WritePin(LCD_PORT, D4_PIN, (dat >> 0) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D5_PIN, (dat >> 1) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D6_PIN, (dat >> 2) & 0x01);
	HAL_GPIO_WritePin(LCD_PORT, D7_PIN, (dat >> 3) & 0x01);

	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_SET);						//EN = 1
	HAL_Delay(1); 															//Atraso 1ms
	HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_RESET);						//EN = 0
	HAL_Delay(3); 															//Atraso 3ms
}

void LCD_Char_xy(char row,char pos, char dat){
	uint8_t location = 0;

	switch(row){
		case 0:
			location = (uint8_t)((0x80) + (pos));
			LCD_Send_Command(location);
			break;

		case 1:
			location = (uint8_t)((0xC0) + (pos));
			LCD_Send_Command(location);
			break;

		case 2:
			location = (uint8_t)((0x94) + (pos));
			LCD_Send_Command(location);
			break;

		case 3:
			location = (uint8_t)((0xD4) + (pos));
			LCD_Send_Command(location);
			break;
	}
	LCD_Char(dat);
}

void LCD_String(const char *msg){
	while((*msg)!=0){
		LCD_Char(*msg);
	    msg++;
	}
}

void LCD_String_xy(char row,char pos,const char *msg){
	uint8_t location = 0;

	switch(row){
		case 0:
			location = (uint8_t)((0x80) + (pos));
			LCD_Send_Command(location);
			break;

		case 1:
			location = (uint8_t)((0xC0) + (pos));
			LCD_Send_Command(location);
			break;

		case 2:
			location = (uint8_t)((0x94) + (pos));
			LCD_Send_Command(location);
			break;

		case 3:
			location = (uint8_t)((0xD4) + (pos));
			LCD_Send_Command(location);
			break;
	}
	LCD_String(msg);
}

void LCD_Clear(){
	LCD_Send_Command(0x01);													//Limpa o display
	HAL_Delay(3);															//Atraso 3ms
}
