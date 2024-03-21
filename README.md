<h1 align="center"> 
<br>
    <img src="https://github.com/GabrielAB2411/NexumTech/assets/103553596/d4135cae-0443-4da5-b831-d4a1df760eca" width="800" height="400";
>
<br>
<br>
Nexum Tech: Data Logger
</h1>

<hr />

## :dart: Objetivo

<br>

O objetivo deste trabalho é desenvolver um Proof of Concept (PoC) utilizando a plataforma Arduino UNO R3 para realizar medições de luminosidade, temperatura e umidade em um ambiente industrial. O sistema calculará a média ponderada dessas leituras a cada minuto de operação, exibindo-as em um display de cristal líquido (LCD) e armazenando-as na memória EEPROM com timestamps, enquanto aciona um alerta sonoro e luminoso caso os parâmetros estejam fora dos níveis de referência predefinidos. Além disso, o projeto incluirá uma abertura gráfica personalizada com o logo ou slogan da empresa. Os triggers definidos para disparar o alerta são: temperatura entre 15°C e 25°C, luminosidade entre 0% e 30%, e umidade entre 30% e 50%.

<br>

<hr />

## :page_with_curl: Participantes

<br>

Lista de participantes responsáveis pela elaboração do projeto:

  - Ruan Faccin: 081220029
  - Gustavo Braz: 081220001
  - Gabriel Alves: 081220041
  - Victor Albano: 081220000

<br>

<hr />

## :city_sunset: Preview

<br>

<div align="center">
    <img src="./Assets/Preview.gif" width="570" height="230">
</div>

<br>

<hr />

## :rocket: Componentes Utilizados 

Projeto desenvolvido com os seguintes componentes:

- :heavy_check_mark: MCU (Atmega 328P) - Arduino Uno R3
- :heavy_check_mark: LDR + Resistor 10KOhm
- :heavy_check_mark: DHT-11 (Sensor de temperatura e umidade)
- :heavy_check_mark: LCD 16x2 - I2C
- :heavy_check_mark: Bateria de 9V
- :heavy_check_mark: RTC (Real Time Clock)
- :heavy_check_mark: Protoboard
- :heavy_check_mark: Jumpers
- :heavy_check_mark: LEDs
- :heavy_check_mark: Resistores

<br>
<hr />

## 📦 Documentação

### Especificação técnica, Diagrama elétrico, Manual de operações e Código fonte

| Link | Descrição |
| --- | --- |
| [`Especificação`](https://github.com/GabrielAB2411/NexumTech/blob/main/DataLogger/EspeficacaoTecnica.md) | Documento que detalha os requisitos técnicos específicos do projeto|
| [`Diagrama`](https://github.com/nhn/tui.editor/tree/master/apps/react-editor) | Representação simplificada de um sistema elétrico do projeto |
| [`Código`](https://github.com/nhn/tui.editor/tree/master/apps/react-editor) | Código fonte utilizado no projeto |
| [`Manual`](https://github.com/GabrielAB2411/NexumTech/blob/main/DataLogger/Manual.md) | Documento que fornece instruções detalhadas sobre como usar, configurar e manter o produto 
