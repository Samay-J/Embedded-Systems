#include <HardwareSerial.h>

HardwareSerial MySerial(2); // Use UART1

void setup() {
  Serial.begin(115200);      // For debugging
  MySerial.begin(9600, SERIAL_8N1, 16, 17); // RX = GPIO16, TX = GPIO17
}

void loop() {
  if (MySerial.available()) {
    byte received = MySerial.read();
    Serial.print("Received: ");
    Serial.println(received);
  }
}
