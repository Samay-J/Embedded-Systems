# Sketchbook

Smaller sketches — practice exercises and one-off tests, not standalone projects.

- **`curriculum/`** — a 51-sketch progression: LEDs, buttons, sensors, and
  communication protocols (Parallel, UART, SPI, I2C, 433MHz RF, ESP-NOW), repeated
  across UNO → NANO → ESP32 → ESP8266 → STM32 as each board was picked up. Two-board
  exercises (e.g. `12_Parallel_Com_UNO_UNO`) need a sketch flashed to each of two
  boards — folders suffixed `B` are the second board's sketch.
- **`board-communication/`** — extra I2C/UART cross-board tests (Arduino↔ESP32,
  STM32↔ESP32).
- **`sensors/`** — standalone sensor reads: DHT11, MPU6050 (raw + DMP orientation,
  each with a Processing visualizer where one exists), a DHT-based weather station,
  and a fingerprint sensor (access-control style enroll/match).
- **`traffic-lights/`** — a traffic-light state machine, in an ESP and an Arduino variant.
- **`blynk-wifi-basic/`** — a minimal Blynk-controlled GPIO toggle. Needs
  `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`, `YOUR_BLYNK_TEMPLATE_ID`, and
  `YOUR_BLYNK_AUTH_TOKEN`.
- **`esp8266-blink/`** — an ESP8266 AT-command WiFi join + blink test. Needs
  `YOUR_WIFI_SSID` / `YOUR_WIFI_PASSWORD` in the `AT+CWJAP` command.
- **`book-exercises/`** — motor controller, piezo sensor (plain + button-gated),
  potentiometer mood cue, temperature, and traffic lights — exercises worked through
  from an Arduino book.
