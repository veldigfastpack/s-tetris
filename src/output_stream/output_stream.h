#ifndef OUTPUT_STREAM
#define OUTPUT_STREAM
#include <stdio.h>
#include "../globals.h"

void draw_block(int mtx[Y][X], block* block);
void echo_crossfield(int mtx[Y][X], int baked_crossfield[Y][X], block* block);

#endif
