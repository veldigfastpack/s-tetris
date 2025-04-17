#include "output_stream.h"
//#include "../system_calls/system_calls.h"

void draw_block(int mtx[Y][X], block* block) {
    if(block->type == 1) {
        for(int i = 0; i < SIZE_S; i++) {
            for(int j = 0; j < SIZE_S; j++) {
                mtx[block->y+i][block->x+j] = 1;
            }
        }
    } else if(block->type == 2) {
        for(int i = 0; i < SIZE_S; i++) {
            for(int j = 0; j < SIZE_S; j++) {
                mtx[block->y+i][block->x+j] = 1;
                if(i == 0 && j == 1) mtx[block->y+i][block->x+j] = 0;
            }
        }
    } else if(block->type == 3) {
        for(int i = 0; i < SIZE_S; i++) {
            for(int j = 0; j < SIZE_S; j++) {
                mtx[block->y+i][block->x+j] = 1;
                if((i == 0 && j == 1) || (i == 1 && j == 1)) mtx[block->y+i][block->x+j] = 0;
            }
        }
    }
}

void echo_crossfield(int mtx[Y][X], int baked_crossfield[Y][X], block* block) {
    printf("\033[H");
    draw_block(mtx, block);
    for(int y = 0; y < Y; y++) {
        for(int x = 0; x < X; x++) {
            if(mtx[y][x] || baked_crossfield[y][x] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}
