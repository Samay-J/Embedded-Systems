void setup() {
  Serial.begin(9600);
  pinMode(PA0, INPUT_PULLUP);
  pinMode(PA1, OUTPUT);
}

void loop() {
  int pushed = digitalRead(PA0);
  Serial.println(pushed);
  if (pushed == LOW){
    tone(PA1, 440); //A4
    delay(500);
    tone(PA1, 494); //B4
    delay(500);
    tone(PA1, 523); //C4
    delay(500);
    tone(PA1, 587); //D4
    delay(500);
    tone(PA1, 659); //E4
    delay(500);
    noTone(PA1);
    delay(1000);
    tone(PA1, 659); //E4
    delay(500);
    tone(PA1, 587); //D4
    delay(500);
    tone(PA1, 523); //C4
    delay(500);
    tone(PA1, 494); //B4
    delay(500);
    tone(PA1, 440); //A4
    delay(500);
  }
  else{
    noTone(PA1);
  }
}
