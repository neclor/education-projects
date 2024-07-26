#include "GameOfLife.h"

#define FIELD_WIDTH 100
#define FIELD_HEIGHT 100

int main()
{
    Field field = createField(FIELD_WIDTH, FIELD_HEIGHT);
    drawBorders(&field);
    drawField(&field);

    while (1){
        editorLoop(&field);
        gameLoop(&field);
    }
}



