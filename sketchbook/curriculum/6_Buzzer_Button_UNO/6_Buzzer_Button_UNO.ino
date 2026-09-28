void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
}

void loop() {
  int pushed = digitalRead(2);
  Serial.println(pushed);
  if (pushed == LOW){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }
}
