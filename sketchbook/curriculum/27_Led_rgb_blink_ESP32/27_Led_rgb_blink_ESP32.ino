void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  analogWrite(0,255);
  for (int i =0;i <=255; i ++)
  {
    analogWrite(0,255-i);
    analogWrite(2, i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(2,255-i);
    analogWrite(4,i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(4,255-i);
    analogWrite(0,i);
    delay(10);
  }
}