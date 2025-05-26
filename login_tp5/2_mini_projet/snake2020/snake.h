#pragma once

#define SNAKE_SIZE 4

typedef struct Coord
{
    int x;
    int y;
} Coord;

typedef enum direction
{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
} Direction;

typedef struct struct_snake
{
    Coord pos[SNAKE_SIZE];
    Direction dir;
} Snake;

void crawl(Snake *s);
