void setup() {
  Serial.begin(9600);
  pinMode(PA0, INPUT_PULLUP);
  pinMode(PA1, OUTPUT);
}

void loop() {
  int pushed = digitalRead(PA0);
  Serial.println(pushed);
  if (pushed == LOW){
    digitalWrite(PA1, HIGH);
  }
  else{
    digitalWrite(PA1, LOW);
  }
}
