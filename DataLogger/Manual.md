<h1 align="center"> 
<br>
    <img src="./Assets/Title.PNG" width="270">
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

## :page_with_curl: Tutorial

<br>

Lista de dependências para executar o projeto:

    Client:
    - React 18
    - Vite
    - Tailwind CSS
    - AOS
    - React-Query
    - Axios 
    - Apex Charts
    - Data table component
    - React-Player
    - React-Spinners
    - React-Phosphor

    Server:
    - .Net 6
    - Entity Framework Core
    - SQL Server

OBS: É necessário fazer a importação da base de dados do arquivo "datatran2013.csv" de dados dentro do seu banco de dados, e em seguida executar os scripts encontrado no arquivo "cria_banco.txt" e "normaliza_banco.txt" para que os dados possam ser acessados e consumidos propriamente.

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
