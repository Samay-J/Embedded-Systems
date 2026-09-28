void setup() {
  pinMode(PA1, OUTPUT);
  pinMode(PA0, INPUT);
  pinMode(PA13, OUTPUT);
}

void loop() {
  long duration, inches, cm;
  digitalWrite(PA13, LOW);
  digitalWrite(PA1, LOW);
  delayMicroseconds(2);
  digitalWrite(PA1, HIGH);
  delayMicroseconds(5);
  digitalWrite(PA1, LOW);

  duration = pulseIn(PA0, HIGH);

  inches = duration /74/2;
  cm = duration /29/2;
  digitalWrite(PA13, HIGH);
  delay(cm*100);
  delay(100);
}
