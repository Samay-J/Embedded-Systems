#include<Servo.h>
Servo myservo; 
void setup() {
  myservo.attach(PA1);
}

void loop() {
  for (int i=0;i<=180;i+=15){
    myservo.write(i);
    delay(100);
  }
  for (int i=180;i>=0;i-=15){
    myservo.write(i);
    delay(100);
  }
}
