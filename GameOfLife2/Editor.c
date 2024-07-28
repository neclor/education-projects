#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "GameOfLife2.h"

#define K_ENTER 13
#define K_SPACE ' '
#define K_ARROW_UP 72
#define K_ARROW_DOWN 80
#define K_ARROW_LEFT 75
#define K_ARROW_RIGHT 77

void editorLoop(Field* field) {
    printf("\033[?25h");
    drawField(field);

    unsigned int width = field->width, height = field->height;
    unsigned char* data = field->data;

    unsigned int x = 0, y = 0;

    while (1) {
        printf("\033[%d;%dH", y + 1, x + 1);
        int key = _getch();
        if (key == K_ENTER) {
            break;
        }
        else if (key == K_SPACE) {
            size_t cellIndex = y * (size_t)width + x;
            if (data[cellIndex] == 0) {
                data[cellIndex] = 1;
            }
            else if (data[cellIndex] == 1) {
                data[cellIndex] = 2;
            }
            else {
                data[cellIndex] = 0;
            }
            drawField(field);
        }
        else if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
                case K_ARROW_UP:
                    if (y > 0) {
                        y--;
                    }
                    break;
                case K_ARROW_DOWN:
                    if (y < height - 1) {
                        y++;
                    }
                    break;
                case K_ARROW_LEFT:
                    if (x > 0) {
                        x--;
                    }
                    break;
                case K_ARROW_RIGHT:
                    if (x < width - 1) {
                        x++;
                    }
                    break;
            }
        }
    }
}
