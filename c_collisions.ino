bool check_collision ( const byte dir ) {
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
  }

  // now check every set bit in the tetromino container
  // if it collides with a set bit in the bucket

Serial.print(temp_tetr_offsY);
Serial.print(F(" "));
Serial.println(temp_tetr_offsX);
Serial.println();

  for ( byte i = 0; i < 16; i++ ) {
    if ( bitRead(temp_tet, i) ) {
      byte row = floor(i / 4);
      byte col = i % 4;

Serial.print(row+temp_tetr_offsY);
Serial.print(F(" "));
Serial.println(col+temp_tetr_offsX);

      // the floor is not included in the bucket, so check it here
      if ( row+temp_tetr_offsY > 16 )
        return true;

      // temp_tetr_offsX is offset by another 1 because the walls of the bucket are included
      if ( bitRead(bucket[row+temp_tetr_offsY], col+temp_tetr_offsX+1) )
        return true;
    }
  }
  
  return false;
}

