void setup() {
  Serial.begin(9600);
  pinMode(0, OUTPUT);
}

void loop() {
  for (int i=0; i<=255; i++)
  {
    analogWrite(0, i);
    delay(10);
  }
  analogWrite(0, 0);
  delay(2000);
  Serial.println("*****************");
}
