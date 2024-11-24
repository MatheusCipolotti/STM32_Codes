# Instruções

## Pinout
Conector J2 - Pinos de programação:
- 1 - 3V3;
- 2 - SWDIO;
- 3 - SWCLK;
- 4 - GND;

Conector J3 - Pinos de Interface:

| Pino | Nome    | Funções                                                              |
| ---- | ------- | -------------------------------------------------------------------- |
| 1    | VDC     |                                                                      |
| 2    | 3V3     |                                                                      |
| 3    | GND     |                                                                      |
| 4    | GND     |                                                                      |
| 5    | PA13    | IR_OUT - SWDIO                                                       |
| 6    | PA14    | USART1_TX - USART2_TX - SWCLK                                        |
| 7    | PA11    | USART1_CTS - TIM1_CH4 - EVENTOUT - I2C2_SCL                          |
| 8    | PA12    | USART1_RTS - TIM1_ETR - EVENTOUT - I2C2_SDA                          |
| 9    | PA9     | USART1_TX - TIM1_CH2 - TIM15_BKIN - I2C1_SCL                         |
| 10   | PA10    | USART1_RX - TIM1_CH3 - TIM17_BKIN - I2C1_SCA                         |
| 11   | PB1     | TIM3_CH4 - TIM14_CH1 - TIM1_CH3N - USART3_RTS                        |
| 12   | PA8     | USART1_CK - TIM1_CH1 - EVENTOUT - MCO                                |
| 13   | PA7     | SPI1_MOSI - TIM3_CH2 - TIM14_CH1 - TIM1_CH1N - TIM17_CH1 - EVENTOUT  |
| 14   | PB0     | TIM3_CH3 - TIM1_CH2N - EVENTOUT - USART3_CK                          |
| 15   | PA5     | SPI1_SCK - USART6_RX                                                 |
| 16   | PA6     | SPI1_MISO - TIM3_CH1 - TIM1_BKIN - TIM16_CH1 - EVENTOUT - USART3_CTS |
| 17   | PA3     | USART1_RX - USART2_RX - TIM15_CH2                                    |
| 18   | PA4     | SPI1_NSS - USART1_CK - USART2_CK - TIM14_CH1 - USART6_TX             |
| 19   | PA1     | USART1_RTS - USART2_RTS - EVENTOUT - USART4_RX                       |
| 20   | PA2     | USART1_TX - USART2_TX - TIM15_CH1                                    |
| 21   | PB7     | I2C1_SDA - USART1_RX - TIM17_CH1N - USART4_CTS                       |
| 22   | PA0     | USART1_CTS - USART2_CTS - USART4_TX                                  |
| 23   | PB5     | SPI1_MOSI - I2C1_SMBA - TIM16_BKIN - TIM3_CH2 - USART5_CK_RTS        |
| 24   | PB6     | I2C1_SCL - USART1_TX - TIM16_CH1N                                    |
| 25   | PB3     | SPI1_SCK - EVENTOUT - USART5_TX                                      |
| 26   | PB4     | SPI1_MISO - TIM3_CH1 - EVENTOUT - TIM17_BKIN - USART5_RX             |
| 27   | RESET   |                                                                      |
| 28   | PA15    | SPI1_NSS - USART1_RX - USART2_RX - USART4_RTS - EVENTOUT             |
| 29   | OSC_IN  |                                                                      |
| 30   | OSC_OUT |                                                                      |

## Jumpers
- JP1 - Habilita o LED de indicação do 3V3;
- JP2 - Reset;
- JP3 - BOOT0 em nível lógico 1;
- JP4 - Habilita o BOARDLED (PB0);
- JP5 - Habilita a alimentação via USB;
- JP6 - Habilita o pino de entrada do cristal (8MHz) da placa;
- JP7 - Habilita o pino de saída do cristal (8MHz) da placa;
- JP8 - BOOT0 em nível lógico 0;

*Obs.: Lista considerando os efeitos descritos quando o jumper estiver soldado ou conectado.

## Test Points
- TP1 - GND;
- TP2 - 3V3;

## LEDs de Indicação
- D6 - 3V3;
- D7 - BOARDLED (PB0);
- D8 - RS232 RX (PA3);
- D9 - RS232 TX (PA2);
