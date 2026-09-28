#include <SPI.h>

volatile byte receivedData = 0; // Store SPI data
volatile bool newData = false;  // Flag to indicate new data arrived

void setup() {
  pinMode(MISO, OUTPUT);    // Important: MISO must be OUTPUT
  SPI.begin();              // Start SPI as Slave
  SPI.attachInterrupt();    // Enable interrupt for SPI receive
  Serial.begin(9600);       // Serial Monitor
}

ISR(SPI_STC_vect) {
  receivedData = SPDR;      // Read received SPI data
  newData = true;           // Set flag
}

void loop() {
  if (newData) {           // Check if new data arrived
    Serial.print("Received: ");
    Serial.println(receivedData);
    newData = false;       // Reset flag
  }
}
