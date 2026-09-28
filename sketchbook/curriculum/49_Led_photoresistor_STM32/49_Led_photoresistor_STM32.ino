void setup() {
  Serial.begin(9600);
  pinMode(PA0, INPUT);
  pinMode(PA1, OUTPUT);
}

void loop() {
  int sensor = analogRead(PA0);
  Serial.println(sensor);
  analogWrite(PA1, sensor);
}
