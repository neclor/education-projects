#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "GameOfLife.h"

#define DELAY 500

static clock_t CLOCKS_PER_MS = CLOCKS_PER_SEC * 1000;

static unsigned char* dataCopy = NULL;

Field createField(unsigned int width, unsigned int height) {
    unsigned char* data = (unsigned char*)calloc(width, height);
    if (!data) {
        fprintf(stderr, "ERROR: Failed to allocate memory\n");
        exit(1);
    }
    Field field = { data, width, height };
    return field;
}

void updateField(Field* field) {
    unsigned int width = field->width, height = field->height;
    unsigned char* data = field->data;
    if (!dataCopy) {
        dataCopy = (char*)malloc(width * height);
        if (!dataCopy) {
            fprintf(stderr, "ERROR: Failed to allocate memory\n");
            exit(1);
        }
    }
    memcpy(dataCopy, data, width * height);

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int neighborsNumber = 0;
            for (int relativeX = -1; relativeX < 2; relativeX++) {
                unsigned int neighborX = (x + relativeX + width) % width;
                for (int relativeY = -1; relativeY < 2; relativeY++) {
                    unsigned int neighborY = (y + relativeY + height) % height;
                    neighborsNumber += dataCopy[neighborY * (size_t)width + neighborX];
                }
            }
            size_t cellIndex = y * (size_t)width + x;
            neighborsNumber -= dataCopy[cellIndex];

            if (neighborsNumber < 2 || neighborsNumber > 3) {
                data[cellIndex] = 0;
            }
            else if (neighborsNumber == 3) {
                data[cellIndex] = 1;
            }
        }
    }
}

void gameLoop(Field* field) {
    unsigned char pause = 0;
    time_t time = clock();
    int count = 0;
    while (1) {
        int key;
        if (_kbhit()) {
            key = _getch();
            if (key == 32) {
                if (pause) {
                    pause = 0;
                }
                else {
                    pause = 1;
                }
            }
            else if (key == 82 || key == 114) {
                break;
            }
        }
        if (!pause) {
            time_t newTime = clock();
            if ((newTime - time) >= DELAY) {
                time = newTime;
                updateField(field);
                drawField(field);
            }
        }
    }
}
