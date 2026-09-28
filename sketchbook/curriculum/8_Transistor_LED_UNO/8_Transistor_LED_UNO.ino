void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  for (int i=0; i<=255; i++)
  {
    analogWrite(3, i);
    delay(10);
  }
  analogWrite(3, 0);
  delay(2000);
  Serial.println("*****************");
}
