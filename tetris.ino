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

/**
 * functions to draw numbers for scores etc.
 */
class LXLedPanelNumbers {
  public:
    static void write ( unsigned long number = 0, int where = SCORE_POINTS, uint16_t color = YELLOW ) {
      int digit_1 = number % 10;
      int digit_2 = (int) floor(number / 10) % 10;
      int digit_3 = (int) floor(number / 100) % 10;
      int digit_4 = (int) floor(number / 1000) % 10;
      int digit_5 = (int) floor(number / 10000) % 10;
      int digit_6 = (int) floor(number / 100000) % 10;

      switch (where) {
        case SCORE_LEVELS:
          LXLedPanelNumbers::draw_number(digit_3, 20, 11, color);
          LXLedPanelNumbers::draw_number(digit_2, 24, 11, color);
          LXLedPanelNumbers::draw_number(digit_1, 28, 11, color);
          break;

        case SCORE_LINES:
          LXLedPanelNumbers::draw_number(digit_3, 20, 18, color);
          LXLedPanelNumbers::draw_number(digit_2, 24, 18, color);
          LXLedPanelNumbers::draw_number(digit_1, 28, 18, color);
          break;

        case SCORE_POINTS:
          LXLedPanelNumbers::draw_number(digit_6,  8, 25, color);
          LXLedPanelNumbers::draw_number(digit_5, 12, 25, color);
          LXLedPanelNumbers::draw_number(digit_4, 16, 25, color);
          LXLedPanelNumbers::draw_number(digit_3, 20, 25, color);
          LXLedPanelNumbers::draw_number(digit_2, 24, 25, color);
          LXLedPanelNumbers::draw_number(digit_1, 28, 25, color);
          break;
      }
    }

  private:
    static void draw_number ( int number = 0, int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      switch ( number ) {
        case 0: draw_0(offset_x, offset_y, color); break;
        case 1: draw_1(offset_x, offset_y, color); break;
        case 2: draw_2(offset_x, offset_y, color); break;
        case 3: draw_3(offset_x, offset_y, color); break;
        case 4: draw_4(offset_x, offset_y, color); break;
        case 5: draw_5(offset_x, offset_y, color); break;
        case 6: draw_6(offset_x, offset_y, color); break;
        case 7: draw_7(offset_x, offset_y, color); break;
        case 8: draw_8(offset_x, offset_y, color); break;
        case 9: draw_9(offset_x, offset_y, color); break;
      }
    }
  
    static void clear_number ( int offset_x = 0, int offset_y = 0 ) {
      matrix.fillRect(offset_x + 0, offset_y + 0, 3, 5, BLACK);
    }

    static void draw_0 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 4, color);
      matrix.drawPixel(offset_x + 1, offset_y + 0, color);
      matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
      matrix.drawPixel(offset_x + 1, offset_y + 4, color);
    }

    static void draw_1 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawPixel(offset_x + 0, offset_y + 0, color);
      matrix.drawLine(offset_x + 1, offset_y + 0, offset_x + 1, offset_y + 3, color);
      matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
    }

    static void draw_2 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
      matrix.drawPixel(offset_x + 2, offset_y + 1, color);
      matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
      matrix.drawPixel(offset_x + 0, offset_y + 3, color);
      matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
    }

    static void draw_3 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
      matrix.drawPixel(offset_x + 2, offset_y + 1, color);
      matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
      matrix.drawPixel(offset_x + 2, offset_y + 3, color);
      matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
    }

    static void draw_4 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 2, color);
      matrix.drawPixel(offset_x + 1, offset_y + 2, color);
      matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
    }

    static void draw_5 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
      matrix.drawPixel(offset_x + 0, offset_y + 1, color);
      matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
      matrix.drawPixel(offset_x + 2, offset_y + 3, color);
      matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
    }

    static void draw_6 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
      matrix.drawLine(offset_x + 0, offset_y + 1, offset_x + 0, offset_y + 4, color);
      matrix.drawLine(offset_x + 1, offset_y + 4, offset_x + 2, offset_y + 4, color);
      matrix.drawLine(offset_x + 2, offset_y + 2, offset_x + 2, offset_y + 3, color);
      matrix.drawPixel(offset_x + 1, offset_y + 2, color);
    }

    static void draw_7 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
      matrix.drawLine(offset_x + 2, offset_y + 1, offset_x + 2, offset_y + 4, color);
    }

    static void draw_8 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 4, color);
      matrix.drawPixel(offset_x + 1, offset_y + 0, color);
      matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
      matrix.drawPixel(offset_x + 1, offset_y + 2, color);
      matrix.drawPixel(offset_x + 1, offset_y + 4, color);
    }

    static void draw_9 ( int offset_x = 0, int offset_y = 0, uint16_t color = YELLOW ) {
      clear_number(offset_x, offset_y);
    
      matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
      matrix.drawLine(offset_x + 2, offset_y + 3, offset_x + 2, offset_y + 0, color);
      matrix.drawLine(offset_x + 1, offset_y + 0, offset_x + 0, offset_y + 0, color);
      matrix.drawLine(offset_x + 0, offset_y + 1, offset_x + 0, offset_y + 2, color);
      matrix.drawPixel(offset_x + 1, offset_y + 2, color);
    }
};

void start() {
  levels = 0;
  lines  = 0;
  points = 0;
  
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

  // 000
  LXLedPanelNumbers::write(levels, SCORE_LEVELS);
  LXLedPanelNumbers::write(lines,  SCORE_LINES);
  LXLedPanelNumbers::write(points, SCORE_POINTS);
}

void setup() {
  matrix.begin();
  
  start();
}

void loop() {

}
