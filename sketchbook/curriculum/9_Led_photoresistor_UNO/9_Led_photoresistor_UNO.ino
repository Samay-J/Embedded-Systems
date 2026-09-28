void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  int sensor = analogRead(A0);
  Serial.println(sensor);
  analogWrite(9, sensor);
}
