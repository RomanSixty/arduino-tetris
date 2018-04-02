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

// add the current tetromino to the bucket
void add_to_bucket() {
  uint16_t tet = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation);

  for ( byte i = 0; i < 16; i++ ) {
    if ( bitRead(tet, i) ) {
      byte row = floor(i / 4);
      byte col = i % 4;

      bitSet(bucket[row+tetr_offsY], col+tetr_offsX+1);
    }
  }

  // increase score

  points += 4;

  LXLedPanelNumbers_write(points, SCORE_POINTS);
}

// and throw in the next tetromino
void throw_next() {
  tetr_type  = next_tetr_type;
  tetr_color = next_tetr_color;

  get_next_tetromino();
  preview_tetromino();

  drop_tetromino();

  if ( check_collision() )
    game_over = true;
}

void check_rows() {
  byte completed = 0;

  for ( byte i = 0; i < 17; i++ ) {
    if ( bucket[i] == 0b111111111111 ) {
      completed++;

      matrix.drawLine(2, i+5, 11, i+5, BLACK);

      // only the next 3 rows could also be effected
      if ( bucket[i+1] == 0b111111111111 ) {
        completed++;
        matrix.drawLine(2, i+6, 11, i+6, BLACK);
      }
      if ( bucket[i+2] == 0b111111111111 ) {
        completed++;
        matrix.drawLine(2, i+7, 11, i+7, BLACK);
      }
      if ( bucket[i+3] == 0b111111111111 ) {
        completed++;
        matrix.drawLine(2, i+8, 11, i+8, BLACK);
      }

      // shift the bucket

      for ( int y = i + completed - 1; y >= 0; y-- ) {
        if ( y - completed < 0 )
          bucket[y] = 0b100000000001;
        else
          bucket[y] = bucket[y - completed];
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
      points += (20 * levels);
      break;

    case 2:
      points += (50 * levels);
      break;

    case 3:
      points += (200 * levels);
      break;

    case 4:
      points += (500 * levels);
      break;
  }

  LXLedPanelNumbers_write(points, SCORE_POINTS);

  if ( floor ( lines / 10 ) < floor ( ( lines + completed ) / 10 ) ) {
    levels++;

    LXLedPanelNumbers_write(levels, SCORE_LEVELS);

    tick_length = tick_length * 8 / 10;
  }

  // count rows

  lines += completed;

  LXLedPanelNumbers_write(lines,  SCORE_LINES);

  // paint the new bucket

  for ( byte row = 0; row < 17; row++ ) {
    for ( byte col = 1; col < 11; col++ ) {
      // note: Arduino Uno's sparse memory doesn't have enough space to also remember colors
      if ( bitRead(bucket[row], col) )
        matrix.drawPixel(col + BUCKET_OFFS_X, row + BUCKET_OFFS_Y, GRASS);
      else
        matrix.drawPixel(col + BUCKET_OFFS_X, row + BUCKET_OFFS_Y, BLACK);
    }
  }
}
