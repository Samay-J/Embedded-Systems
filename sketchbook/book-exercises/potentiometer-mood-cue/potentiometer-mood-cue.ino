#include<Servo.h>
Servo myServo;
int potVal, angle;
void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(A0);
  angle = map(potVal, 0, 1023, 0, 179);
  myServo.write(angle);
  delay(15);
}
