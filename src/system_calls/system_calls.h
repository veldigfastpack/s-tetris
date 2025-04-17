#ifndef SYSTEM_CALLS
#define SYSTEM_CALLS
/* --- */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
/* --- */
#include "../gameplay/gameplay.h"
#include "../globals.h"
/* --- */
int check_gameover(int baked_crossfield[Y][X]);
void clear_crossfield(int crossfield[Y][X], block* block);
void dimission_matrix(int matrix[Y][X]);
void echo_matrix(int matrix[Y][X]);
void echo_mark(int crossfield[Y][X], block* block);
int line_isfilled(int baked_crossfield[Y][X], int block_pos);
void copy_matrix(int origin[Y][X], int outcome[Y][X]);
int clear_and_drop(int baked_crossfield[Y][X], int separator_line);

#endif
