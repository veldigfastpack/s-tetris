/* c-file for header "gameplay.h" */
#include <time.h>
/* --- */
#include "./gameplay.h"
#include "../system_calls/system_calls.h"
#include "../gameplay_sys/gameplay_sys.h"

void main_loop(int crossfield[Y][X], int baked_crossfield[Y][X], block* block) {
    srand(time(NULL));
    //block->type = 3;
    block->type = change_blocktype();
    START_POS_SET;
    while(check_gameover(baked_crossfield)) {
        block->type = change_blocktype();
        while(block_canitfall(&baksteen, baked_crossfield)) {
            CLEAR_TERM;
            WAIT;
            input(&baksteen);
            clear_crossfield(crossfield, &baksteen);
            echo_crossfield(crossfield, baked_crossfield, &baksteen);
            baksteen.y++;
        }
        bake_block(baked_crossfield, &baksteen);
        clear_and_drop(baked_crossfield, block->y-1);
        clear_and_drop(baked_crossfield, block->y);
        START_POS_SET;
    }
}

void input(block* block) {
    char buf[3];
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    if (n <= 0) return;
    if (buf[0] == 27 && n >= 3 && buf[1] == '[') {
        switch (buf[2]) {
            case 'C': {
                if(block->type == 3) {
                    if(block->x+1 == X) {
                        break;
                    } else {
                        block->x++;
                        break;
                    }
                } else if(block->type == 1 || block->type == 2) {
                    if(block->x+1 == X-1) {
                        break;
                    } else {
                        block->x++;
                        break;
                    }
                }
            }
            case 'D': {
                if(block->x == 0) {
                    break;
                } else {
                    block->x--;
                    break;
                }
            }
            default: break;
        }
    }
}
