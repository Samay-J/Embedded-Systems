
void setup() {
  // put your setup code here, to run once:
  pinmode(17,OUTPUT);
  pinmode(18,OUTPUT);
  pinmode(19,OUTPUT);
  pinmode(20,OUTPUT);
  pinmode(21,OUTPUT);
  pinmode(22,OUTPUT);
  pinmode(23,OUTPUT);
  pinmode(24,OUTPUT);
  pinmode(25,OUTPUT);
  pinmode(26,OUTPUT);
  pinmode(27,OUTPUT);
  pinmode(28,OUTPUT);
  defaultWrite(17,LOW);
  defaultWrite(18,LOW);
  defaultWrite(19,LOW);
  defaultWrite(20,LOW);
  defaultWrite(21,LOW);
  defaultWrite(22,LOW);
  defaultWrite(23,LOW);
  defaultWrite(24,LOW);
  defaultWrite(25,LOW);
  defaultWrite(26,LOW);
  defaultWrite(27,LOW);
  defaultWrite(28,LOW);
  delay(1000);

  //All red lights
  defaultWrite(17,HIGH);
  defaultWrite(22,HIGH);
  defaultWrite(23,HIGH);
  defaultWrite(28,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Light 1
  defaultWrite(23,LOW);
  defaultWrite(24,HIGH);
  delay(1000);
  defaultWrite(24,LOW);
  defaultWrite(25,HIGH);
  delay(5000);
  defaultWrite(25,LOW);
  defaultWrite(23,HIGH);

  //Light 2
  defaultWrite(28,LOW);
  defaultWrite(27,HIGH);
  delay(1000);
  defaultWrite(27,LOW);
  defaultWrite(26,HIGH);
  delay(5000);
  defaultWrite(26,LOW);
  defaultWrite(28,HIGH);

  //Light 3
  defaultWrite(17,LOW);
  defaultWrite(18,HIGH);
  delay(1000);
  defaultWrite(18,LOW);
  defaultWrite(19,HIGH);
  delay(5000);
  defaultWrite(19,LOW);
  defaultWrite(17,HIGH);

  //Light 4
  defaultWrite(22,LOW);
  defaultWrite(21,HIGH);
  delay(1000);
  defaultWrite(21,LOW);
  defaultWrite(20,HIGH);
  delay(5000);
  defaultWrite(20,LOW);
  defaultWrite(22,HIGH);

}
