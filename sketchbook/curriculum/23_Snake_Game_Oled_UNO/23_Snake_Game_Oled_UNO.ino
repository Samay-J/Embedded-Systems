#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Buttons
#define PIN_UP    2
#define PIN_DOWN  3
#define PIN_LEFT  4
#define PIN_RIGHT 5

// Grid settings
#define CELL 8
#define GRID_W (SCREEN_WIDTH / CELL)
#define GRID_H (SCREEN_HEIGHT / CELL)

// Snake
int snakeX[128], snakeY[128];
int snakeLen = 1;
int dx = 1, dy = 0; // start moving right

// Food
int foodX, foodY;

// Game state
bool gameOver = false;

void setup() {
  pinMode(PIN_UP, INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) for(;;);

  // start snake in middle
  snakeX[0] = GRID_W / 2;
  snakeY[0] = GRID_H / 2;

  randomSeed(analogRead(A0));
  placeFood();
}

void loop() {
  if (gameOver) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 30);
    display.println("GAME OVER");
    display.display();
    delay(2000);
    resetGame();
    return;
  }

  readInput();
  moveSnake();
  drawGame();
  delay(200);
}

void readInput() {
  if (digitalRead(PIN_UP) == LOW)    { dx = 0; dy = -1; }
  if (digitalRead(PIN_DOWN) == LOW)  { dx = 0; dy = 1; }
  if (digitalRead(PIN_LEFT) == LOW)  { dx = -1; dy = 0; }
  if (digitalRead(PIN_RIGHT) == LOW) { dx = 1; dy = 0; }
}

void moveSnake() {
  // shift body
  for (int i = snakeLen - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  // move head
  snakeX[0] += dx;
  snakeY[0] += dy;

  // wall collision
  if (snakeX[0] < 0 || snakeX[0] >= GRID_W || snakeY[0] < 0 || snakeY[0] >= GRID_H) {
    gameOver = true;
    return;
  }

  // self collision
  for (int i = 1; i < snakeLen; i++) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      gameOver = true;
      return;
    }
  }

  // eat food
  if (snakeX[0] == foodX && snakeY[0] == foodY) {
    if (snakeLen < 128) snakeLen++;
    placeFood();
  }
}

void drawGame() {
  display.clearDisplay();
  // draw snake
  for (int i = 0; i < snakeLen; i++) {
    display.fillRect(snakeX[i]*CELL, snakeY[i]*CELL, CELL, CELL, SSD1306_WHITE);
  }
  // draw food
  display.fillRect(foodX*CELL, foodY*CELL, CELL, CELL, SSD1306_WHITE);
  display.display();
}

void placeFood() {
  foodX = random(0, GRID_W);
  foodY = random(0, GRID_H);
}

void resetGame() {
  snakeLen = 1;
  dx = 1; dy = 0;
  snakeX[0] = GRID_W / 2;
  snakeY[0] = GRID_H / 2;
  gameOver = false;
  placeFood();
}
