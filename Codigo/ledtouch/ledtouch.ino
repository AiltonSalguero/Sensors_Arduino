int pinLED = 13;
int pinTouch = 8;

void setup() {
 pinMode (pinLED, OUTPUT);
 pinMode (pinTouch, INPUT);
}

void loop() {
 digitalWrite (pinLED, digitalRead (pinTouch)); 
}
