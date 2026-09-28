int throttlePin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(throttlePin);

  // Convert to %
  float throttle = map(raw, 160, 875, 0, 100);
  throttle = constrain(throttle, 0, 100);

  Serial.print("Throttle: ");
  Serial.print(raw);
  Serial.println(" %");

  delay(20);
}
