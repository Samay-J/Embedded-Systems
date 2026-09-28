void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
}

void loop() {
  int pushed = digitalRead(2);
  Serial.println(pushed);
  if (pushed == LOW){
    tone(9, 440); //A4
    delay(500);
    tone(9, 494); //B4
    delay(500);
    tone(9, 523); //C4
    delay(500);
    tone(9, 587); //D4
    delay(500);
    tone(9, 659); //E4
    delay(500);
    noTone(9);
    delay(1000);
    tone(9, 659); //E4
    delay(500);
    tone(9, 587); //D4
    delay(500);
    tone(9, 523); //C4
    delay(500);
    tone(9, 494); //B4
    delay(500);
    tone(9, 440); //A4
    delay(500);
  }
  else{
    noTone(9);
  }
}
