#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>

#define BLYNK_PRINT Serial
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>

const int trigPin = 3;
const int echoPin = 1;
// defines variables
long duration;
int distance;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "CodigoBlink";

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
  // Se puede enviar datos al blynk
  Blynk.virtualWrite(V5, millis() / 1000);
}


void setup() {
  Serial.begin(115200);
  lcd.begin(COLUMNAS, FILAS);
  delay(10);
 
  pinMode(15, OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  
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
  lcd.print("Humedad:");
  lcd.setCursor(9,0);

  lcd.setCursor(0,1);
  lcd.print("Distancia:");
  lcd.setCursor(10,1);
  lcd.print(distance);

  delay(500);

  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  medirDistancia();
}

void medirDistancia(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  }
 
