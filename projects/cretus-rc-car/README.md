# Cretus RC Car

An ESP-NOW controlled RC car project, built up in stages across two ESP32s plus an
Arduino for pedal/sensor input.

- **`transmitter-gyro-steering/`** — handheld ESP32 transmitter; reads an MPU6050 and
  sends steering data over ESP-NOW.
- **`receiver-servo-motor/`** — onboard ESP32 receiver; takes the ESP-NOW steering
  data and drives the steering servo + drive motor.
- **`bldc-motor-control/`** — standalone ESC/BLDC arming and throttle test.
- **`ps4-controller-bldc/`** — alternate control scheme: a PS4 controller (via
  Bluepad32) driving the ESC and steering servo directly, no transmitter/receiver pair
  needed.
- **`oled-drift-display/`** — an SSD1306 OLED speedometer/drift-angle display.
- **`throttle-pedal/`** — analog throttle pedal reading (potentiometer), mapped to 0–100%.
- **`load-cell-sensor/`** — analog load-cell reading for pedal force / weight feedback.

No WiFi credentials or cloud services are involved — ESP-NOW pairs boards directly by
MAC address, configured at flash time in the Arduino IDE serial monitor output.
