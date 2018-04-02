

/**
 * get a new tetromino
 */
void get_next_tetromino() {
  Serial.print(F("get_tetromino: "));
  Serial.println(freeRam());

  // of course not every tetromino has the same probability being the next one
  switch ( random(17) ) {
    case 0:
      Serial.println(F("I"));
      next_tetr_type = 0;
      next_tetr_color = BLUE;
      break;

    case 1:
    case 2:
    case 3:
      Serial.println(F("O"));
      next_tetr_type = 1;
      next_tetr_color = PURPLE;
      break;

    case 4:
    case 5:
    case 6:
      Serial.println(F("Z"));
      next_tetr_type = 2;
      next_tetr_color = RED;
      break;

    case 7:
    case 8:
    case 9:
      Serial.println(F("S"));
      next_tetr_type = 3;
      next_tetr_color = RED;
      break;

    case 10:
    case 11:
    case 12:
      Serial.println(F("L"));
      next_tetr_type = 4;
      next_tetr_color = ORANGE;
      break;

    case 13:
    case 14:
    case 15:
      Serial.println(F("L2"));
      next_tetr_type = 5;
      next_tetr_color = ORANGE;
      break;

    default:
      Serial.println(F("T"));
      next_tetr_type = 6;
      next_tetr_color = GREEN;
      break;
  }
}

void preview_tetromino() {
  matrix.fillRect(21, 4, 4, 4, BLACK);

  uint16_t tet = pgm_read_word(TETROMINOES + 4*next_tetr_type );
  
  for ( byte i = 0; i < 16; i++ ) {
    byte row = floor(i / 4);
    byte col = i % 4;

    // use offsets for the preview box
    if ( bitRead(tet, i) )
      matrix.drawPixel(col + 21, row + 4, next_tetr_color);
  }
}

void drop_tetromino() {
  // reset positions
  tetr_offsX = 3;
  tetr_offsY = 0;
  
  tetr_rotation = 0;

  paint_tetromino(tetr_color);
}

void paint_tetromino ( uint16_t color ) {
  uint16_t tet = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation );
  
  for ( byte i = 0; i < 16; i++ ) {
    byte row = floor(i / 4);
    byte col = i % 4;

    // offsets are increased here because the bucket doesn't start at 0|0
    if ( bitRead(tet, i) )
      matrix.drawPixel(col + tetr_offsX + 2, row + tetr_offsY + 5, color);
  }
}

bool rotate_tetromino() {
  Serial.print(F("rotate_tetromino: "));
  Serial.println(freeRam());
  
  if ( check_collision(ROTATE) )
    return false;

  paint_tetromino(BLACK);
  tetr_rotation++;
  tetr_rotation %= 4;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_left() {
  Serial.print(F("move_tetromino_left: "));
  Serial.println(freeRam());
  
  if ( check_collision(LEFT) )
    return false;

  paint_tetromino(BLACK);
  tetr_offsX--;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_right() {
  Serial.print(F("move_tetromino_right: "));
  Serial.println(freeRam());
  
  if ( check_collision(RIGHT) )
    return false;

  paint_tetromino(BLACK);
  tetr_offsX++;
  paint_tetromino(tetr_color);

  return true;
}

bool move_tetromino_down() {
  Serial.print(F("move_tetromino_down: "));
  Serial.println(freeRam());
  
  if ( check_collision(FALL) ) {
    // increase score

    points += 4;
    
    LXLedPanelNumbers_write(points, SCORE_POINTS);
  
    // add the current tetromino to the bucket
    
    uint16_t tet = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation);

    for ( byte i = 0; i < 16; i++ ) {
      if ( bitRead(tet, i) ) {
        byte row = floor(i / 4);
        byte col = i % 4;
  
        bitSet(bucket[row+tetr_offsY], col+tetr_offsX+1);
      }
    }
    
    // and get the next one

    tetr_type  = next_tetr_type;
    tetr_color = next_tetr_color;
    
    get_next_tetromino();
    preview_tetromino();
    
    drop_tetromino();
  
    return false;
  }

  paint_tetromino(BLACK);
  tetr_offsY++;
  paint_tetromino(tetr_color);

  return true;
}

