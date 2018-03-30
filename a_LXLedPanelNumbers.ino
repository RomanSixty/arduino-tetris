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
