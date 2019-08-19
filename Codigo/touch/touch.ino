// SERVO
#include <Servo.h>
Servo servo;
int angle = 10;
int pinServo = 7;

#define ctsPin 4 // Pin Touch
void setup() {
  Serial.begin(9600);
  // TOUCH
  pinMode(ctsPin, INPUT);

  // SERVO
  servo.attach(pinServo);
  servo.write(angle);
}

void loop() {
  // touch
  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH) {
    Serial.println("Presionado");
    moverMotor();

  }
  else {
    //digitalWrite(ledPin, LOW);
    Serial.println("No presionado");
  }
  delay(500);
}

void moverMotor() {
  for (angle = 10; angle < 180; angle++)
  {
    servo.write(angle);
    delay(1);
  }
  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 10; angle--)
  {
    servo.write(angle);
    delay(1);
  }
}
