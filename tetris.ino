/**
 * http://adafru.it/1484
 */

#include <RGBmatrixPanel.h>

#define CLK 8
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define SWITCH A5

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

// colors
const uint16_t BLACK  = matrix.Color333(0, 0, 0);
const uint16_t GRAY   = matrix.Color333(1, 1, 1);
const uint16_t YELLOW = matrix.Color333(3, 2, 0);
const uint16_t BLUE   = matrix.Color333(0, 0, 1);
const uint16_t GREEN  = matrix.Color333(0, 1, 0);
const uint16_t ORANGE = matrix.Color333(3, 1, 0);
const uint16_t RED    = matrix.Color333(1, 0, 0);
const uint16_t PURPLE = matrix.Color333(1, 0, 1);

const byte SCORE_POINTS = 1;
const byte SCORE_LINES  = 2;
const byte SCORE_LEVELS = 3;

// variables
byte levels = 0;
byte lines  = 0;
unsigned long points = 0;

uint16_t *tetr_type;
byte tetr_rotation = 0;
uint16_t tetr_color;
byte tetr_offsX = 5;
byte tetr_offsY = 5;

// for scores
byte digit_1, digit_2, digit_3, digit_4, digit_5, digit_6 = 0;

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
