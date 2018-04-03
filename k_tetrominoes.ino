/**
 * randomly get a new tetromino
 */
void get_next_tetromino() {
  // of course not every tetromino has the same probability being the next one
  switch ( random(17) ) {
    case 0:
      next_tetr_type = 0;
      next_tetr_color = BLUE;
      break;

    case 1:
    case 2:
    case 3:
      next_tetr_type = 1;
      next_tetr_color = PURPLE;
      break;

    case 4:
    case 5:
    case 6:
      next_tetr_type = 2;
      next_tetr_color = RED;
      break;

    case 7:
    case 8:
    case 9:
      next_tetr_type = 3;
      next_tetr_color = RED;
      break;

    case 10:
    case 11:
    case 12:
      next_tetr_type = 4;
      next_tetr_color = ORANGE;
      break;

    case 13:
    case 14:
    case 15:
      next_tetr_type = 5;
      next_tetr_color = ORANGE;
      break;

    default:
      next_tetr_type = 6;
      next_tetr_color = GREEN;
      break;
  }
}

/**
 * shows the next tetromino in the preview box
 */
void preview_tetromino() {
  matrix.fillRect(21, 4, 4, 4, BLACK);

  uint16_t tet = pgm_read_word(TETROMINOES + 4*next_tetr_type );

  for ( byte i = 0; i < 16; i++ ) {
    byte row = floor(i / 4);
    byte col = i % 4;

    // use offsets for the preview box
    // also put every brick a row further down
    if ( bitRead(tet, i) )
      matrix.drawPixel(col + 21, row + 5, next_tetr_color);
  }
}

/**
 * throws a tetromino in the bucket
 */
void drop_tetromino() {
  // reset positions
  tetr_offsX = 3;
  tetr_offsY = 0;

  tetr_rotation = 0;

  paint_tetromino(tetr_color);
}

/**
 * light the corresponding LEDs for a tetromino
 */
void paint_tetromino ( uint16_t color ) {
  uint16_t tet = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation );

  for ( byte i = 0; i < 16; i++ ) {
    byte row = floor(i / 4);
    byte col = i % 4;

    if ( bitRead(tet, i) )
      matrix.drawPixel(col + tetr_offsX + BUCKET_OFFS_X, row + tetr_offsY + BUCKET_OFFS_Y, color);
  }
}

/**
 * tetromino movements
 */

bool rotate_tetromino() {
  if ( check_collision(ROTATE) )
    return false;

  paint_tetromino(BLACK);
  tetr_rotation++;
  tetr_rotation %= 4;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_left() {
  if ( check_collision(LEFT) )
    return false;

  paint_tetromino(BLACK);
  tetr_offsX--;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_right() {
  if ( check_collision(RIGHT) )
    return false;

  paint_tetromino(BLACK);
  tetr_offsX++;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_down() {
  if ( check_collision(FALL) ) {
    handle_next();
    return false;
  }

  paint_tetromino(BLACK);
  tetr_offsY++;
  paint_tetromino(tetr_color);

  return true;
}

