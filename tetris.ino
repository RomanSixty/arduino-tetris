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
#define BLACK  matrix.Color333(0, 0, 0)
#define GRAY   matrix.Color333(1, 1, 1)
#define YELLOW matrix.Color333(3, 2, 0)
#define BLUE   matrix.Color333(0, 0, 1) // I
#define GREEN  matrix.Color333(0, 1, 0) // T
#define ORANGE matrix.Color333(3, 1, 0) // L
#define RED    matrix.Color333(1, 0, 0) // Z + S
#define PURPLE matrix.Color333(1, 0, 1) // O

// same colors as integers to save space in the bucket
#define COL_BLACK   0
#define COL_GRAY    1
#define COL_YELLOW  2
#define COL_BLUE    3
#define COL_GREEN   4
#define COL_ORANGE  5
#define COL_RED     6
#define COL_PURPLE  7

#define SCORE_POINTS 1
#define SCORE_LINES  2
#define SCORE_LEVELS 3

// variables
byte levels = 0;
byte lines  = 0;
unsigned long points = 0;
