# GPS Tracker

Three independent takes on GPS tracking:

- **`esp32-mqtt-gps/`** — ESP32 + a GPS module (TinyGPSPlus over Serial1), publishing
  lat/lng over MQTT to a ThingsBoard device. Fill in `YOUR_WIFI_SSID`,
  `YOUR_WIFI_PASSWORD`, and `YOUR_THINGSBOARD_ACCESS_TOKEN`.
- **`arduino-gps-logger/`** — Arduino UNO + GPS module over SoftwareSerial, logging
  coordinates to the serial monitor. No network/credentials needed.
- **`sim808-4g-blynk-tracker/`** — a SIM808 4G/GPRS module reporting GPS position to
  Blynk Cloud over HTTP, for a fully cellular (no WiFi) tracker. Fill in your Blynk
  device token where the code says `ADD YOU TOKEN HERE`.
