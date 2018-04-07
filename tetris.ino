/**
 * LX' Tetris
 * 
 * for Arduino/Genuino Uno and a 32x32 LED matrix panel like
 * http://adafru.it/1484
 * 
 * four buttons are added using a resistor ladder and analog pin A5
 * 
 * latest version and documentation here:
 * https://github.com/RomanSixty/arduino-tetris
 */

#include <RGBmatrixPanel.h>

#define CLK 11
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define SWITCH A5

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

// colors
#define BLACK  matrix.Color333(0, 0, 0)
#define GRAY   matrix.Color333(1, 1, 1)
#define YELLOW matrix.Color333(3, 2, 0)
#define BLUE   matrix.Color333(0, 0, 1)
#define GREEN  matrix.Color333(0, 1, 0)
#define ORANGE matrix.Color333(3, 1, 0)
#define RED    matrix.Color333(1, 0, 0)
#define PURPLE matrix.Color333(1, 0, 1)
#define CYAN   matrix.Color333(0, 1, 1)

// for positions on the panel
#define SCORE_POINTS 1
#define SCORE_LINES  2
#define SCORE_LEVEL  3

// for collision checking
#define ROTATE 1
#define LEFT   2
#define RIGHT  3
#define FALL   4

// bucket offset on the panel
#define BUCKET_OFFS_X 2
#define BUCKET_OFFS_Y 5

int bucket[17];

unsigned long last_interaction =    0; // when was the last button pressed? 
unsigned long next_tick        =    0; // when will the next automatic step happen?
int           tick_length      = 1000; // how long does on step take? (decreases on higher levels)

// scores
byte level;
byte lines;
unsigned long points;

// current tetromino
byte     tetr_type, next_tetr_type;
uint16_t tetr_color, next_tetr_color;
byte     tetr_rotation;
int      tetr_offsX;
int      tetr_offsY;

bool game_over   = false;
bool key_pressed = false;

/**
 * those are the 7 different tetris bricks, each placed in a 4x4 square
 * set bits are the parts where a brick is solid
 * the four quartets represent the four directions a tetromino can rotate
 */
const PROGMEM uint16_t TETROMINOES[28] = {
  // X
  // X
  // X
  // X
  0b0000000011110000, 0b0100010001000100, 0b0000000011110000, 0b0100010001000100,

  // XX
  // XX
  0b0000000001100110, 0b0000000001100110, 0b0000000001100110, 0b0000000001100110,

  // XX
  //  XX
  0b0000000001100011, 0b00000000001001100100, 0b000001100011, 0b0000001001100100,

  //  XX
  // XX
  0b0000000001101100, 0b0000100011000100, 0b0000000001101100, 0b0000100011000100,

  // X
  // X
  // XX
  0b0000000001110100, 0b0000010001000110, 0b0000000000010111, 0b0000011000100010,

  //  X
  //  X
  // XX
  0b0000000011100010, 0b0000011001000100, 0b0000000010001110, 0b0000001000100110,

  //  X
  // XXX
  0b0000000011100100, 0b0000010001100100, 0b0000010011100000, 0b0000010011000100
};
