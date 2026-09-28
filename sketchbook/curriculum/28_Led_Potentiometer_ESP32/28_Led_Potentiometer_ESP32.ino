void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  int pot = analogRead(2);
  int bright = pot*255/1023;
  Serial.println(bright);
  analogWrite(0, bright);
}
