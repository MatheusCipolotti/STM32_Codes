# Software

## Configuração do Clock
O exemplo desse código utiliza um cristal externo de 8MHz, sem o uso da PLL, a *Figura 1* mostra a estrutura de funcionamento e configuração do clock, além disso a dispersão para os periféricos.
<p align="center" width="100%">
<img width="100%" src="https://github.com/user-attachments/assets/293d138e-f5b6-4f3e-b53f-d6b02e55d10d">
</p>
<p align="center" width="100%">
  Figura 1 - Árvore de configuração do clock 
</p>


## Systick e Delay

## Saída Digital
A configuração de saídas digitais nesse microcontrolador depende das seguintes configurações:
- Habilitação do clock para o PORT do pino que será configurado.
