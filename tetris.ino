/**
 * http://adafru.it/1484
 */

#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

// colors
const uint16_t BLACK  = matrix.Color333(0, 0, 0);
const uint16_t GRAY   = matrix.Color333(1, 1, 1);
const uint16_t YELLOW = matrix.Color333(3, 2, 0);
const uint16_t BLUE   = matrix.Color333(0, 0, 1); // I
const uint16_t GREEN  = matrix.Color333(0, 1, 0); // T
const uint16_t ORANGE = matrix.Color333(3, 1, 0); // L
const uint16_t RED    = matrix.Color333(1, 0, 0); // Z + S
const uint16_t PURPLE = matrix.Color333(1, 0, 1); // O

const int SCORE_POINTS = 1;
const int SCORE_LINES  = 2;
const int SCORE_LEVELS = 3;

// variables
unsigned int  levels = 0;
unsigned int  lines  = 0;
unsigned long points = 0;


void setup() {
  matrix.begin();

  // draw the basic game setup

  matrix.fillScreen(BLACK);

  // bucket
  matrix.drawLine(1, 5, 1, 22, GRAY);
  matrix.drawLine(12, 5, 12, 22, GRAY);
  matrix.drawLine(2, 22, 11, 22, GRAY);

  // box for next item
  matrix.drawLine(20, 3, 25, 3, GRAY);
  matrix.drawLine(20, 8, 25, 8, GRAY);
  matrix.drawLine(20, 4, 20, 7, GRAY);
  matrix.drawLine(25, 4, 25, 7, GRAY);

  // lv (= level)
  matrix.drawLine(14, 10, 14, 15, GRAY);
  matrix.drawLine(16, 12, 16, 15, GRAY);
  matrix.drawLine(18, 12, 18, 13, GRAY);
  matrix.drawPixel(17, 14, GRAY);

  // ln (= lines)
  matrix.drawLine(14, 17, 14, 22, GRAY);
  matrix.drawLine(16, 19, 16, 22, GRAY);
  matrix.drawLine(18, 20, 18, 22, GRAY);
  matrix.drawPixel(17, 19, GRAY);

  // pt (= points)
  matrix.drawLine(1, 25, 1, 29, GRAY);
  matrix.drawPixel(2, 25, GRAY);
  matrix.drawLine(2, 27, 3, 26, GRAY);
  matrix.drawLine(5, 25, 5, 28, GRAY);
  matrix.drawPixel(6, 26, GRAY);
  matrix.drawPixel(6, 29, GRAY);

  // initialize scores etc.
  start();
}

void loop() {

}
