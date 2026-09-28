void setup() {
  Serial.begin(9600);
  pinMode(PA0, INPUT);
  pinMode(PA1, OUTPUT);
}

void loop() {
  int pot = analogRead(PA0);
  Serial.println(pot);
  int bright = map(pot, 0, 1023, 0, 255);
  analogWrite(PA1, bright);
}
