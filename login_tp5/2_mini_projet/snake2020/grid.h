#include "snake.h"

#define DIFFICULTY 4

typedef enum element
{
    WALL = 'w',
    EMPTY = ' ',
    FRUIT = 'f',
    SNAKE = 's',
} Element;

typedef struct grid
{
    int nbl;
    int nbc;
    char **grid;
} Grid;

void debug(Grid *grid);
int compute_size(int w, int h, Grid *grid);
void draw_grid(Grid *grid);
void place_snake(Grid *grid, Snake s);
Element move_snake(Snake *s, Grid *grid);
int get_nb_fruit(Grid *grid);
Grid *allocate_grid(int n, int m);
void free_grid(Grid *g);
