#include <DHT.h>
#include <Wire.h> 
#include "RTClib.h"
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

RTC_DS1307 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(7, DHT22);

#define EEPROM_SIZE 1024 
#define LOG_SIZE sizeof(Log) 
#define MAX_LOGS 5

#define LED_temperature 13
#define LED_luminosity  12
#define LED_humidity    11
#define BUZZER_PIN       8
#define BUTTON_PIN       6

int minutes = 1;
float humiditySum;
float temperatureSum;
float luminositySum;

char tempAlert[] = "TEMP IS OUT OF RANGE";
char lumAlert[] = "LUM IS OUT OF RANGE";
char humAlert[] = "HUM IS OUT OF RANGE";

const long interval = 60000;

unsigned long previousMinute = 0;

struct Log {
  char timestamp[64]; 
  char message[64]; 
};

void setup()
{
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  dht.begin();

  rtc.begin();

  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_temperature, OUTPUT);
  pinMode(LED_luminosity, OUTPUT);
  pinMode(LED_humidity, OUTPUT);

  // Exibição do loading animado ao inicializar o data logger
  ShowLoading();

  // Seta os valores iniciais de medição dos sensores para serem exibidos no LCD
  temperatureSum += dht.readTemperature();  
  humiditySum += dht.readHumidity();
  luminositySum += map(analogRead(A0), 0, 1023, 0, 100);

  ShowParameters(temperatureSum, luminositySum, humiditySum);
}

void loop()
{ 
  unsigned long currentTime = millis();

  // Verifica se já se passou um minuto, se sim, é recalculada a média das medições dos sensores e o display é atualizado
  if (currentTime - previousMinute >= interval) {
    previousMinute = currentTime;
    minutes++;
    temperatureSum += dht.readTemperature(); 
    humiditySum += dht.readHumidity();
    luminositySum += map(analogRead(A0), 0, 1023, 0, 100);
    ShowParameters(temperatureSum / minutes, luminositySum / minutes, humiditySum / minutes);
  }

  float humidityAVG = humiditySum / minutes;
  float temperatureAVG = temperatureSum / minutes;
  float luminosityAVG = luminositySum / minutes;

  // Checkagem de todas as medições para saber se cada uma delas está dentro de seus parâmetros específicos
  CheckParameters(temperatureAVG, 15.00, 25.00, tempAlert, sizeof(tempAlert), LED_temperature);
  CheckParameters(luminosityAVG, 0.00, 30.00, lumAlert, sizeof(lumAlert), LED_luminosity);
  CheckParameters(humidityAVG, 30.00, 50.00, humAlert, sizeof(humAlert), LED_humidity);

  // Uma outra verificação é realizada para saber se o buzzer deverá ser acionado
  if ((temperatureAVG > 15.00 && temperatureAVG < 25.00) && 
      (luminosityAVG > 0.00 && luminosityAVG < 30.00) && 
      (humidityAVG > 30.00 && humidityAVG < 50.0)) 
  {
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    Alarm();
  }
}  

// Formata o log a ser exibido na porta serial, com o timestamp e a mensagem 
void PrintLog(const Log& log) {
  Serial.print("Timestamp: ");
  Serial.println(log.timestamp);
  Serial.print("Message: ");
  Serial.println(log.message);
  Serial.println("-----------------------------");
}

// Exibe os últimos 5 logs salvos na EEPROM
void PrintLastLogs() {
  int numLogs = min(EEPROM_SIZE / LOG_SIZE, MAX_LOGS); 
  int startIndex = max(0, EEPROM_SIZE - numLogs * LOG_SIZE); 

  for (int i = startIndex; i < EEPROM_SIZE; i += LOG_SIZE) {
    Log log;
    ReadLog(i, log);
    PrintLog(log);
  }
}

// Exibe as medições no LCD
void ShowParameters(float temperature, float luminosity, float humidity) {
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(8, 0);
  lcd.print(" L:");
  lcd.print(luminosity, 1);
  lcd.print("% ");
  
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humidity, 1);
  lcd.print("% ");
}

// Faz a checkagem de valores de referencia das váriaveis de temperatura, luminosidade e humidade
void CheckParameters(float currentValue, float minValue, float maxValue, char message[], int messageSize, int led) {
  if(currentValue >= minValue && currentValue <= maxValue){
    digitalWrite(led, LOW);
  } else {
    DateTime now = rtc.now();
    Log newLog;   
    snprintf(newLog.timestamp, sizeof(newLog.timestamp), "%02d-%02d-%04d %02d:%02d:%02d",
             now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());
    strcpy(newLog.message, message);
    AddLog(newLog); 
    digitalWrite(led, HIGH);
  }
}

// Aciona os alertas luminosos
void Alarm() {
  #define NOTE_B0  31
  #define NOTE_C1  33
  #define NOTE_CS1 35
  #define NOTE_D1  37
  #define NOTE_DS1 39
  #define NOTE_E1  41
  #define NOTE_F1  44
  #define NOTE_FS1 46
  #define NOTE_G1  49
  #define NOTE_GS1 52
  #define NOTE_A1  55
  #define NOTE_AS1 58
  #define NOTE_B1  62
  #define NOTE_C2  65
  #define NOTE_CS2 69
  #define NOTE_D2  73
  #define NOTE_DS2 78
  #define NOTE_E2  82
  #define NOTE_F2  87
  #define NOTE_FS2 93
  #define NOTE_G2  98
  #define NOTE_GS2 104
  #define NOTE_A2  110
  #define NOTE_AS2 117
  #define NOTE_B2  123
  #define NOTE_C3  131
  #define NOTE_CS3 139
  #define NOTE_D3  147
  #define NOTE_DS3 156
  #define NOTE_E3  165
  #define NOTE_F3  175
  #define NOTE_FS3 185
  #define NOTE_G3  196
  #define NOTE_GS3 208
  #define NOTE_A3  220
  #define NOTE_AS3 233
  #define NOTE_B3  247
  #define NOTE_C4  262
  #define NOTE_CS4 277
  #define NOTE_D4  294
  #define NOTE_DS4 311
  #define NOTE_E4  330
  #define NOTE_F4  349
  #define NOTE_FS4 370
  #define NOTE_G4  392
  #define NOTE_GS4 415
  #define NOTE_A4  440  
  #define NOTE_AS4 466
  #define NOTE_B4  494
  #define NOTE_C5  523
  #define NOTE_CS5 554
  #define NOTE_D5  587
  #define NOTE_DS5 622
  #define NOTE_E5  659
  #define NOTE_F5  698
  #define NOTE_FS5 740
  #define NOTE_G5  784
  #define NOTE_GS5 831
  #define NOTE_A5  880
  #define NOTE_AS5 932
  #define NOTE_B5  988
  #define NOTE_C6  1047
  #define NOTE_CS6 1109
  #define NOTE_D6  1175
  #define NOTE_DS6 1245
  #define NOTE_E6  1319
  #define NOTE_F6  1397
  #define NOTE_FS6 1480
  #define NOTE_G6  1568
  #define NOTE_GS6 1661
  #define NOTE_A6  1760
  #define NOTE_AS6 1865
  #define NOTE_B6  1976
  #define NOTE_C7  2093
  #define NOTE_CS7 2217
  #define NOTE_D7  2349
  #define NOTE_DS7 2489
  #define NOTE_E7  2637
  #define NOTE_F7  2794
  #define NOTE_FS7 2960
  #define NOTE_G7  3136
  #define NOTE_GS7 3322
  #define NOTE_A7  3520
  #define NOTE_AS7 3729
  #define NOTE_B7  3951
  #define NOTE_C8  4186
  #define NOTE_CS8 4435
  #define NOTE_D8  4699
  #define NOTE_DS8 4978
  #define REST      0

  int tempo = 180;
  int melody[] = {  
    NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
    NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
    NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
    NOTE_A4, 2, 
  };

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(BUZZER_PIN, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(BUZZER_PIN);
  }
}

// Exibe o loading animado
void ShowLoading() {
  byte loadingBar1[] = { B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111 };
  byte loadingBar2[] = { B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111 };
  byte loadingBar3[] = { B11111, B00001, B00001, B00001, B00001, B00001, B00001, B11111 };
  byte loadingBar4[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };

  lcd.setCursor(3, 0);
  lcd.print("NEXUM TECH");

  lcd.createChar(0, loadingBar1);
  lcd.setCursor(3, 1);
  lcd.write(0);
  
  lcd.createChar(1, loadingBar2);
  lcd.setCursor(4, 1);
  lcd.write(1);

  lcd.setCursor(5, 1);
  lcd.write(1);

  lcd.setCursor(6, 1);
  lcd.write(1);

  lcd.setCursor(7, 1);
  lcd.write(1);

  lcd.setCursor(8, 1);
  lcd.write(1);

  lcd.setCursor(9, 1);
  lcd.write(1);

  lcd.setCursor(10, 1);
  lcd.write(1);

  lcd.setCursor(11, 1);
  lcd.write(1); 
  
  lcd.createChar(2, loadingBar3);
  lcd.setCursor(12, 1);
  lcd.write(2);

  lcd.createChar(3, loadingBar4);

  for(int i = 3; i <= 12; i++){
      lcd.setCursor(i, 1);
      lcd.write(3);
      delay(500);
  }
  
  lcd.clear();
}

// Leitura do log na EEPROM
void ReadLog(int address, Log& log) {
  EEPROM.get(address, log);
}

// Sobrescreve o log mais antigo armazenado na EEPROM, de modo que sempre fiquem os últimos 5 
void WriteLog(int address, const Log& log) {
  EEPROM.put(address, log);
}

// Adiciona os últimos 5 logs na EEPROM
void AddLog(const Log& newLog) {
  int numLogs = min(EEPROM_SIZE / LOG_SIZE, MAX_LOGS); 

  for (int i = numLogs - 1; i > 0; i--) {
    Log log;
    ReadLog((i - 1) * LOG_SIZE, log);
    WriteLog(i * LOG_SIZE, log);
  }

  WriteLog(0, newLog);
}

