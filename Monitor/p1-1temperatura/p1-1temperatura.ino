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
  float t,tC,tK,tF;
  t = analogRead(A0);
  tC = t*50/1023.0;
  //tK = tC+273.15;
  //tF = (tC*9/5)+32.0;
  Serial.print("C:  ");
  Serial.println(tC);
  if(tC >= 27){ //umbral
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
  lcd.print("C:");
  lcd.setCursor(2,0);
  lcd.print(tC);
  /*lcd.setCursor(8,0);
  lcd.print("F:");
  lcd.setCursor(10,0);
  lcd.print(tF);
  lcd.setCursor(0,1);
  lcd.print("K:");
  lcd.setCursor(2,1);
  lcd.print(tK);*/
}
