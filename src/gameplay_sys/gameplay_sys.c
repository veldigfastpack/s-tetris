#include <unistd.h>
#include <stdlib.h>
/* --- */
#include "gameplay_sys.h"

void block_setpos(block* block, int y, int x) {
    block->y = y;
    block->x = x;
}

int block_canitfall(block *block, int baked_crossfield[Y][X]) {
    if(block->type == 1 || block->type == 2) {
        if(block->y+1 == Y || baked_crossfield[block->y+1][block->x] == 1 || baked_crossfield[block->y+1][block->x+1] == 1) return 0;
    } else if(block->type == 3) {
        if(block->y+1 == Y || baked_crossfield[block->y+1][block->x] == 1) return 0;
    }
    return 1;
}

void bake_block(int baked_crossfield[Y][X], block* block) {
    if(block->type == 1) {
        baked_crossfield[block->y-1][block->x] = 1;
        baked_crossfield[block->y+1-1][block->x] = 1;
        baked_crossfield[block->y-1][block->x+1] = 1;
        baked_crossfield[block->y+1-1][block->x+1] = 1;
    } else if(block->type == 2) {
        baked_crossfield[block->y-1][block->x] = 1;
        baked_crossfield[block->y+1-1][block->x] = 1;
        baked_crossfield[block->y+1-1][block->x+1] = 1;
    } else if(block->type == 3) {
        baked_crossfield[block->y-1][block->x] = 1;
        baked_crossfield[block->y+1-1][block->x] = 1;
    }
}

void reset_terminal_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
}

void set_nonblocking_terminal_mode() {
    tcgetattr(STDIN_FILENO, &orig_term);
    atexit(reset_terminal_mode);
    new_term = orig_term;
    new_term.c_lflag &= ~(ICANON | ECHO); // неканонический режим, без echo
    new_term.c_cc[VMIN] = 0; // минимальное количество байтов для чтения
    new_term.c_cc[VTIME] = 0; // без тайм-аута
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
    // Сделать STDIN неблокирующим
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

int change_blocktype() {
    return rand() % 3 + 1;
}
