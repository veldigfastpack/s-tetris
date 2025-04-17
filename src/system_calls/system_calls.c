#include "system_calls.h"

int check_gameover(int baked_crossfield[Y][X]) {
    for(int ptrcage = 0; ptrcage < X; ptrcage++) {
        if(baked_crossfield[0][ptrcage] == 1) {
            return 0;
        }
    }
    return 1;
}

void clear_crossfield(int crossfield[Y][X], block* block) {
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            if(i == block->y && j == block->x) {
                crossfield[i][j] = 1;
            }
            crossfield[i][j] = 0;
        }
    }
}

void dimission_matrix(int matrix[Y][X]) {
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            matrix[i][j] = 0;
        }
    }
};

void echo_matrix(int matrix[Y][X]) {
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void echo_mark(int crossfield[Y][X], block* block) {
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            printf("%d ", crossfield[i][j]);
        }
        printf("\n");
    }
}

int line_isfilled(int baked_crossfield[Y][X], int block_pos) {
    int sum = 0;
    for(int i = 0; i < X; i++) {
        sum += baked_crossfield[block_pos][i];
    }
    if(sum == X) {
        return 1;
    } else {
        return 0;
    }
}

void copy_matrix(int origin[Y][X], int outcome[Y][X]) {
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            outcome[i][j] = origin[i][j];
        }
    }
}

int clear_and_drop(int baked_crossfield[Y][X], int separator_line) {
    int baked_crossfield_shadow[Y][X] = { {0} };
    copy_matrix(baked_crossfield, baked_crossfield_shadow);
    int control_sum = 0;
    for(int i = 0; i < X; i++) {
        if(baked_crossfield_shadow[separator_line][i] == 1) {
            control_sum++;
        } else {
            return 0;
        }
    }
    if(control_sum == X) {
        for(int i = 0; i < separator_line; i++) {
            for(int j = 0; j < X; j++) {
                baked_crossfield[i+1][j] = baked_crossfield_shadow[i][j];
            }
        }
    }
    return 1;
}
