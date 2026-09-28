// Parallel Communication - Receiver (Uno B)

int dataPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};  
int strobePin = 10;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(dataPins[i], INPUT);
  }
  pinMode(strobePin, INPUT);
}

void loop() {
  if (digitalRead(strobePin) == HIGH) {
    byte value = 0;
    for (int i = 0; i < 8; i++) {
      if (digitalRead(dataPins[i])) {
        value |= (1 << i);
      }
    }
    Serial.print("Received Value: ");
    Serial.println(value);

    // wait for strobe to go LOW before next read
    while (digitalRead(strobePin) == HIGH);
  }
}
