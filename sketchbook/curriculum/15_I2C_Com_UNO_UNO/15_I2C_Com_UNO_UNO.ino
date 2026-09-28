#include <Wire.h>

void setup() {
  Wire.begin();        // Join I2C bus as Master
  Serial.begin(9600);
}

void loop() {
  byte dataToSend = random(0, 256);
  Wire.beginTransmission(8);  // Address of Slave
  Wire.write(dataToSend);
  Wire.endTransmission();
  Serial.print("Sent: ");
  Serial.println(dataToSend);
  delay(1000);
}
