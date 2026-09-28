#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "thingsboard.cloud";
const int mqtt_port = 1883;
const char* mqtt_user = "Sovereign";
const char* mqtt_password = "123";

unsigned long lastMsg = 0; // Declare lastMsg here
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("Wifi connected");
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);

  while (!client.connect("Sovereign25", mqtt_user, mqtt_password)) {
    delay(1000);
  }
  Serial.println("Mqtt connected");
}

void loop() {
  if (!client.connected()) {
    client.connect("Sovereign25", mqtt_user, mqtt_password);
  }
  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  if (millis() - lastMsg > 1000) {
    lastMsg = millis();
    String payload = "{\"temperature\": " + String(t) + ", \"humidity\": " + String(h) + "}";
    client.publish("v1/devices/me/telemetry", payload.c_str(), true);
    Serial.println(payload);
  }
}

void mqttCallback(char* topic, byte* payload, int length) {
  // Handle incoming messages from ThingsBoard
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}