

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;
int ledPin=6;
int thresholdvalue=100;

void setup() 
{
  pinMode(ledPin,OUTPUT);
  Serial.begin(115200);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
 

    delay(1000);
}

void loop() 
{
   int sensorValue=analogRead(1);
 
  if (sensorValue<thresholdvalue){
    digitalWrite(ledPin,HIGH);
    
  }else{
    digitalWrite(ledPin,LOW);
  }
  
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(sensorValue);

    delay(300);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
