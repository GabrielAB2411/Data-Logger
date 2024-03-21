<h1 align="center"> 
<br>
    <img src="https://github.com/GabrielAB2411/NexumTech/assets/103553596/d4135cae-0443-4da5-b831-d4a1df760eca" width="800" height="400";
>
<br>
<br>
Nexum Tech: Manual de operações
</h1>

<hr />

## :blue_book: Introdução

<br>

Este projeto é baseado na arquitetura AVR ATmega328P e implementa um data logger capaz de monitorar luminosidade através do sensor LDR, temperatura ambiente e umidade relativa do ar por meio do sensor DHT11. O sistema utiliza a EEPROM para o registro de anormalidades, como descrito no código fonte. Além disso, o equipamento foi construído com um display LCD I2C 16x2 e um RTC I2C para registro temporal, complementado por três LEDs sinalizadores (verde, vermelho e amarelo) para alertas visuais.

<br>

<hr />

## :hammer: Funcionalidades

<br>

- **Monitoramento de Luminosidade:** O sensor LDR é responsável por capturar variações na luminosidade do ambiente, fornecendo informações valiosas para análise de condições de iluminação;
- **Medição de Temperatura e Umidade:** O sensor DHT11 possibilita a medição precisa da temperatura e umidade relativa do ar, aspectos cruciais para o controle de ambientes;
- **Registro em EEPROM:** Os dados coletados são armazenados na EEPROM do Arduino, permitindo o acesso a históricos de leituras para análise retrospectiva;
- **Exibição em Display LCD:** O display LCD I2C 16x2 proporciona uma interface intuitiva para visualização em tempo real dos dados coletados;
- **Sinalização de Anormalidades:** Os LEDs sinalizadores indicam de forma clara e imediata quando os parâmetros monitorados ultrapassam os níveis de referência estabelecidos.

<br>

<hr />

## :rocket: Componentes Utilizados 
<br>

1. **MCU (Atmega 328P) - Arduino Uno R3**
   - O microcontrolador é o cérebro do projeto, responsável por executar o código e controlar todas as operações do sistema. No caso deste projeto, o Arduino Uno R3 com MCU Atmega 328P é utilizado devido à sua facilidade de programação e ampla compatibilidade com diversos sensores e periféricos.

2. **LDR + Resistor 10KOhm**
   - O LDR (Light Dependent Resistor) é um sensor de luminosidade que varia sua resistência de acordo com a intensidade da luz incidente. O resistor de 10KOhm é utilizado em conjunto com o LDR para formar um divisor de tensão, permitindo que o Arduino possa medir a variação de resistência e, consequentemente, a luminosidade do ambiente.

3. **DHT-11 (Sensor de temperatura e umidade)**
   - O DHT-11 é um sensor que permite medir tanto a temperatura ambiente quanto a umidade relativa do ar. Ele é utilizado neste projeto para fornecer informações sobre as condições ambientais do local onde o sistema está instalado.

4. **LCD 16x2 - I2C**
   - O display LCD 16x2 é utilizado para exibir informações ao usuário de forma visual. A versão I2C deste display facilita a comunicação com o Arduino, reduzindo a quantidade de pinos necessários para conexão e simplificando o código de controle.

5. **Bateria de 9V**
   - A bateria de 9V é utilizada como fonte de energia para alimentar o sistema de forma autônoma, sem depender de uma fonte de alimentação externa.

6. **RTC (Real Time Clock)**
   - O RTC é um componente que mantém o controle preciso do tempo mesmo quando o sistema está desligado. Ele é utilizado neste projeto para registrar o momento exato em que cada medição é realizada, garantindo precisão temporal nos dados coletados.

7. **Protoboard**
   - A protoboard é uma placa de circuito que permite realizar conexões temporárias entre os componentes eletrônicos durante o desenvolvimento do projeto.

8. **Jumpers**
   - Os jumpers são cabos condutores utilizados para fazer as conexões elétricas entre os componentes na protoboard. Eles permitem uma montagem flexível e facilitam a reconfiguração do circuito conforme necessário.

9. **LEDs**
   - Os LEDs (Light Emitting Diodes) são dispositivos semicondutores que emitem luz quando uma corrente elétrica passa por eles. Neste projeto, os LEDs são utilizados para fornecer feedback visual ao usuário, indicando o status do sistema ou a ocorrência de eventos específicos.

10. **Resistores**
    - Os resistores são componentes eletrônicos que limitam a corrente elétrica em um circuito. Eles são utilizados em diferentes partes do projeto para garantir o funcionamento correto dos componentes, protegê-los contra sobrecargas e ajudar a ajustar níveis de tensão e corrente conforme necessário.

<br>
<hr />

## :computer: Configuração do Ambiente de Desenvolvimento 
<br>

1. Instale o software de programação AVR de sua preferência (por exemplo, AVR Studio ou Arduino IDE);
2. Conecte os componentes conforme o diagrama de conexão fornecido;
3. Carregue o código fonte disponível neste repositório para o microcontrolador.
<br>
<hr />

## :paperclip: Montagem do Circuito 
<br>

1. Conecte o Arduino Uno à protoboard;
2. Conecte os sensores LDR e DHT11 à protoboard;
3. Conecte o display LCD e o RTC à protoboard;
4. Conecte os LEDs sinalizadores à protoboard;
5. Utilize os jumpers para fazer as conexões entre os componentes de acordo com o esquema de ligação.
<br>
<hr />
