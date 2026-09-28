void setup() {
  Serial.begin(9600);
  pinMode(PC13, OUTPUT);
}

void loop() {
  Serial.println("Working");
  digitalWrite(PC13, HIGH);
  delay(1000);
  digitalWrite(PC13, LOW);
  delay(1000);
}
