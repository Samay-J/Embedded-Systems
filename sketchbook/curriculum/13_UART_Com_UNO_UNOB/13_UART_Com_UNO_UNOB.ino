#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX (only RX used here)

void setup() {
  Serial.begin(9600);      // USB Serial Monitor
  mySerial.begin(9600);    // SoftwareSerial receive
}

void loop() {
  if (mySerial.available()) {
    int value = mySerial.parseInt();
    Serial.print("Received Value: ");
    Serial.println(value);
  }
}
