void setup() {
  pinMode(PC14, OUTPUT);
}

void loop() {
  digitalWrite(PC14, HIGH);
  delay(500);
  digitalWrite(PC14, LOW);
  delay(500);
}
