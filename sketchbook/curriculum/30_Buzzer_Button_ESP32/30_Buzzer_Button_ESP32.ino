void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(4, OUTPUT);
}

void loop() {
  int pushed = digitalRead(0);
  Serial.println(pushed);
  if (pushed == LOW){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
}
