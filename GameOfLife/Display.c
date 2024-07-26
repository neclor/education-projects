#include <stdio.h>
#include <stdlib.h>

#include "GameOfLife.h"

#define BORDER_CHAR "#"
#define DEAD_CHAR "."
#define LIVE_CHAR "@"

void drawBorders(Field* field) {
    unsigned int width = field->width, height = field->height;
    for (unsigned int x = 1; x < width + 3; x++) {
        printf("\033[%d;%dH", 1, x);
        printf(BORDER_CHAR);
        printf("\033[%d;%dH", height + 2, x);
        printf(BORDER_CHAR);
    }
    for (unsigned int y = 1; y < height + 3; y++) {
        printf("\033[%d;%dH", y, 1);
        printf(BORDER_CHAR);
        printf("\033[%d;%dH", y, width + 2);
        printf(BORDER_CHAR);
    }
}

void drawField(Field* field) {
    unsigned int width = field->width, height = field->height;
    unsigned char* data = field->data;
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            printf("\033[%d;%dH", y + 2, x + 2);
            if (data[y * width + x] == 0) {
                printf(DEAD_CHAR);
            }
            else {
                printf(LIVE_CHAR);
            }
        }
    }
}
