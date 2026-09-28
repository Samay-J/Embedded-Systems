#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 2     // Digital pin connected to the DHT22
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  float temp = dht.readTemperature();   // Celsius
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Display on OLED
  // Clear OLED before writing new data
  display.clearDisplay();

  // Clear OLED before writing new data
  display.clearDisplay();

  // Display temperature (line 1)
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0); // Start near top
  display.print("Temp: ");
  display.print(temp);
  display.print(" C"); // Keep on same line

  // Display humidity (line 2)
  display.setCursor(0, 30); // Move down ~30 pixels for next line
  display.print("Hum: ");
  display.print(hum);
  display.print(" %"); // Keep on same line

  // Show on OLED
  display.display();

  delay(2000);
}
