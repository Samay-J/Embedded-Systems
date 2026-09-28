# Cloud Telemetry Dashboard

DHT11/DHT22 sensor readings pushed to a cloud dashboard, repeated across every board
and backend combination that got tried.

## `thingsboard/`

MQTT telemetry to [ThingsBoard](https://thingsboard.cloud), one sketch per
board/sensor combo:

- `arduino-dht11/`, `esp32-dht11/`, `esp8266-dht11/` — DHT11 humidity/temperature
- `esp32-dht22/` — DHT22 variant
- `esp32-basic-mqtt/`, `esp8266-basic-mqtt/` — bare MQTT connectivity, no sensor
- `esp32-telegram-thingsboard/` — ESP32 toggling GPIO state via ThingsBoard RPC

Each needs `ssid` / `password` and a ThingsBoard device **access token** filled in at
the top of the `.ino` file (marked `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`,
`YOUR_THINGSBOARD_ACCESS_TOKEN`).

## `influxdb-telegraf/`

`esp8266-multiboard-influxdb/` — pushes WiFi RSSI to an InfluxDB Cloud bucket
(compiles for both ESP32 and ESP8266). Needs `WIFI_SSID`, `WIFI_PASSWORD`,
`INFLUXDB_TOKEN`, and `INFLUXDB_ORG` filled in.
