/* header of global and single objects */
#ifndef STATIC_OBJ
#define STATIC_OBJ
/* --- */ //includes
#include <termios.h>
#include <stdio.h>
/* --- */
#define START_POS_SET block_setpos(&baksteen, START_Y_POS, START_X_POS)
#define CLEAR_TERM printf("\033[H\033[J")
//#define WAIT usleep(1000000)
#define WAIT usleep(500000)
#define START_Y_POS 1
#define START_X_POS 4
#define Y 15
#define X 10
#define SIZE_S 2
typedef struct {
    int bitmap[SIZE_S][SIZE_S];
    int type;
    int x, y;
} block;
/* --- */ //global objects
extern block baksteen;
extern struct termios orig_term, new_term;
extern int crossfield[Y][X];
extern int baked_crossfield[Y][X];
/* --- */
#endif
