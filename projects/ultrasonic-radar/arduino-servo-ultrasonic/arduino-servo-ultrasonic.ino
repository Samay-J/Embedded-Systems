#include <Servo.h>. 
long duration;
int distance;
Servo myServo; 
void setup() {
  pinMode(10, OUTPUT); 
  pinMode(11, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() {
  for(int i=15;i<=165;i++){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();  
    Serial.print(i);
    Serial.print(","); 
    Serial.print(distance); 
    Serial.print("."); 
  }
  for(int i=165;i>15;i--){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    Serial.println();
  }
}
int calculateDistance(){ 
  
  digitalWrite(10, LOW); 
  delayMicroseconds(2);
  digitalWrite(10, HIGH); 
  delayMicroseconds(10);
  digitalWrite(10, LOW);
  duration = pulseIn(11, HIGH); 
  distance= duration*0.017;
  return distance;
}