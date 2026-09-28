#include <DHT.h>

#define DHTPIN 4     // Digital pin connected to the DHT11 sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature and humidity from DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity to the serial monitor
  String payload = "{\"temperature\": " + String(t) + ", \"humidity\": " + String(h) + "}";
  Serial.println(payload);
  delay(2000);
}