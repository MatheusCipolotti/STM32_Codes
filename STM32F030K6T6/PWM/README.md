# Software
Nesse exemplo, os arquivos PWM.c e configs.c, na função GPIO, possuem as configurações necessárias para habilitar o PWM, abaixo é explicado o funcionamento e as opções disponíveis nos registradores utilizados no arquivo.

# GPIO
A configuração do GPIO para essa aplicação, necessita dos seguintes passos:
- 1º - Habilitação do clock no GPIO com a função que será utilizada, nesse caso GPIOA;
- 2º - Definir o pino com a função alternativa, utilizando o registrador MODER;
- 3º - Definir qual das funções alternativas o GPIO possuirá, utilizando o registrador AFR;

## MODER
<p align="center">
<img  src="https://github.com/user-attachments/assets/a7368376-9674-4781-adaf-587715a21e60">
</p>
<p align="center">
  Figura 1 - Registrador MODER
</p>

## AFR 
No STM32, cada pino pode ter múltiplas funções alternativas, que são configuradas através dos registros de função alternativa (AFR). Cada porta GPIO tem dois registros de função alternativa: AFR[0] para os pinos de 0 a 7 (*Figura 2*) e AFR[1] para os pinos de 8 a 15 (*Figura 3*). Conforme a *Figura 4* e a *Figura 5*, a função alternativa AF2 é atribuída da seguinte maneira:
- PA8 - TIM1_CH1;
- PA9 - TIM1_CH2;
- PA10 - TIM1_CH3;
- PB13 - TIM1_CH1N;
- PB14 - TIM1_CH2N;
- PB15 - TIM1_CH3N;

<p align="center">
<img  src="https://github.com/user-attachments/assets/1c7efc87-0225-4efa-b17d-dbeadbb576b9">
</p>
<p align="center">
  Figura 2 - Registrador AFRL (AFR[0])
</p>

<p align="center">
<img  src="https://github.com/user-attachments/assets/332aa283-9388-430f-a5b6-c0df6df6a437">
</p>
<p align="center">
  Figura 3 - Registrador AFRH (AFR[1])
</p>

<p align="center">
<img  src="https://github.com/user-attachments/assets/9b850c31-462b-45f8-a15a-9c562d10f9fd">
</p>
<p align="center">
  Figura 4 - 1ª Tabela de funções alternativas
</p>

<p align="center">
<img  src="https://github.com/user-attachments/assets/56d4e1e2-2c34-41ac-888d-59b3a05096e6">
</p>
<p align="center">
  Figura 5 - 2ª Tabela de funções alternativas
</p>

# PWM

## Frequência do PWM - ARR e PSC
A frequência do PWM é determinada por 3 fatores, frequência do clock do microcontrolador, valor do registrador ARR (Auto Reload Register) e o PSC (prescaler), conforme a *Figura 6*:
<p align="center">
<img  src="https://github.com/user-attachments/assets/4f15b572-46d6-4336-a8ea-1f1291a81ab9">
</p>
<p align="center">
  Figura 6 - Fórmula para definição da frequência do PWM
</p>
