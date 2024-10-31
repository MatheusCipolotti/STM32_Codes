# Software
Nesse exemplo, os arquivos PWM.c e configs.c, na função GPIO, possuem as configurações necessárias para habilitar o PWM, abaixo é explicado o funcionamento e as opções disponíveis nos registradores utilizados no arquivo.

# GPIO
A configuração do GPIO para essa aplicação, necessita dos seguintes passos:
- 1º - Habilitação do clock no GPIO com a função que será utilizada, nesse caso GPIOA;
- 2º - Definir o pino com a função alternativa, utilizando o registrador MODER;
- 3º - Definir qual das funções alternativas o GPIO possuirá;

## MODER
<p align="center">
<img  src="https://github.com/user-attachments/assets/a7368376-9674-4781-adaf-587715a21e60">
</p>
<p align="center">
  Figura 1 - Registrador MODER
</p>

## AFR 
No STM32, cada pino pode ter múltiplas funções alternativas, que são configuradas através dos registros de função alternativa (AFR). Cada porta GPIO tem dois registros de função alternativa: AFR[0] para os pinos de 0 a 7 (*Figura 2*) e AFR[1] para os pinos de 8 a 15 (*Figura 3*). Conforme a *Figura 4*, a função alternativa AF2 é atribuída ao TIM1_CH1N no PA7 e TIM1_CH1 no PA8.

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
  Figura 2 - Registrador AFRH (AFR[1])
</p>

<p align="center">
<img  src="https://github.com/user-attachments/assets/12dab3cf-2ed7-4b74-a6f9-c3e4334b47b4">
</p>
<p align="center">
  Figura 4 - Tabela de funções alternativas
</p>

# PWM

## Frequência do PWM - ARR e PSC
A frequência do PWM é determinada por 3 fatores, frequência do clock do microcontrolador, valor do registrador ARR (Auto Reload Register) e o PSC (prescaler), conforme a *Figura 5*:
<p align="center">
<img  src="https://github.com/user-attachments/assets/4f15b572-46d6-4336-a8ea-1f1291a81ab9">
</p>
<p align="center">
  Figura 5 - Fórmula para definição da frequência do PWM
</p>
