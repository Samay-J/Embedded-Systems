#include<ESP32Servo.h>
Servo myservo; 
void setup() {
  Serial.begin(115200);
  myservo.attach(0);
}

void loop() {
  for (int i=0;i<=180;i+=15){
    myservo.write(i);
    Serial.println(i);
    delay(100);
  }
  for (int i=180;i>=0;i-=15){
    myservo.write(i);
    Serial.println(i);
    delay(100);
  }
}
