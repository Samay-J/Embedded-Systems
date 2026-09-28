#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ThingsBoard.h>
#include <ArduinoJson.h>

#define GPIO13_PIN 13
#define GPIO12_PIN 12

// Deklarasi Variable dan Konstanta
String wifiSSID = "YOUR_WIFI_SSID";
String wifiPassword = "YOUR_WIFI_PASSWORD";

// Thingsboard Credential
String tbHost = "thingsboard.cloud";
String tbToken = "YOUR_THINGSBOARD_ACCESS_TOKEN";

WiFiClient client;
ThingsBoard tb(client);
PubSubClient mqtt(client);

boolean gpioState[] = {false, false};

// Deklarasi Fungsi
void connectWifi();
String randTemp();
String randHum();
void tbReconnect();
void on_message(const char *topic, byte *payload, unsigned int length);
void set_gpio_status(int pin, boolean enabled);
String get_gpio_status();

void setup()
{
    Serial.begin(9600);
    pinMode(GPIO12_PIN, OUTPUT);
    pinMode(GPIO13_PIN, OUTPUT);
    delay(10);
    connectWifi();
    mqtt.setServer(tbHost.c_str(), 1883);
    mqtt.setCallback(on_message);
}

void loop()
{
    if (!tb.connected())
    {
        tbReconnect();
    }

    float temp = randTemp().toDouble();
    float hum = randHum().toDouble();

    Serial.println("Sending data to Thingsboard");
    tb.sendTelemetryFloat("temperature", temp);
    tb.sendTelemetryFloat("humidity", hum);
    tb.loop();
    mqtt.loop();
    delay(1000);
}

String randTemp()
{
    float randDec = random(0, 99);
    randDec /= 100;
    int randVal = random(25, 30);
    return String(randVal + randDec);
}

String randHum()
{
    float randDec = random(0, 99);
    randDec /= 100;
    int randVal = random(40, 60);
    return String(randVal + randDec);
}

void tbReconnect()
{
    while (!tb.connected())
    {
        if (WiFi.status() != WL_CONNECTED)
        {
          connectWifi();
        }

        Serial.println("connecting to thingsboard ... ");
        if (tb.connect(tbHost.c_str(), tbToken.c_str()))
        {
            Serial.println("Thingsboard Connected!");
        }
        else
        {
            Serial.println("Thingsboard connection failed");
            Serial.println("Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void connectWifi()
{
    Serial.println("Connecting To Wifi");
    WiFi.begin(wifiSSID.c_str(), wifiPassword.c_str());
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println("Wifi Connected");
    Serial.println(WiFi.SSID());
    Serial.println(WiFi.RSSI());
    Serial.println(WiFi.macAddress());
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.gatewayIP());
    Serial.println(WiFi.dnsIP());
}

void on_message(const char *topic, byte *payload, unsigned int length)
{

    Serial.println("On message");

    char json[length + 1];
    strncpy(json, (char *)payload, length);
    json[length] = '\0';

    Serial.print("Topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
    Serial.println(json);
}

String get_gpio_status()
{
    // Prepare gpios JSON payload string
    StaticJsonDocument<200> jsonDoc;
    jsonDoc[String(GPIO13_PIN)] = gpioState[0] ? true : false;
    jsonDoc[String(GPIO12_PIN)] = gpioState[1] ? true : false;

    String json;
    serializeJson(jsonDoc, json);
    Serial.println(json);
    return json;
}