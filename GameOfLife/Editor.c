#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "GameOfLife.h"


void editorLoop(Field* field) {
    unsigned int width = field->width, height = field->height;
    unsigned char* data = field->data;
    unsigned int x = 0, y = 0;
    while (1) {
        int key = _getch();
        if (key == 13) {
            break;
        }
        else if (key == 32) {
            size_t cellIndex = y * (size_t)width + x;
            if (data[y * (size_t)width + x] == 0) {
                data[y * (size_t)width + x] = 1;
            }
            else {
                data[y * (size_t)width + x] = 0;
            }
            drawField(field);
        }
        else if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
                case 72:
                    if (y > 0) {
                        y--;
                    }
                    break;
                case 80:
                    if (y < height - 1) {
                        y++;
                    }
                    break;
                case 75:
                    if (x > 0) {
                        x--;
                    }
                    break;
                case 77:
                    if (x < width - 1) {
                        x++;
                    }
                    break;
            }
        }
        printf("\033[%d;%dH", y + 2, x + 2);
    }
}
