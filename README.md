# Embedded Systems

A collection of embedded/IoT projects — Arduino, ESP32, ESP8266, STM32 — built while
learning hardware communication protocols, sensor integration, and cloud telemetry.

## Projects

| Project | Boards | What it does |
|---|---|---|
| [`cloud-telemetry-dashboard`](projects/cloud-telemetry-dashboard) | Arduino, ESP32, ESP8266 | DHT11/DHT22 sensor data pushed to ThingsBoard (MQTT) and InfluxDB Cloud (Telegraf), across every board variant |
| [`aws-iot-core`](projects/aws-iot-core) | ESP32 | DHT sensor telemetry to AWS IoT Core over TLS (MQTT + client cert) |
| [`gps-tracker`](projects/gps-tracker) | ESP32, Arduino, SIM808 | GPS module readers (serial + MQTT) and a 4G/GPRS SIM808 tracker reporting to Blynk |
| [`ultrasonic-radar`](projects/ultrasonic-radar) | Arduino, ESP32 | Servo-mounted ultrasonic radar sweep with a Processing sweep-visualizer, plus an ESP32 + Blynk cloud-relay variant |
| [`esp32-gemini-assistant`](projects/esp32-gemini-assistant) | ESP32 | ESP32 calling the Google Gemini API over HTTPS |
| [`esp32-web-dashboard`](projects/esp32-web-dashboard) | ESP32 | ESP32-hosted web server and control page |

## sketchbook/

[`sketchbook/`](sketchbook) holds everything smaller: a 51-sketch curriculum working
through UNO → NANO → ESP32 → ESP8266 → STM32 (LEDs, sensors, comms protocols —
Parallel/UART/SPI/I2C/RF/ESP-NOW), plus standalone exercises (IMU reads, fingerprint
sensor, traffic lights, Blynk basics) and a set of book exercises.

## Configuring secrets

None of these sketches ship with real WiFi credentials or API keys — every sensitive
value is a placeholder like `YOUR_WIFI_SSID` or `YOUR_API_KEY`. Before flashing a
sketch, open it and fill in your own values directly, or (for `aws-iot-core`, which
uses a `secrets.example.h` template) copy it to `secrets.h`, fill it in, and it'll be
picked up automatically — `secrets.h` is gitignored so your real credentials never get
committed.

## Not included

A few things were deliberately left out of this repo rather than vendored:

- Third-party cloned tools that were used for experimentation (an ESP8266 deauther,
  an ESP32 WiFi pentesting tool, a Gemini API example repo, an Arduino examples
  collection) — these live upstream on GitHub already; re-hosting a copy here would
  just be stale duplication.
- Arduino libraries (Adafruit GFX/SSD1306/MPU6050, ESP32Servo, RadioHead, rc-switch,
  etc.) — install these via the Arduino Library Manager / PlatformIO as needed per
  sketch.
