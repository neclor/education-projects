#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define FIELD_WIDTH 20
#define FIELD_HEIGHT 20

#define EMPTY_CELL 0
#define SNAKE_CELL 1
#define APPLE_CELL 2

#define FLOOR_CHAR '.'
#define SNAKE_CHAR '@'
#define APPLE_CHAR '$'

typedef struct {
    int x, y;
} Point;

int field[FIELD_WIDTH][FIELD_HEIGHT] = { EMPTY_CELL };

int gameOver;

Point snakeBody[FIELD_WIDTH * FIELD_HEIGHT];
int snakeLenght;
int direction;

void drawField() {
    char screenData[FIELD_HEIGHT][FIELD_WIDTH + 1];
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        screenData[y][FIELD_WIDTH] = '\n';
        for (int x = 0; x < FIELD_WIDTH; x++) {
            switch (field[x][y]) {
                case(EMPTY_CELL):
                    screenData[y][x] = FLOOR_CHAR;
                    break;
                case(SNAKE_CELL):
                    screenData[y][x] = SNAKE_CHAR;
                    break;
                case(APPLE_CELL):
                    screenData[y][x] = APPLE_CHAR;
                    break;
            }
        }
    }
    screenData[FIELD_HEIGHT - 1][FIELD_WIDTH] = 0;
    printf("\033[%d;%dH", 1, 1);
    puts(screenData);
}

void drawScore() {
    printf("\033[%d;%dH", 1, FIELD_WIDTH + 2);
    printf("Score: %d", snakeLenght - 1);
}

void getDirection() {
    int newDirection;
    int key = _getch();
    switch (key) {
        case 119: // w
        case 87: // W
            newDirection = UP;
            break;
        case 100: // d
        case 68: // D
            newDirection = RIGHT;
            break;
        case 115: // s
        case 83: // S
            newDirection = DOWN;
            break;
        case 97: // a
        case 65: // A
            newDirection = LEFT;
            break;
        default:
            newDirection = direction;
    }
    direction = (direction % 2 == newDirection % 2) ? direction : newDirection;
}

void createApple() {
    int randomPosition = rand() % (FIELD_WIDTH * FIELD_HEIGHT - snakeLenght);
    int count = 0;
    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (field[x][y] == EMPTY_CELL) {
                if (randomPosition == count) {
                    field[x][y] = APPLE_CELL;
                    return;
                }
                count++;
            }
        }
    }
}

void moveSnake() {
    Point nextPosition = snakeBody[snakeLenght - 1];

    switch (direction) {
        case UP:
            nextPosition.y--;
            break;
        case RIGHT:
            nextPosition.x++;
            break;
        case DOWN:
            nextPosition.y++;
            break;
        case LEFT:
            nextPosition.x--;
            break;
    }
    nextPosition.x = (nextPosition.x + FIELD_WIDTH) % FIELD_WIDTH;
    nextPosition.y = (nextPosition.y + FIELD_HEIGHT) % FIELD_HEIGHT;

    if (field[nextPosition.x][nextPosition.y] == SNAKE_CELL) {
        gameOver = 1;
        return;
    }
    else if (field[nextPosition.x][nextPosition.y] == APPLE_CELL) {
        snakeLenght++;
        drawScore();
        if (snakeLenght == FIELD_WIDTH * FIELD_WIDTH) {
            gameOver = 1;
            return;
        }
        createApple();
    }
    else {
        field[snakeBody[0].x][snakeBody[0].y] = EMPTY_CELL;
        for (int i = 0; i < snakeLenght - 1; i++) {
            snakeBody[i] = snakeBody[i + 1];
        }
    }
    snakeBody[snakeLenght - 1] = nextPosition;
    field[nextPosition.x][nextPosition.y] = SNAKE_CELL;
}

void restart() {
    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            field[x][y] = EMPTY_CELL;
        }
    }
    Point snakeStartPosition = { FIELD_WIDTH / 2, FIELD_HEIGHT / 2 };
    snakeBody[0] = snakeStartPosition;
    snakeLenght = 1;
    direction = UP;

    field[snakeStartPosition.x][snakeStartPosition.y] = SNAKE_CELL;
    createApple();

    gameOver = 0;

    drawField();
    drawScore();
}

void init() {
    printf("\033[?25l");
}

int main() {
    init();
    while (1) {
        restart();
        while (!gameOver) {
            getDirection();
            moveSnake();
            drawField();
            Sleep(200);
        }
    }
    return 0;
}
