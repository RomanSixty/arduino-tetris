/**
 * those are the 7 different tetris bricks, each placed
 * in a 4x4 square like this:
 * 
 * 16 15 14 13
 * 12 11 10 09
 * 08 07 06 05
 * 04 03 02 01
 * 
 * set bits are the parts where a brick is solid
 * 
 * the up to four quartets represent the four directions a
 * tetromino can rotate
 */

const PROGMEM uint16_t TETROMINOES[7][4] = {
  // X
  // X
  // X
  // X
  { 0b0100010001000100, 0b0000000011110000, 0b0100010001000100, 0b0000000011110000 },
  
  // XX
  // XX
  { 0b0000011001100000, 0b0000011001100000, 0b0000011001100000, 0b0000011001100000 },
  
  // XX
  //  XX
  { 0b0000011000110000, 0b0000001001100100, 0b0000011000110000, 0b0000001001100100 },
  
  //  XX
  // XX
  { 0b0000011011000000, 0b0000100011000100, 0b0000011011000000, 0b0000100011000100 },
  
  // X
  // X
  // XX
  { 0b0000011101000000, 0b0100010001100000, 0b0000001011100000, 0b0000011000100010 },
  
  //  X
  //  X
  // XX
  { 0b0000111000100000, 0b0000011001000100, 0b0000010001110000, 0b0010001001100000 },
  
  //  X
  // XXX
  { 0b0000000011100100, 0b0000010011000100, 0b0000010011100000, 0b0000010001100100 }
};

/**
 * get a new tetromino
 */
void get_tetromino() {
  Serial.print(F("get_tetromino: "));
  Serial.println(freeRam());

  free(tetr_type);

  tetr_rotation = 0;

  randomSeed(analogRead(A4));

  // of course not every tetromino has the same probability being the next one
  switch ( random(17) ) {

    case 0:
      Serial.println(F("I"));
      tetr_type = pgm_read_word(TETROMINOES[0]);
      tetr_color = BLUE;
      break;

    case 1:
    case 2:
    case 3:
      Serial.println(F("O"));
      tetr_type = pgm_read_word(TETROMINOES[1]);
      tetr_color = PURPLE;
      break;

    case 4:
    case 5:
    case 6:
      Serial.println(F("Z"));
      tetr_type = pgm_read_word(TETROMINOES[2]);
      tetr_color = RED;
      break;

    case 7:
    case 8:
    case 9:
      Serial.println(F("S"));
      tetr_type = pgm_read_word(TETROMINOES[3]);
      tetr_color = RED;
      break;

    case 10:
    case 11:
    case 12:
      Serial.println(F("L"));
      tetr_type = pgm_read_word(TETROMINOES[4]);
      tetr_color = ORANGE;
      break;

    case 13:
    case 14:
    case 15:
      Serial.println(F("L2"));
      tetr_type = pgm_read_word(TETROMINOES[5]);
      tetr_color = ORANGE;
      break;

    default:
      Serial.println(F("T"));
      tetr_type = pgm_read_word(TETROMINOES[6]);
      tetr_color = GREEN;
      break;
  }
}

void drop_tetromino() {
  for ( byte i = 0; i < 16; i++ ) {
    if ( bitRead(tetr_type [ tetr_rotation ], i) ) {
      byte row = floor(i / 4);
      byte col = i % 4;

      matrix.drawPixel(col + tetr_offsX, row + tetr_offsY, tetr_color);
    }
  }
}

