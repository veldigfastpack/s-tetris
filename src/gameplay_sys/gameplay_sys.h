#ifndef GAMEPLAY_SYS
#define GAMEPLAY_SYS
#include "../globals.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

void block_setpos(block* block, int y, int x);
int block_canitfall(block* block, int baked_crossfield[Y][X]);
void bake_block(int baked_crossfield[Y][X], block* block);
int change_blocktype();
void set_nonblocking_terminal_mode();
void reset_terminal_mode();

#endif
