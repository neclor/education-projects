#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define FIELD_POSITION_X 1
#define FIELD_POSITION_Y 1

#define FIELD_WIDTH 20
#define FIELD_HEIGHT 20




int field[FIELD_WIDTH][FIELD_HEIGHT] = { 0 };




typedef struct {
    int x;
    int y;
} Point;




typedef struct {
    Point body[FIELD_WIDTH * FIELD_HEIGHT];
    int lenght;
    int direction;
} Snake;



int score = 0;




void drawField() {
    for (int x = FIELD_POSITION_X - 1; x <= FIELD_POSITION_X + FIELD_WIDTH; x++) {
        for (int y = FIELD_POSITION_Y - 1; y <= FIELD_POSITION_Y + FIELD_HEIGHT; y++) {
            printf("\033[%d;%dH", x, y);
            if (x == FIELD_POSITION_X - 1 || x == FIELD_POSITION_X + FIELD_WIDTH || y == FIELD_POSITION_Y - 1 || y == FIELD_POSITION_Y + FIELD_HEIGHT) {
                printf("#");
            }
            else {
                printf(".");
            }
        }
    }
}

void drawScore() {
    printf("\033[%d;%dH", FIELD_POSITION_X, FIELD_POSITION_Y + FIELD_HEIGHT + 2);
    printf("Score: %d", score);
}

void init() {



}


int main() {
    int array[5] = { 1, 2, 3, 4, 5 };


    test();


    //ptr = array;


    printf("%d\n", ptr[4]);




    return 0;
}


