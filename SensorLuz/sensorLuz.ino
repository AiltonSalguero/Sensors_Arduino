int ledPin=6;
int thresholdvalue=100;
void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(115200);
 
}
void loop(){
  int sensorValue=analogRead(1);
 
  if (sensorValue<thresholdvalue){
    digitalWrite(ledPin,HIGH);
    
  }else{
    digitalWrite(ledPin,LOW);
  }
  
  Serial.println(sensorValue);
  delay(300);
  
  
}
