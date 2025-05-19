#ifndef EUSART_H_
#define EUSART_H_

void EUSART1_Init(unsigned long baudrate);
void EUSART1_Write(const char data);
void EUSART1_Write_ln(const char data);
void EUSART1_Write_Text(const char text[]);
void EUSART1_Write_Text_ln(const char text[]);
char EUSART1_Read(void);

#endif
