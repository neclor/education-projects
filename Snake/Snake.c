#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define FIELD_POSITION_X 1
#define FIELD_POSITION_Y 1

#define FIELD_WIDTH 20
#define FIELD_HEIGHT 20

#define WALL_CHAR "#"
#define FLOOR_CHAR "."
#define SNAKE_HEAD_CHAR "@"
#define SNAKE_CHAR "0"
#define APPLE_CHAR "$"

typedef struct {
    int x;
    int y;
} Point;

int gameOver;
int score;

int fieldArea = FIELD_WIDTH * FIELD_HEIGHT;
int field[FIELD_WIDTH][FIELD_HEIGHT] = { 0 };

Point snakeBody[FIELD_WIDTH * FIELD_HEIGHT];
int snakeLenght;
int direction; // 0 - Up, 1 - Right, 2 - Down, 3 - Left

void drawField() {
    /*
    for (int x = FIELD_POSITION_X - 1; x <= FIELD_POSITION_X + FIELD_WIDTH; x++) {
        printf("\033[%d;%dH", x, FIELD_POSITION_Y - 1);
        printf("\033[%d;%dH", x, FIELD_POSITION_Y + FIELD_HEIGHT);
    }

    for (int y = FIELD_POSITION_Y - 1; y <= FIELD_POSITION_Y + FIELD_HEIGHT; y++) {
        printf("\033[%d;%dH", FIELD_POSITION_X - 1, y);
        printf("\033[%d;%dH", FIELD_POSITION_X + FIELD_WIDTH, y);
    }
    */
    
    for (int x = FIELD_POSITION_X - 1; x <= FIELD_POSITION_X + FIELD_WIDTH; x++) {
        for (int y = FIELD_POSITION_Y - 1; y <= FIELD_POSITION_Y + FIELD_HEIGHT; y++) {
            printf("\033[%d;%dH", x, y);
            if (x == FIELD_POSITION_X - 1 || x == FIELD_POSITION_X + FIELD_WIDTH || y == FIELD_POSITION_Y - 1 || y == FIELD_POSITION_Y + FIELD_HEIGHT) {
                printf("WALL_CHAR");
            }
            else {
                printf("FLOOR_CHAR");
            }
        }
    } 
}

void drawScore() {
    printf("\033[%d;%dH", FIELD_POSITION_X, FIELD_POSITION_Y + FIELD_HEIGHT + 2);
    printf("Score: %d", score);
}

void drawGameOver() {

}


void init() {
    Point snakeStartPosition = { FIELD_WIDTH / 2, FIELD_HEIGHT / 2 };
    snakeBody[0] = snakeStartPosition;
    snakeLenght = 1;
    direction = 0;

    field[snakeStartPosition.x][snakeStartPosition.y] = 1;
    createApple();

    gameOver = 0;

    drawField();
    drawScore();
}

void createApple() {
    int value = rand() % (fieldArea - snakeLenght + 1);
    int count = 0;
    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (value == count) {
                field[x][y] = 2;
                printf("\033[%d;%dH", FIELD_POSITION_X + x, FIELD_POSITION_Y + y);
                printf(APPLE_CHAR);
                return;
            }
            count++;
        }
    }
}

void getDirection() {
    int newDirection;
    int key = _getch();
    switch(key) {
        case 119: // w
        case 87: // W
            newDirection = 0;
        case 100: // d
        case 68: // D
            newDirection = 1;
        case 115: // s
        case 83: // S
            newDirection = 2;
        case 97: // a
        case 65: // A
            newDirection = 3;
        default:
            newDirection = direction;
    }
    direction = (direction % 2 == newDirection % 2) ? direction : newDirection;
}

void moveSnake() {
    printf("%s", "\033[1;32m");
    printf("This text is green!\n");


    Point nextPosition = snakeBody[0];
    switch(direction) {
        case 0:
            nextPosition.y--;
        case 1:
            nextPosition.x++;
        case 2:
            nextPosition.y++;
        case 3:
            nextPosition.x--;
    }
    nextPosition.x = (nextPosition.x + FIELD_WIDTH) % FIELD_WIDTH;
    nextPosition.y = (nextPosition.y + FIELD_HEIGHT) % FIELD_HEIGHT;

    if(field[nextPosition.x][nextPosition.y] == 1) {
        gameOver = 1;
        return;
    }

    if(field[nextPosition.x][nextPosition.y] == 2) {
        score++;
        snakeLenght++;
        if(snakeLenght == fieldArea) {
            gameOver = 1;
        }
    }
    


    memmove(snakeBody + 1, snakeBody, snakeLenght * sizeof(int));

    snakeBody;








}

int main() {
    while(1) {
        init();
        while(!gameOver) {
            getDirection();


        }
    }
    return 0;
}
