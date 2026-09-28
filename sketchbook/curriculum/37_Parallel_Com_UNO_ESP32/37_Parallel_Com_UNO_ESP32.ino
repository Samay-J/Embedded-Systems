#define DATA_PINS 8
int dataPins[DATA_PINS] = {2,3,4,5,6,7,8,9}; // D2-D9 as data bus
int strobePin = 10; // Signal to ESP32 that data is ready
int ackPin = 11;    // Acknowledge from ESP32

void setup() {
  Serial.begin(115200);

  // Set data pins as OUTPUT
  for(int i = 0; i < DATA_PINS; i++) pinMode(dataPins[i], OUTPUT);

  // Set control pins
  pinMode(strobePin, OUTPUT);
  pinMode(ackPin, INPUT);
  
  digitalWrite(strobePin, LOW); // Ensure strobe is LOW initially
}

void loop() {
  byte dataToSend = random(0, 256); // Example data, can be sensor value

  // Write data to data pins
  for(int i = 0; i < DATA_PINS; i++){
    digitalWrite(dataPins[i], (dataToSend >> i) & 1);
  }

  // Pulse strobe to notify ESP32
  digitalWrite(strobePin, HIGH);
  delayMicroseconds(10); // Short pulse
  digitalWrite(strobePin, LOW);

  // Wait for acknowledgment from ESP32
  while(digitalRead(ackPin) == LOW);

  Serial.print("Sent: "); Serial.println(dataToSend);

  delay(500); // Delay between sends
}
