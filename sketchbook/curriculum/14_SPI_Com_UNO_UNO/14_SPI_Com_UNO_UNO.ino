#include <SPI.h>

void setup() {
  pinMode(10, OUTPUT);   // SS pin must be OUTPUT
  digitalWrite(10, HIGH); // Deselect Slave initially
  SPI.begin();           // Start SPI as Master
}

void loop() {
  byte dataToSend = random(0, 256);  // Random number 0–255
  digitalWrite(10, LOW);             // Select Slave
  SPI.transfer(dataToSend);          // Send data
  digitalWrite(10, HIGH);            // Deselect Slave
  delay(1000);                        // Wait 1 second
}
