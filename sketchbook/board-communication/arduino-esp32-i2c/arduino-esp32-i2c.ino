#include <Wire.h>

void setup() {
  // Start I2C communication
  Wire.begin();  // Default is SDA (A4) and SCL (A5)
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(8);  // Address of the ESP32 (choose a number between 0 and 127)
  Wire.write("Hello ESP32");
  Wire.endTransmission();
  delay(1000);
}
