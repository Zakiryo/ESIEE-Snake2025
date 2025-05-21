#include "snake.h"

#define NBL 22
#define NBC 36
#define DIFFICULTY 4

typedef enum element {
  WALL = 'w',
  EMPTY = ' ',
  FRUIT = 'f',
  SNAKE = 's',
} Element;

void debug(char matrix[NBL][NBC + 1]);
int compute_size(int w, int h);
void draw_grid(char grid[NBL][NBC + 1]);
void place_snake(char grid[NBL][NBC + 1], Snake s);
Element move_snake(Snake *s, char grid[NBL][NBC + 1]);
int get_nb_fruit(char grid[NBL][NBC + 1]);
