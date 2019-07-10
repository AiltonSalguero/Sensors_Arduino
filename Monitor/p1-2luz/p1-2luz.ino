
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
  int light;
  light = analogRead(A2);
  if(light < 200){ //umbral
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
  Serial.print("lux:  ");
  Serial.println(light);
  lcd.setCursor(0,0);
  lcd.print("lux:");
  lcd.setCursor(4,0);
  lcd.print(light);
}
