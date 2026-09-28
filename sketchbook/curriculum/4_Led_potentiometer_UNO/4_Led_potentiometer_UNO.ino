void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int pot = analogRead(A0);
  Serial.println(pot);
  int bright = map(pot, 0, 1023, 0, 255);
  analogWrite(10, bright);
}
