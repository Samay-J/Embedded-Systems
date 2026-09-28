void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(18, OUTPUT);
}

void loop() {
  int sensor = analogRead(5);
  Serial.println(sensor);
  analogWrite(18, sensor);
  delay(100);
}
