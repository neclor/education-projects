#include <stdio.h>
#include <stdlib.h>

#include "GameOfLife2.h"

#define DEAD_CHAR '.'
#define ADULT_CHAR '#'
#define CHILD_CHAR '+'


unsigned char* screenData = NULL;

void drawHelp(unsigned int width) {
    unsigned int x = width + 2;
    printf("\033[%d;%dH", 1, x);
    printf("Editor:");
    printf("\033[%d;%dH", 2, x + 1);
    printf("Select cell - arrows");
    printf("\033[%d;%dH", 3, x + 1);
    printf("Draw cell - space");
    printf("\033[%d;%dH", 4, x + 1);
    printf("Start game - enter");
    printf("\033[%d;%dH", 5, x);
    printf("Game:");
    printf("\033[%d;%dH", 6, x + 1);
    printf("Change speed - arrows");
    printf("\033[%d;%dH", 7, x + 1);
    printf("Pause game - space");
    printf("\033[%d;%dH", 8, x + 1);
    printf("Stop - enter");
}

void drawField(Field* field) {
    unsigned int width = field->width, height = field->height;
    unsigned char* data = field->data;
    if (!screenData) {
        screenData = (unsigned char*)malloc((width + 1) * height);
        if (!screenData) {
            fprintf(stderr, "ERROR: Failed to allocate memory\n");
            exit(1);
        }
    }
    for (unsigned int y = 0; y < height; y++) {
        unsigned int rowIndex = y * width;
        screenData[rowIndex + y + width] = '\n';
        for (unsigned int x = 0; x < width; x++) {
            unsigned int dataIndex = rowIndex + x;
            unsigned int screenIndex = dataIndex + y;
            if (data[dataIndex] == 0) {
                screenData[screenIndex] = DEAD_CHAR;
            }
            else if (data[dataIndex] == 1) {
                screenData[screenIndex] = ADULT_CHAR;
            }
            else {
                screenData[screenIndex] = CHILD_CHAR;
            }
        }
    }
    screenData[height * (width + 1) - 1] = 0;
    printf("\033[%d;%dH", 1, 1);
    puts(screenData);
}
