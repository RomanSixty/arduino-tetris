/**
 * functions to draw numbers for scores etc.
 */
 
void LXLedPanelNumbers_clear ( byte offset_x = 0, byte offset_y = 0 ) {
  matrix.fillRect(offset_x + 0, offset_y + 0, 3, 5, BLACK);
}

void LXLedPanelNumbers_0 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 4, color);
  matrix.drawPixel(offset_x + 1, offset_y + 0, color);
  matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
  matrix.drawPixel(offset_x + 1, offset_y + 4, color);
}

void LXLedPanelNumbers_1 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawPixel(offset_x + 0, offset_y + 0, color);
  matrix.drawLine(offset_x + 1, offset_y + 0, offset_x + 1, offset_y + 3, color);
  matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_2 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
  matrix.drawPixel(offset_x + 2, offset_y + 1, color);
  matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
  matrix.drawPixel(offset_x + 0, offset_y + 3, color);
  matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_3 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
  matrix.drawPixel(offset_x + 2, offset_y + 1, color);
  matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
  matrix.drawPixel(offset_x + 2, offset_y + 3, color);
  matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_4 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 2, color);
  matrix.drawPixel(offset_x + 1, offset_y + 2, color);
  matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_5 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
  matrix.drawPixel(offset_x + 0, offset_y + 1, color);
  matrix.drawLine(offset_x + 0, offset_y + 2, offset_x + 2, offset_y + 2, color);
  matrix.drawPixel(offset_x + 2, offset_y + 3, color);
  matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_6 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
  matrix.drawLine(offset_x + 0, offset_y + 1, offset_x + 0, offset_y + 4, color);
  matrix.drawLine(offset_x + 1, offset_y + 4, offset_x + 2, offset_y + 4, color);
  matrix.drawLine(offset_x + 2, offset_y + 2, offset_x + 2, offset_y + 3, color);
  matrix.drawPixel(offset_x + 1, offset_y + 2, color);
}

void LXLedPanelNumbers_7 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 2, offset_y + 0, color);
  matrix.drawLine(offset_x + 2, offset_y + 1, offset_x + 2, offset_y + 4, color);
}

void LXLedPanelNumbers_8 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 0, offset_x + 0, offset_y + 4, color);
  matrix.drawPixel(offset_x + 1, offset_y + 0, color);
  matrix.drawLine(offset_x + 2, offset_y + 0, offset_x + 2, offset_y + 4, color);
  matrix.drawPixel(offset_x + 1, offset_y + 2, color);
  matrix.drawPixel(offset_x + 1, offset_y + 4, color);
}

void LXLedPanelNumbers_9 ( byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  matrix.drawLine(offset_x + 0, offset_y + 4, offset_x + 2, offset_y + 4, color);
  matrix.drawLine(offset_x + 2, offset_y + 3, offset_x + 2, offset_y + 0, color);
  matrix.drawLine(offset_x + 1, offset_y + 0, offset_x + 0, offset_y + 0, color);
  matrix.drawLine(offset_x + 0, offset_y + 1, offset_x + 0, offset_y + 2, color);
  matrix.drawPixel(offset_x + 1, offset_y + 2, color);
}

void LXLedPanelNumbers_number ( byte number = 0, byte offset_x = 0, byte offset_y = 0, uint16_t color = YELLOW ) {
  LXLedPanelNumbers_clear(offset_x, offset_y);

  switch ( number ) {
    case 0: LXLedPanelNumbers_0(offset_x, offset_y, color); break;
    case 1: LXLedPanelNumbers_1(offset_x, offset_y, color); break;
    case 2: LXLedPanelNumbers_2(offset_x, offset_y, color); break;
    case 3: LXLedPanelNumbers_3(offset_x, offset_y, color); break;
    case 4: LXLedPanelNumbers_4(offset_x, offset_y, color); break;
    case 5: LXLedPanelNumbers_5(offset_x, offset_y, color); break;
    case 6: LXLedPanelNumbers_6(offset_x, offset_y, color); break;
    case 7: LXLedPanelNumbers_7(offset_x, offset_y, color); break;
    case 8: LXLedPanelNumbers_8(offset_x, offset_y, color); break;
    case 9: LXLedPanelNumbers_9(offset_x, offset_y, color); break;
  }
}

LXLedPanelNumbers_write ( unsigned long number = 0, byte where = SCORE_POINTS, uint16_t color = YELLOW ) {
  byte digit_1 = number % 10;
  byte digit_2 = (int) floor(number / 10) % 10;
  byte digit_3 = (int) floor(number / 100) % 10;
  byte digit_4 = (int) floor(number / 1000) % 10;
  byte digit_5 = (int) floor(number / 10000) % 10;
  byte digit_6 = (int) floor(number / 100000) % 10;

  switch (where) {
    case SCORE_LEVELS:
      LXLedPanelNumbers_number(digit_3, 20, 11, color);
      LXLedPanelNumbers_number(digit_2, 24, 11, color);
      LXLedPanelNumbers_number(digit_1, 28, 11, color);
      break;

    case SCORE_LINES:
      LXLedPanelNumbers_number(digit_3, 20, 18, color);
      LXLedPanelNumbers_number(digit_2, 24, 18, color);
      LXLedPanelNumbers_number(digit_1, 28, 18, color);
      break;

    case SCORE_POINTS:
      LXLedPanelNumbers_number(digit_6,  8, 25, color);
      LXLedPanelNumbers_number(digit_5, 12, 25, color);
      LXLedPanelNumbers_number(digit_4, 16, 25, color);
      LXLedPanelNumbers_number(digit_3, 20, 25, color);
      LXLedPanelNumbers_number(digit_2, 24, 25, color);
      LXLedPanelNumbers_number(digit_1, 28, 25, color);
      break;
  }
}
