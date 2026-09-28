void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(4, OUTPUT);
}

void loop() {
  int pushed = digitalRead(0);
  Serial.println(pushed);
  if (pushed == LOW){
    tone(4, 440); //A4
    delay(500);
    tone(4, 494); //B4
    delay(500);
    tone(4, 523); //C4
    delay(500);
    tone(4, 587); //D4
    delay(500);
    tone(4, 659); //E4
    delay(500);
    noTone(4);
    delay(1000);
    tone(4, 659); //E4
    delay(500);
    tone(4, 587); //D4
    delay(500);
    tone(4, 523); //C4
    delay(500);
    tone(4, 494); //B4
    delay(500);
    tone(4, 440); //A4
    delay(500);
  }
  else{
    noTone(4);
  }
}
