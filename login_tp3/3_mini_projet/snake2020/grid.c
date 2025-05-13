#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include <MLV/MLV_all.h>

void debug(char matrix[NBL][NBC + 1])
{
    int i, j;
    for (i = 0; i < NBL; ++i)
    {
        printf("\n");
        for (j = 0; j < NBC + 1; ++j)
        {
            printf("%c", matrix[i][j]);
        }
    }
}

int compute_size(int w, int h)
{
    int aw = w / NBC;
    int ah = h / NBL;
    return aw < ah ? aw : ah;
}

void draw_grid(char grid[NBL][NBC + 1])
{
    int w = MLV_get_window_width();
    int h = MLV_get_window_height();
    int a = compute_size(w, h);
    int i, j;
    for (i = 0; i < NBL; i++)
    {
        for (j = 0; j < NBC+1; j++)
        {
            char square = grid[i][j];
            MLV_Color color;
            switch (square)
            {
            case WALL:
                color = MLV_COLOR_BLACK;
                break;
            case EMPTY:
                color = MLV_COLOR_WHITE;
                break;
            case FRUIT:
                color = MLV_COLOR_RED;
                break;
            case SNAKE:
                color = MLV_COLOR_GREEN;
                break;
            }
            MLV_draw_filled_rectangle(j * a, i * a, a, a, color);
        }
    }
    MLV_actualise_window();
}

void place_snake(char grid[NBL][NBC + 1], Snake s)
{
    int i;
    for (i = 0; i < SNAKE_SIZE; ++i)
    {
        grid[s.pos[i].x][s.pos[i].y] = SNAKE;
    }
}

void move_snake(Snake s, char grid[NBL][NBC + 1])
{
    grid[s.pos[SNAKE_SIZE - 1].x][s.pos[SNAKE_SIZE - 1].y] = EMPTY;
    crawl(s);
    grid[s.pos[0].x][s.pos[0].y] = SNAKE;
}
