void setup()
{
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
}

void loop()
{
  analogWrite(PA1,255);
  for (int i =0;i <=255; i ++)
  {
    analogWrite(PA1,255-i);
    analogWrite(PA2, i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(PA2,255-i);
    analogWrite(PA3,i);
    delay(10);
  }
  for(int i=0;i<=255;i++)
  {
    analogWrite(PA3,255-i);
    analogWrite(PA1,i);
    delay(10);
  }
}