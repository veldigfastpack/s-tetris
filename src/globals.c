#include "globals.h"

struct termios orig_term, new_term;
block baksteen;
int baked_crossfield[Y][X] = { {0} };
int crossfield[Y][X] = { {0} };
