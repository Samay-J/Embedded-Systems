#include <ESP32Servo.h>

Servo esc;
Servo motor;

int escPin = 12;
int motorPin = 14;

void setup() {
  Serial.begin(115200);
  esc.attach(escPin);
  motor.attach(motorPin);
  Serial.println("Arming...");
  esc.writeMicroseconds(1000);  // Send low throttle immediately
  delay(4000);                  // Wait for ESC to arm
  Serial.println("Armed!");
  delay(2000);
}

void loop() {
  // Slowly ramp motor
  for (int val = 1000; val <= 2000; val += 10) {
    esc.writeMicroseconds(val);
    Serial.println(val);
    delay(20);
  }
  for (int i=0;i<=180;i+=15){
    motor.write(i);
    Serial.println(i);
    delay(100);
  }
  for (int val = 2000; val >= 1000; val -= 10) {
    esc.writeMicroseconds(val);
    delay(20);
  }
  for (int i=180;i>=0;i-=15){
    motor.write(i);
    Serial.println(i);
    delay(100);
  }
}
