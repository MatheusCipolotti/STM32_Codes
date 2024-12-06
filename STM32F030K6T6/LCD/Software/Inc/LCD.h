#ifndef LCD_H_
#define LCD_H_

void LCD_Command(unsigned char cmd);
void LCD_Init(void);
void LCD_Char(char dat);
void LCD_Char_xy(char row,char pos, char dat);
void LCD_String(const char *msg);
void LCD_String_xy(char row,char pos,const char *msg);
void LCD_Clear(void);

#endif /* LCD_H_ */
