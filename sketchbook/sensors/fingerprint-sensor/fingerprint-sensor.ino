#include <Adafruit_Fingerprint.h>

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
}
