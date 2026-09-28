void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //RED
  digitalWrite(7,HIGH);
  delay(5000);
  digitalWrite(7,LOW);

  //YELLOW
  digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);

  //GREEN
  digitalWrite(9,HIGH);
  delay(5000);
  digitalWrite(9,LOW);
}
