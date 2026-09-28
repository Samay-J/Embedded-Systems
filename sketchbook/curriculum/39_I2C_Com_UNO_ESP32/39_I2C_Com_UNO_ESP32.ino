#include <Wire.h>

void setup() {
  Wire.begin(); // Join I2C bus as master
  Serial.begin(9600); // Debug
}

void loop() {
  // --- Send data to ESP32 ---
  Wire.beginTransmission(8);   // Slave address = 8
  const char reply[] = "Helloesp 1";              // Byte array
  Wire.write((uint8_t*)reply, sizeof(reply)-1); // Send array without null terminator
  Wire.endTransmission();      // Stop condition

  Serial.println("Sent to ESP32: Hi ESP32");
  delay(500);

  // --- Request data back from ESP32 ---
  Wire.requestFrom(8, 9); // Request 9 bytes (length of "Hello Uno")
  Serial.print("Received from ESP32: ");
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();

  delay(1000);
}
