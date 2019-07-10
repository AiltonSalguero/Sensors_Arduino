#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

const int pinLed = 7;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  int sound,soundr;
  sound = analogRead(A2);
  soundr = sound*50/1023.0;
  Serial.print("db:  ");
  Serial.println(soundr);
  if(soundr >= 100){ //umbral
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
  lcd.print("db:");
  lcd.setCursor(3,0);
  lcd.print(soundr);
}
