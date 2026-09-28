#include <Wire.h>

String receivedData = "";

void setup() {
  Wire.begin(8);  // ESP32 address (same as in the master code)
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Received: ");
  Serial.println(receivedData);
  receivedData = "";
  delay(1000);  // Allow the I2C communication to occur
}

void receiveEvent(int bytes) {
  while (Wire.available()) {
    char c = Wire.read();
    receivedData += c;
  }
}
