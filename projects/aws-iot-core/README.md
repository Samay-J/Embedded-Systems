# AWS IoT Core

ESP32 reading a DHT sensor and publishing telemetry to **AWS IoT Core** over MQTT/TLS,
using WiFiClientSecure + a device certificate for mutual auth.

## Setup

1. Copy `secrets.example.h` to `secrets.h` in this folder (gitignored, so your real
   values never get committed).
2. Fill in: `WIFI_SSID`, `WIFI_PASSWORD`, `AWS_IOT_ENDPOINT` (from your AWS IoT Core
   console), and your device's `AWS_CERT_CRT` (device certificate) and
   `AWS_CERT_PRIVATE` (private key), generated when you create a Thing in AWS IoT Core.
3. `AWS_CERT_CA` (the Amazon Root CA) is already filled in — it's public and doesn't
   need changing.
