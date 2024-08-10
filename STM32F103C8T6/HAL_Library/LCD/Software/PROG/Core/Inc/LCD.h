#ifndef INC_LCD_H_
#define INC_LCD_H_

void LCD_Send_Command(uint8_t cmd);									//Função para enviar comandos ao LCD
void LCD_Init(void);												//Função para inicializar o LCD
void LCD_Char(char dat);
void LCD_Char_xy(char row,char pos, char dat);
void LCD_String(const char *msg);
void LCD_String_xy(char row,char pos,const char *msg);
void LCD_Clear(void);

#endif /* INC_LCD_H_ */
