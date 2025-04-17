/* main file */
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
/* --- */
//#include "./gameplay/gameplay.h"
#include "./system_calls/system_calls.h"
#include "./globals.h"
#include "gameplay_sys/gameplay_sys.h"
//#include "output_stream/output_stream.h"

int main(void) {
    srand(time(NULL));
    set_nonblocking_terminal_mode();
    dimission_matrix(crossfield);
    block_setpos(&baksteen, START_Y_POS, START_X_POS);
    START_POS_SET;
    clear_crossfield(crossfield, &baksteen);
    /* gameplay part */
    main_loop(crossfield, baked_crossfield, &baksteen);

    tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
    return 0;
}
