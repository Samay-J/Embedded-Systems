void setup() {
  Serial.begin(9600);
  pinMode(PA1, OUTPUT);
}

void loop() {
  for (int i=0; i<=255; i++)
  {
    analogWrite(PA1, i);
    delay(10);
  }
  analogWrite(PA1, 0);
  delay(2000);
  Serial.println("*****************");
}
