#include "snake.h"

#define NBL 22
#define NBC 36

void debug(char matrix[NBL][NBC + 1]);
int compute_size(int w, int h);
void draw_grid(char grid[NBL][NBC + 1]);
void place_snake(char grid[NBL][NBC + 1], Snake s);
void move_snake(Snake *s, char grid[NBL][NBC + 1]);

enum Element
{
    WALL = 'b',
    EMPTY = ' ',
    FRUIT = 'f',
    SNAKE = 's',
};
