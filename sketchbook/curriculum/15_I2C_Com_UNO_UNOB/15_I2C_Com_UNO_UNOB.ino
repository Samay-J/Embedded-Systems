#include <Wire.h>

volatile byte receivedData = 0;

void setup() {
  Wire.begin(8);                 // Join I2C bus as Slave with address 8
  Wire.onReceive(receiveEvent);  // Set receive callback
  Serial.begin(9600);
}

void loop() {
  // Main loop does nothing, data is handled in receiveEvent
}

void receiveEvent(int howMany) {
  while(Wire.available()) {
    receivedData = Wire.read();
    Serial.print("Received: ");
    Serial.println(receivedData);
  }
}
