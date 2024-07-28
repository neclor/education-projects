#include "GameOfLife2.h"

#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25

int main() {
    Field field = createField(FIELD_WIDTH, FIELD_HEIGHT);
    drawHelp(FIELD_WIDTH);
    while (1) {
        editorLoop(&field);
        gameLoop(&field);
    }
    return 0;
}
