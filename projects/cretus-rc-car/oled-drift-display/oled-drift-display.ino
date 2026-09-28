#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Simulated speed
int speed = 0;  // 0-100%

// Speedometer parameters
const int speedX = 64;   // center x
const int speedY = 40;   // center y
const int speedR = 38;   // radius (max to fill screen)

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // try 0x3D if 0x3C doesn't work
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  display.clearDisplay();
  display.display();
  delay(100);
}

// Draw speedometer arc with tick marks
void drawSpeedometerArc() {
  for(int i=-180; i<=0; i+=10){   // tick every 10 degrees
    float rad = i * 3.1416 / 180.0;
    int x1 = speedX + (speedR-3) * cos(rad);
    int y1 = speedY + (speedR-3) * sin(rad);
    int x2 = speedX + speedR * cos(rad);
    int y2 = speedY + speedR * sin(rad);
    display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
  }
  display.drawCircle(speedX, speedY, speedR, SSD1306_WHITE);
}

// Draw needle for speed
void drawSpeedNeedle(int speedVal){
  float angle = map(speedVal, 0, 100, -180, 0);   
  float rad = angle * 3.1416 / 180.0;
  int nx = speedX + (speedR-3) * cos(rad);
  int ny = speedY + (speedR-3) * sin(rad);
  display.drawLine(speedX, speedY, nx, ny, SSD1306_WHITE);
}

// Draw digital speed in center
void drawDigitalSpeed(int speedVal){
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(speedX-15, speedY-15);
  display.print(speedVal);
  display.print("%");
}

// Draw full dashboard
void drawDashboard(int speedVal){
  display.clearDisplay();
  drawSpeedometerArc();
  drawSpeedNeedle(speedVal);
  drawDigitalSpeed(speedVal);
  display.display();
}

void loop() {
  // Simulate speed (0-100%)
  speed = (millis()/100) % 101;

  drawDashboard(speed);
  delay(50);
}
