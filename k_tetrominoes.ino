/**
 * those are the 7 different tetris bricks, each placed
 * in a 4x4 square with coordinates like 10*x + y
 * 
 * 13 means a pixel at x=1 and y=3
 * 
 * the four quartets represent the four directions a
 * tetromino can rotate
 */


// X
// X
// X
// X
const byte TETROMINO_I[]  = { 10,11,12,13,  1,11,21,31,  20,21,22,23,  2,12,22,32 };

// XX
// XX
const byte TETROMINO_O[]  = {  1, 2,11,12,  1, 2,11,12,   1, 2,11,12,  1, 2,11,12 };

// XX
//  XX
const byte TETROMINO_Z[]  = {  2, 3,11,12,  2,12,13,23,   2, 3,11,12,  2,12,13,23 };

//  XX
// XX
const byte TETROMINO_S[]  = {  1, 2,12,13,  2,11,12,21,   1, 2,12,13,  2,11,12,21 };

// X
// X
// XX
const byte TETROMINO_L[]  = {  0,10,11,12,  1, 2,11,21,  10,11,12,22,  1,11,20,21 };

//  X
//  X
// XX
const byte TETROMINO_L2[] = {  3,11,12,13,  2,12,22,23,  11,12,13,21,  1, 2,12,22 };

//  X
// XXX
const byte TETROMINO_T[]  = {  2,11,12,13,  2,12,13,22,  11,12,13,22,  2,11,12,22 };
