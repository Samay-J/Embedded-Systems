#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Servo settings
Servo myServo;
#define SERVOPIN 9

// Potentiometer pin
#define POTPIN A0

void setup() {
  Serial.begin(9600);

  myServo.attach(SERVOPIN);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  // Read potentiometer
  int potValue = analogRead(POTPIN); // 0 - 1023
  int angle = map(potValue, 0, 1023, 0, 180); // Map to 0-180 degrees

  // Move servo
  myServo.write(angle);

  // Debugging
  Serial.print("Pot Value: "); Serial.print(potValue);
  Serial.print(" => Angle: "); Serial.println(angle);

  // --- Display on OLED ---
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.print("Angle: ");
  display.print(angle);
  display.print(" deg");
  display.display();

  delay(100); // Small delay for smooth motion
}
