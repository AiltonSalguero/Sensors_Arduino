#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>

#define BLYNK_PRINT Serial
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "CodigoBlynk";

BlynkTimer timer;

LiquidCrystal lcd(13, 12, 02, 00, 04, 05);
#define COLUMNAS 16
#define FILAS 2
const char* ssid = "FIIS_Estudiantes";
const char* password = "EstFIIS@02";
 
const int ledPin = 2;
WiFiServer server(80);


void myTimerEvent()
{
  // Se puede enviar datos a la interfaz Blink
  Blynk.virtualWrite(V5, millis() / 1000);
}


void setup() {
  Serial.begin(115200);
  lcd.begin(COLUMNAS, FILAS);
  delay(10);
 
  pinMode(15, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Blynk.begin(auth, ssid, password);

  timer.setInterval(1000L, myTimerEvent);
}
 
void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hum:");
  lcd.setCursor(5,0);
  lcd.print(analogRead(A0));

  delay(500);
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
 
