#include <TinyGPSPlus.h>
#include <WiFi.h>
#include <PubSubClient.h>

//Wifi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password="YOUR_WIFI_PASSWORD";

//Thingsboard MQTT settings
const char* mqttserver="thingsboard.cloud";
const int mqttport = 1883;
const char* accessToken = "YOUR_THINGSBOARD_ACCESS_TOKEN";

//intialize mqtt client
WiFiClient wifiClient;
PubSubClient client(wifiClient);

//gps setup for serial1
#define GPS_TX_PIN 12
#define GPS_RX_PIN 14

TinyGPSPlus gps;
unsigned long timestamp;
float lat = 100.32467;
float lng = 34.76895;

//function to connect to wifi (it will connect on its own)
void setup_wifi(){
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected. ");
}

// Function to connect to ThingsBoard MQTT server
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to ThingsBoard...");
    if (client.connect("ESP32", accessToken, "")) {
      Serial.println("Connected.");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds.");
      delay(5000);
    }
  }
}

//Function to get GPS data
void get_gps_data(){
  Serial.println("getting gps data:");
  while(Serial1.available()>0){
    gps.encode(Serial1.read());
  }
  //check if gps location is valid
  if(gps.location.isValid()){
    lat= gps.location.lat();
    lng= gps.location.lng();
    Serial.print("Latitude= ");
    Serial.println(lat, 6);
    Serial.print("Longitude= ");
    Serial.println(lng, 6);
  } else{
      Serial.println(F("Invalid GPS data"));
  }
    Serial.println();
}
    


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, GPS_TX_PIN, GPS_RX_PIN);// for  gps
  setup_wifi();
  client.setServer(mqttserver, mqttport);
}


void loop() {
    if (!client.connected()) {
    reconnect();
  }
  client.loop();

  get_gps_data();//function made by us
  delay(5000);
  //create json payload
  String payload="{";
  payload += "\"latitude\":"; payload += lat; payload += ",";
  payload += "\"longitude\":"; payload += lng; payload += "}";

  Serial.print("Publishing data: ");
  Serial.println(payload);
  client.publish("v1/devices/me/telemetry", payload.c_str());

  delay(10000);
}