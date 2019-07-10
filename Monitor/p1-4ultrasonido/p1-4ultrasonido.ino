#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

const int pinLed = 7;
const int Echo = 4;
const int Trig = 5;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  float dist;
  long tiempo;
  
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  tiempo = pulseIn(Echo, HIGH)/2;
  dist = tiempo*0.0343;
  Serial.print("m:  ");
  Serial.println(dist);
  if(dist >= 1){ //umbral
    for (int i=1;i<=5;i++){
      digitalWrite(pinLed,HIGH);
      delay(100);
      digitalWrite(pinLed,LOW);
      delay(100);
    }
  }else{
    digitalWrite(pinLed,LOW);
    delay(1000);
  }
  lcd.setCursor(0,0);
  lcd.print("cm:");
  lcd.setCursor(3,0);
  lcd.print(dist);
}
