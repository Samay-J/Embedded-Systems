void setup() {
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(2);
  if (switchState == HIGH)
  {
    Serial.println("High");
    digitalWrite(9, HIGH);
  }
  else
  {
    Serial.println("Low");
    digitalWrite(9, LOW);
  }
  delay(1000);
}
