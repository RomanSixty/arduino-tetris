/**
 * handle key presses for movement etc.
 */

#include <Keypad.h>

// 4x4 membrane switch
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

// we use only 2, 4, 5 and 6 in WASD fashion
char keymap[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte colPins[KEYPAD_ROWS] = {41, 39, 37, 35};
byte rowPins[KEYPAD_COLS] = {49, 47, 45, 43};

Keypad keypad = Keypad ( makeKeymap(keymap), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );

char keypress = NO_KEY;

void keys() {
  if ( millis() - last_interaction < 200 )
    return;

  char current_keypress = keypad.getKey();

  if ( keypad.getState() == RELEASED ) {
    keypress = current_keypress;

    last_interaction = millis() - 200;
  }
  else if ( keypress == NO_KEY || keypad.getState() == IDLE ) {
    keypress = current_keypress;

    last_interaction = millis();
  }
  else if ( keypad.getState() == PRESSED || keypad.getState() == HOLD ) {
    last_interaction = millis() - 100;
  }

  if ( keypress != NO_KEY ) {
    switch ( keypress ) {
      case '2':
        rotate_tetromino();
        break;
  
      case '4':
        move_tetromino_left();
        break;
  
      case '5':
        move_tetromino_down();
        break;
  
      case '6':
        move_tetromino_right();
        break;
    }

    key_pressed = true;

    if ( game_over ) {
      game_over = false;
      reset();
    }
  }
  else {
    key_pressed = false;
    last_interaction = 0;
  }
}

