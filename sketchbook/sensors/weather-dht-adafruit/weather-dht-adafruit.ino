#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
DHT dht(4, DHT11);
void setup() {
  Serial.begin(9600);
  Serial.println("Testing ");
}

void loop() {
  delay(3000);
  float t = dht.readTemperature();
  int h = dht.readHumidity();
  Serial.print('Temperature = ');
  Serial.print(h);
  Serial.print(' , Humidity = ');
  Serial.print(h);
  Serial.print('\n');
}
