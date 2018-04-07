/**
 * a tetromino has reached the floor
 * calculate scores, check for completed rows etc.
 */
void handle_next() {
  add_to_bucket();

  // are there completed rows?
  check_rows();

  throw_next();
}

/** 
 * add the current tetromino to the bucket 
 */
void add_to_bucket() {
  uint16_t tet = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation);

  for ( byte i = 0; i < 16; i++ ) {
    if ( bitRead(tet, i) ) {
      byte row = floor(i / 4);
      byte col = i % 4;

      bucket[(row+tetr_offsY)*10 + col+tetr_offsX] = tetr_color;
    }
  }

  points += 4 * level;

  LXLedPanelNumbers_write(points, SCORE_POINTS);
}

/**
 * and throw in the next tetromino
 */
void throw_next() {
  tetr_type  = next_tetr_type;
  tetr_color = next_tetr_color;

  get_next_tetromino();
  preview_tetromino();

  drop_tetromino();

  if ( check_collision() ) {
    game_over = true;

    delay(3000);
  }
}

/**
 * check for completed rows to remove
 */
void check_rows() {
  byte completed = 0;

  for ( byte i = 0; i < 17; i++ ) {
    if ( is_complete_row(i) ) {
      completed++;

      matrix.drawLine(2, i+5, 11, i+5, BLACK);

      // only the next 3 rows could also be effected
      if ( is_complete_row(i+1) ) {
        completed++;
        matrix.drawLine(2, i+6, 11, i+6, BLACK);
      }
      if ( is_complete_row(i+2) ) {
        completed++;
        matrix.drawLine(2, i+7, 11, i+7, BLACK);
      }
      if ( is_complete_row(i+3) ) {
        completed++;
        matrix.drawLine(2, i+8, 11, i+8, BLACK);
      }

      // shift the bucket

      for ( int y = i + completed - 1; y >= 0; y-- ) {
        if ( y - completed < 0 ) {
          for ( byte j = 0; j < 10; j++ )
            bucket[y*10+j] = BLACK;
        }
        else {
          for ( byte j = 0; j < 10; j++ )
            bucket[y*10+j] = bucket[(y - completed)*10+j];
        }
      }

      break;
    }
  }

  if ( completed == 0 )
    return;

  delay(100);

  // scores
  switch( completed ) {
    case 1:
      points += (40 * level);
      break;

    case 2:
      points += (100 * level);
      break;

    case 3:
      points += (300 * level);
      break;

    case 4:
      points += (800 * level);
      break;
  }

  LXLedPanelNumbers_write(points, SCORE_POINTS);

  if ( floor ( lines / 5 ) < floor ( ( lines + completed ) / 5 ) ) {
    level++;

    LXLedPanelNumbers_write(level, SCORE_LEVEL);

    tick_length = tick_length * 9 / 10;
  }

  // count rows

  lines += completed;

  LXLedPanelNumbers_write(lines,  SCORE_LINES);

  // paint the new bucket

  for ( byte row = 0; row < 17; row++ ) {
    for ( byte col = 0; col < 10; col++ ) {
      matrix.drawPixel(col + BUCKET_OFFS_X, row + BUCKET_OFFS_Y, bucket[row*10+col]);
    }
  }
}

bool is_complete_row ( byte row ) {
  return ( 
    bucket[row*10]   > 0 &&
    bucket[row*10+1] > 0 &&
    bucket[row*10+2] > 0 &&
    bucket[row*10+3] > 0 &&
    bucket[row*10+4] > 0 &&
    bucket[row*10+5] > 0 &&
    bucket[row*10+6] > 0 &&
    bucket[row*10+7] > 0 &&
    bucket[row*10+8] > 0 &&
    bucket[row*10+9] > 0
  );
}

