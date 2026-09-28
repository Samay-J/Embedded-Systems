void setup() {
  Serial.begin(9600); // Communication with ESP32
}

void loop() {
  byte dataToSend = random(0, 256);
  Serial.write(dataToSend); // Send one byte
  delay(500);
}
