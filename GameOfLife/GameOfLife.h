#pragma once

typedef struct {
    unsigned char* data;
    unsigned int width;
    unsigned int height;
} Field;

Field createField(unsigned int width, unsigned int height);

void gameLoop(Field* field);

void editorLoop(Field* field);

void drawBorders(Field* field);

void drawField(Field* field);
