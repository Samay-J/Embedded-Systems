#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID           "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME         "Radar"
#define BLYNK_AUTH_TOKEN            "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.virtualWrite(V6,
}

void loop() {
  Serial.println("Message Received: ");
  Serial.println(Serial2.readString());
  Blynk.run();
}
