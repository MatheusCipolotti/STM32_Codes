#include "stm32f030x6.h"

#include "defines.h"
#include "delay.h"
#include "LCD.h"

void LCD_Command(unsigned char cmd){
	 //Envia nibble alto
	 GPIOB->ODR = (GPIOB->ODR & ~(GPIO_ODR_0 | GPIO_ODR_1 | GPIO_ODR_3 | GPIO_ODR_7)) |
			(((cmd >> 4) & 0x01) << 0) | (((cmd >> 5) & 0x01) << 1) | 
		 	(((cmd >> 6) & 0x01) << 7) | (((cmd >> 7) & 0x01) << 3);

	 RS_LOW();
	 E_HIGH();
	 Delay_ms(1);
	 E_LOW();
	 Delay_ms(1);

	 //Envia nibble baixo
	 GPIOB->ODR = (GPIOB->ODR & ~(GPIO_ODR_0 | GPIO_ODR_1 | GPIO_ODR_3 | GPIO_ODR_7)) |
			(((cmd >> 0) & 0x01) << 0) | (((cmd >> 1) & 0x01) << 1) | 
		 	(((cmd >> 2) & 0x01) << 7) | (((cmd >> 3) & 0x01) << 3);

	 E_HIGH();
	 Delay_ms(1);
	 E_LOW();
	 Delay_ms(3);
}

void LCD_Init(void){
	Delay_ms(40);
	LCD_Command(0x02);												//Configura o LCD para modo de 4 bits.
	LCD_Command(0x28);												//Configura o LCD para 2 linhas e matriz de 5x8 pontos.
	LCD_Command(0x01);												//Limpa o display
	LCD_Command(0x0C);												//Liga o display e desliga o cursor.
	LCD_Command(0x06);												//Configura o incremento automático do cursor.
}

void LCD_Char(char dat){
	//Envia nibble alto
	GPIOB->ODR = (GPIOB->ODR & ~(GPIO_ODR_0 | GPIO_ODR_1 | GPIO_ODR_3 | GPIO_ODR_7)) |
			(((dat >> 4) & 0x01) << 0) | (((dat >> 5) & 0x01) << 1) | 
			(((dat >> 6) & 0x01) << 7) | (((dat >> 7) & 0x01) << 3);
	RS_HIGH();
	E_HIGH();
	Delay_ms(1);
	E_LOW();
	Delay_ms(1);

	//Envia nibble baixo
	GPIOB->ODR = (GPIOB->ODR & ~(GPIO_ODR_0 | GPIO_ODR_1 | GPIO_ODR_3 | GPIO_ODR_7)) |
			(((dat >> 0) & 0x01) << 0) | (((dat >> 1) & 0x01) << 1) |
			(((dat >> 2) & 0x01) << 7) | (((dat >> 3) & 0x01) << 3);
	E_HIGH();
	Delay_ms(1);
	E_LOW();
	Delay_ms(3);
}

void LCD_Char_xy(char row,char pos, char dat){
	unsigned char location=0;

    switch (row){
	case 0:
           location=(unsigned char)((0x80) + (pos) );
           LCD_Command(location);
           break;
        case 1:
           location=(unsigned char)((0xC0) + (pos));
           LCD_Command(location);
           break;
        case 2:
           location=(unsigned char)((0x94) + (pos));
           LCD_Command(location);
           break;
        case 3:
           location=(unsigned char)((0xD4) + (pos));
           LCD_Command(location);
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
	unsigned  char location=0;

	switch (row){
		case 0:
		location=(unsigned char)((0x80) + (pos));
	        LCD_Command(location);
	        break;
		
		case 1:
	        location=(unsigned char)((0xC0) + (pos));
	        LCD_Command(location);
	        break;
		
	    	case 2:
	    	location=(unsigned char)((0x94) + (pos));
	        LCD_Command(location);
	        break;
		
	    	case 3:
	        location=(unsigned char)((0xD4) + (pos));
	        LCD_Command(location);
	        break;
	}
	LCD_String(msg);
}

void LCD_Clear(void){
	LCD_Command(0x01);												//Limpa o display
	Delay_ms(3);													//Atraso 3ms
}
