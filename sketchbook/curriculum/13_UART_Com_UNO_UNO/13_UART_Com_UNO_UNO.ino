#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX (only TX used here)

void setup() {
  mySerial.begin(9600);  // Start software serial
}

void loop() {
  int value = random(0, 256);
  mySerial.println(value);  // Send value to Uno-B
  delay(1000);
}
