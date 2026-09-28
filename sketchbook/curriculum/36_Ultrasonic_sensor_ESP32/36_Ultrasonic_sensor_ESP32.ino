void setup() {
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  long duration, inches, cm;
  digitalWrite(0, LOW);
  delayMicroseconds(2);
  digitalWrite(0, HIGH);
  delayMicroseconds(5);
  digitalWrite(0, LOW);

  duration = pulseIn(2, HIGH);

  inches = duration /74/2;
  cm = duration /29/2;

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}
