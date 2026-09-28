#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Pins for GPS module
#define RXPin 11
#define TXPin 12
#define GPSBaud 9600

// Pins for ESP32
#define ESP_TX 2
#define ESP_BAUD 9600

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
SoftwareSerial espSerial(ESP_TX, -1); // -1 since ESP RX doesn't need to be emulated

void setup() {
  Serial.begin(9600);           // Monitor output
  gpsSerial.begin(GPSBaud);     // GPS module
  espSerial.begin(ESP_BAUD);    // Communication with ESP32
  
  Serial.println("GPS to ESP32 setup complete.");
}

void loop() {
  //while (gpsSerial.available() > 0) {
    //char gpsChar = gpsSerial.read();
    //if (gps.encode(gpsChar)) {
      //if (gps.location.isUpdated()) {
        //float latitude = gps.location.lat();
        //float longitude = gps.location.lng();
        float latitude = 103.987654;
        float longitude = -124.987654;

        // Format data as JSON string
        String jsonString = String("{\"latitude\":") + String(latitude, 6) + String(",\"longitude\":") + String(longitude, 6) + String("}");
        Serial.println(jsonString);
        espSerial.println(jsonString);
      //}
    //}
  //}
}
