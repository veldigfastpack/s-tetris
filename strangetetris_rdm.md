# Strangetetris

*description: that's about header-files, folders and other shit*

##Folders and what they contain
From the root of project's directory
1. `out`-directory
2. `src`-directory
description: `src` - source-code files, and also `out` - binary and object-files

##`src`-directory
From `src`-directory:
1. `gameplay`-folder
2. `gameplay_sys`-folder
3. `output_stream`-folder
4. `system_calls`-folder
discription: `gameplay` for gameplay source code; `gameplay_sys` for more general functions, but which can still be used in gameplay source code; `output_stream` for output; `system_calls` for auxiliary functions

##Headers of `src`-directory
WARNING: names of `.h`-file the same as its folder name. `gameplay.h` is located in directory `gameplay`, `gameplay_sys.h` in `gameplay_sys` and etc.

####`gameplay.h` funcs
1. main_loop
2. input

####`gameplay_sys.h` funcs
1. block_setpos
2. block_canitfall
3. bake_block
4. change_blocktype
5. set_nonblocking_terminal_mode
6. reset_terminal_mode

####`output_stream.h` funcs
1. draw_block
2. echo_crossfield

####`system_calls.h` funcs
1. check_gameover
2. clear_crossfield
3. dimission_matrix
4. echo_matrix
5. echo_mark
6. line_isfilled
7. copy_matrix
8. clear_and_drop

####`globals.h` definitions
1. structure of block
2. size of playground
3. crossfield and baked_crossfield headers
and etc.


