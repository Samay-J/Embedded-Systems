#define DATA_PINS 8
int dataPins[DATA_PINS] = {2,4,5,12,13,14,15,16}; // Safe GPIOs for ESP32
int strobePin = 17; // Data ready from Arduino
int ackPin = 18;    // Ack back to Arduino

void setup() {
  Serial.begin(115200);
  for(int i=0;i<DATA_PINS;i++) pinMode(dataPins[i], INPUT);
  pinMode(strobePin, INPUT);
  pinMode(ackPin, OUTPUT);
  digitalWrite(ackPin, LOW);
}

void loop() {
  if(digitalRead(strobePin) == HIGH){
    byte received = 0;
    for(int i=0;i<DATA_PINS;i++){
      received |= digitalRead(dataPins[i]) << i;
    }
    Serial.print("Received: "); Serial.println(received);

    // Send acknowledge
    digitalWrite(ackPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(ackPin, LOW);
  }
}
