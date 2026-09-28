# Ultrasonic Radar

A classic servo-mounted ultrasonic radar sweep, built up across a few variants:

- **`arduino-servo-ultrasonic/`** — Arduino UNO sweeping a servo + HC-SR04 ultrasonic
  sensor, printing distance-per-angle over serial.
- **`processing-visualizer/`** — a [Processing](https://processing.org) sketch that
  reads that serial output and draws the live radar sweep on a PC screen.
- **`esp32-servo-ultrasonic/`** — the same servo + ultrasonic hardware loop ported to
  ESP32, forwarding readings over `Serial2` to a second board.
- **`esp32-blynk-relay/`** — a second ESP32 that receives those `Serial2` readings and
  relays them to a Blynk dashboard. Needs `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`,
  `YOUR_BLYNK_TEMPLATE_ID`, and `YOUR_BLYNK_AUTH_TOKEN` filled in.
