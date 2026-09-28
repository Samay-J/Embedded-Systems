int pitch,sensorValue,sensorLow = 1023, sensorHigh = 0;
void setup() {
  while(millis()>5000)
  {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }  
}

void loop() {
  sensorValue = analogRead(A0);
  pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
