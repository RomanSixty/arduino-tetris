/**
 * functions to draw numbers for scores etc.
 * numbers are stored as 2 byte bitstreams
 * set bits are set pixels in a raster like
 * 
 * 15 14 13
 * 12 11 10
 * 09 08 07
 * 06 05 04
 * 03 02 01
 * 
 * bit 16 is not needed
 */
const PROGMEM uint16_t Numbers[10] = {
  0b0111101101101111, // 0
  0b0111010010010011, // 1
  0b0111001111100111, // 2
  0b0111100111100111, // 3
  0b0100100111101101, // 4
  0b0111100111001111, // 5
  0b0111101111001111, // 6
  0b0100100100101111, // 7
  0b0111101111101111, // 8
  0b0111100111101111  // 9
};

void LXLedPanelNumbers_number ( const byte number = 0, const byte offset_x = 0, const byte offset_y = 0, const uint16_t color = YELLOW ) {
  uint16_t bits_number = pgm_read_word_near(Numbers + number);

  for ( byte i = 0; i < 15; i++ ) {
    byte row = floor(i / 3);
    byte col = i % 3;

    if ( bitRead(bits_number, i) )
      matrix.drawPixel(col + offset_x, row + offset_y, color);
    else
      matrix.drawPixel(col + offset_x, row + offset_y, BLACK);
  }
}

void LXLedPanelNumbers_write ( const unsigned long number = 0, const byte where = SCORE_POINTS, const uint16_t color = YELLOW ) {
  digit_1 = number % 10;
  digit_2 = (int) floor(number / 10) % 10;
  digit_3 = (int) floor(number / 100) % 10;
  digit_4 = (int) floor(number / 1000) % 10;
  digit_5 = (int) floor(number / 10000) % 10;
  digit_6 = (int) floor(number / 100000) % 10;

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
