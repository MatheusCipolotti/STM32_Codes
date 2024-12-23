# Software
Os arquivos ADC.h e ADC.c são responsáveis pela conversão AD, abaixo é explicado o funcionamento e as opções disponíveis nos registradores utilizados no arquivo.

## ADC_CFGR2_CKMODE
O ADC possui uma arquitetura com dois Clocks, permitindo que ele seja alimentado por um clock independente do clock APB (PCLK).
<p align="center">
<img src="https://github.com/user-attachments/assets/c9b06dd0-576b-49b3-87b4-13b10f161011">
</p>
<p align="center" width="100%">
  Figura 1 - Seleção do Clock do ADC
</p>

O clock de entrada do ADC pode ser selecionado entre duas fontes:

a) Clock Assíncrono do ADC: Uma fonte de clock específica e independente do PCLK. Para usá-lo, os bits CKMODE[1:0] do registro ADC_CFGR2 devem ser zerados. Isso permite que o ADC alcance sua frequência máxima independentemente da configuração do APB.

b) Clock Derivado do PCLK: O clock do ADC pode ser derivado do clock APB, dividido por um fator programável (2 ou 4), conforme os bits CKMODE[1:0]. Para essa opção, os bits CKMODE[1:0] devem ser diferentes de “00”.

A opção (a) maximiza a frequência do ADC, contudo não é possível determinar a latência entre o evento de disparo e o início da conversão (jitter), enquanto a opção (b) evita ressincronizações de clock, o que é útil para disparos precisos do ADC, especialmente se for acionado por um temporizador.

A imagem abaixo mostra a organização do registrador:

<p align="center">
<img src="https://github.com/user-attachments/assets/0c075911-23b4-43b4-a39d-dbb5faf30a12">
</p>
<p align="center" width="100%">
  Figura 2 - Registrador de configuração do ADC 2 (ADC_CFGR2)
</p>

## ADC_SMPR_SMP
Antes de iniciar uma conversão, o ADC precisa estabelecer uma conexão direta entre a fonte de tensão a ser medida e o capacitor de amostragem embutido. O tempo de amostragem deve ser suficiente para que a fonte de tensão carregue o capacitor de acordo com o nível de tensão de entrada.

O tempo de amostragem programável permite ajustar a velocidade de conversão conforme a resistência de entrada da fonte de tensão. O ADC amostra a tensão de entrada por um número de ciclos de clock que pode ser ajustado pelos bits SMP[2:0] no registro ADC_SMPR, e esse tempo de amostragem é comum a todos os canais. Caso necessário, o software pode ajustar o tempo de amostragem entre conversões.

<p align="center">
<img src="https://github.com/user-attachments/assets/774429e2-68fa-4dc7-9e75-11bcc36b64b0">
</p>
<p align="center" width="100%">
  Figura 3 - Registrador de tempo de amostragem do ADC (ADC_SMPR)
</p>

## ADC_CR_ADCAL
O ADC possui uma função de calibração. Durante essa fase, ele calcula um fator de calibração que é aplicado internamente até o próximo desligamento do ADC. A aplicação não deve usar o ADC durante a calibração e precisa aguardar sua conclusão.

A calibração deve ser realizada antes de iniciar a conversão A/D, pois elimina o erro de offset, que pode variar entre chips devido a diferenças de fabricação. A calibração é iniciada pelo software ao definir o bit ADCAL como 1, e só pode ser feita quando o ADC está desativado (ADEN = 0). O bit ADCAL permanece em 1 durante toda a sequência de calibração e é limpo automaticamente quando a calibração é concluída. Após isso, o fator de calibração pode ser lido no registro ADC_DR (bits 6 a 0).

A calibração interna é mantida enquanto o ADC estiver desativado (ADEN = 0). Quando as condições de operação mudam (como variações de VDDA ou temperatura), recomenda-se realizar nova calibração. O fator de calibração é perdido sempre que a alimentação do ADC é removida, como ao entrar em modo de espera.

Procedimento de calibração via software:

1 - Assegure que ADEN = 0 e DMAEN = 0.

2 - Defina ADCAL = 1.

3 - Aguarde até que ADCAL = 0.

4 - O fator de calibração pode ser lido nos bits 6:0 do registro ADC_DR.
