void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  analogWrite(9,255);
  for (int i =0;i <=255; i ++)
  {
    analogWrite(9,255-i);
    analogWrite(10, i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(10,255-i);
    analogWrite(11,i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(11,255-i);
    analogWrite(9,i);
    delay(10);
  }
}