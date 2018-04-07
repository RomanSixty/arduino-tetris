/**
 * collision detection
 * checks if a tetromino can move in a certain direction or rotate
 * returns true, if a collision is about to happen
 */
bool check_collision ( const byte dir = 0 ) {
  uint16_t temp_tet        = pgm_read_word(TETROMINOES + 4*tetr_type + tetr_rotation);
  int      temp_tetr_offsX = tetr_offsX;
  int      temp_tetr_offsY = tetr_offsY;

  switch ( dir ) {
    case ROTATE:
      temp_tet = pgm_read_word(TETROMINOES + 4*tetr_type + (tetr_rotation + 1)%4 );
      break;

    case LEFT:
      temp_tetr_offsX--;
      break;

    case RIGHT:
      temp_tetr_offsX++;
      break;

    case FALL:
      temp_tetr_offsY++;
      break;

    default: // just dropped tetromino
      break;
  }

  // now check every set bit in the tetromino container
  // if it collides with a set value in the bucket

  for ( byte i = 0; i < 16; i++ ) {
    if ( bitRead(temp_tet, i) ) {
      byte row = floor(i / 4);
      byte col = i % 4;

      // the floor is not included in the bucket, so check it here
      if ( row+temp_tetr_offsY > 16 )
        return true;

      // also check for the walls
      if ( col+temp_tetr_offsX < 0 || col+temp_tetr_offsX > 9)
        return true;

      if ( bucket[(row+temp_tetr_offsY) * 10 + col+temp_tetr_offsX] > 0 )
        return true;
    }
  }

  return false;
}

