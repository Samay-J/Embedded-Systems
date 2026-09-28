const int loadPin = A0;
const float vRef = 5.0;
const int adcMax = 1023;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(loadPin);
  float voltage = (raw * vRef) / adcMax;
  float force;
  float weight;   

  if (raw < 12) {
    weight = 0.0;
    force = 0.0;
  } else {
    weight = (raw - 10) * 12.5;
    force = weight*9.81;
  }

  Serial.print("ADC: ");
  Serial.print(raw);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 3);
  Serial.print("  Weight: ");
  Serial.println(weight, 3);
  Serial.print("  Force: ");
  Serial.println(force, 3);
  delay(100);
}