# Configurações

## CMSIS
Todos os código e projetos descritos acima, utilizam os arquivos da pasta CMSIS, que devem ser vinculados ao projeto conforme a sequência abaixo: 

1º - Com o projeto aberto, clique na opção *Project*;

2º - Selecionar a opção *Properties*;
<p align="center">
<img src="https://github.com/user-attachments/assets/3ceacc66-88f6-4462-8e47-ecdfd88fe395">
</p>

3º - Navegar até a opção *Paths and Symbols* após isso selecionar a opção *Add*;
<p align="center">
<img src="https://github.com/user-attachments/assets/1486f9e6-bba0-4c92-88cd-60009e21239d">
</p>

4º - Selecionar a opção *File System...*;
<p align="center">
<img src="https://github.com/user-attachments/assets/fdf2467b-477c-4d7a-9a2a-f3d8c3ee8f7e">
</p>

5º - Encontre a pasta CMSIS, após isso navegue até a pasta *Include* (STM32\STM32F030K6T6\CMSIS\Include) clique na opção *Selecionar Pasta*, após isso confirmar no botão *OK*;

6º - Repetir o mesmo processo anterior incluindo a pasta *Include* dentro de *Device* (STM32\STM32F030K6T6\CMSIS\Device\ST\STM32F0xx\Include);

Esse processo permitirá com que a IDE encontre o arquivo referente ao processador, nesse caso o arquivo stm32f030x6.h, compilando correntamente o projeto.

## Output Files
Geralmente ao se criar novos projetos na STM32CubeIDE, após a compilação do projeto, não é gerado os arquivos .hex e o .bin, para o programa gerar basta ativar as opções da imagem abaixo:
<p align="center">
<img src="https://github.com/user-attachments/assets/65e33430-1366-4163-864f-19a7563e56b8">
</p>
