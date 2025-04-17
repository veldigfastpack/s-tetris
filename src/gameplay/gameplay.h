#ifndef GAMEPLAY
#define GAMEPLAY
/* --- */
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
/* --- */
#include "../globals.h"
#include "../output_stream/output_stream.h"
/* --- */
//void block_setpos(block* block, int y, int x); //change position of block
void main_loop(int crossfield[Y][X], int baked_crossfield[Y][X], block* block); //main game loop
void input(block* block);

#endif
