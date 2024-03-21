# Nexum Tech: Especificação Técnica

## :page_with_curl: Descrição

Este projeto consiste em um sistema de monitoramento ambiental que utiliza sensores para medir temperatura, umidade e luminosidade. O sistema exibe essas informações em um display LCD e aciona alertas luminosos e sonoros caso alguma das medições esteja fora dos limites pré-definidos.

## :chart_with_upwards_trend: Componentes
- Arduino Uno
- Sensor de temperatura e umidade DHT11
- Sensor de luminosidade LDR
- Módulo RTC (Real Time Clock) DS1307
- Display LCD 16x2 com interface I2C
- Buzzer
- Potenciômetro
- Resistores
- Jumpers
- Protoboard

## :memo: Funcionalidades
- Medição e exibição de temperatura, umidade e luminosidade em tempo real no display LCD.
- Alerta visual e sonoro caso os valores de medição estejam fora dos limites pré-definidos.
- Armazenamento dos últimos 5 eventos de alerta em uma memória EEPROM.
- Display de um loading animado durante a inicialização do sistema.

## :page_with_curl: Pinagem
- DHT11: Conectado ao pino 7 do Arduino.
- LDR: Conectado à entrada analógica A0 do Arduino.
- DS1307: Conectado aos pinos SDA e SCL do Arduino.
- Display LCD: Conectado via interface I2C aos pinos SDA e SCL do Arduino.
- Buzzer: Conectado ao pino 8 do Arduino.
- Potenciômetro: Conectado à entrada analógica A1 do Arduino.

## :page_with_curl: Como usar
1. Conectar todos os componentes conforme a pinagem especificada.
2. Carregar o código para o Arduino.
3. Ajustar os limites de temperatura, umidade e luminosidade conforme necessário no código.
4. Ajustar o potenciômetro para controlar o volume do buzzer.
5. Monitorar as medições exibidas no display LCD e aguardar eventuais alertas.

## :page_with_curl: Autores
Este projeto foi desenvolvido por Gabriel Barbosa, Gustavo Braz, Ruan Faccin, Victor Albano.

---
