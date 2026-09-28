#include <Wire.h>

#define SLAVE_ADDR 8

// Called when master writes data to ESP32
void receiveEvent(int howMany) {
  Serial.print("Received from Uno: ");
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}

// Called when master requests data from ESP32
void requestEvent() {
  const char reply[] = "Hello Uno";              // Byte array
  Wire.write((uint8_t*)reply, sizeof(reply)-1); // Send array without null terminator
}

void setup() {
  Serial.begin(9600); // Debug
  Wire.begin(21, 22, SLAVE_ADDR); // SDA=21, SCL=22, address=8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.println("ESP32 I2C Slave Ready");
}

void loop() {
  // Nothing needed here; callbacks handle communication
  delay(100);
}
