// Parallel Communication - Transmitter (Uno A)

int dataPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};  
int strobePin = 10;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(dataPins[i], OUTPUT);
  }
  pinMode(strobePin, OUTPUT);
  digitalWrite(strobePin, LOW);
}

void loop() {
  byte value = random(0, 256); // generate random 8-bit number
  
  // put value on data pins
  for (int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], (value >> i) & 1);
  }

  // send strobe pulse
  digitalWrite(strobePin, HIGH);
  delayMicroseconds(10);
  digitalWrite(strobePin, LOW);
  
  delay(1000);
}
