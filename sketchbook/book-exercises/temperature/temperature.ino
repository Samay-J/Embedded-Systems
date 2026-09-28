#include<DHT.h>
DHT dht(2, DHT22);
float temp;
float humid;
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  humid = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C ,Humidity: ");
  Serial.print(humid);
  Serial.println("%");
  delay(2000);
}
