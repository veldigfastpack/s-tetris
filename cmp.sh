#!/bin/bash
gcc ./src/main.c ./src/gameplay/gameplay.c ./src/system_calls/system_calls.c ./src/output_stream/output_stream.c ./src/gameplay_sys/gameplay_sys.c ./src/globals.c -o ./out/main
./out/main
