#include "grid.h"

#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

void debug(Grid *matrix)
{
    int i, j;
    for (i = 0; i < matrix->nbl; ++i)
    {
        printf("\n");
        for (j = 0; j < matrix->nbc + 1; ++j)
        {
            printf("%c", matrix->grid[i][j]);
        }
    }
}

int compute_size(int w, int h, Grid *grid)
{
    int aw = w / grid->nbc;
    int ah = h / grid->nbl;
    return aw < ah ? aw : ah;
}

void draw_grid(Grid *grid)
{
    int w = MLV_get_window_width();
    int h = MLV_get_window_height();
    int a = compute_size(w, h, grid);
    int i, j;
    for (i = 0; i < grid->nbl; i++)
    {
        for (j = 0; j < grid->nbc + 1; j++)
        {
            char square = grid->grid[i][j];
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

void place_snake(Grid *grid, Snake s)
{
    int i;
    for (i = 0; i < SNAKE_SIZE; ++i)
    {
        grid->grid[s.pos[i].x][s.pos[i].y] = SNAKE;
    }
}

Element move_snake(Snake *s, Grid *grid)
{
    grid->grid[s->pos[SNAKE_SIZE - 1].x][s->pos[SNAKE_SIZE - 1].y] = EMPTY;
    crawl(s, grid->nbl, grid->nbc);
    Element previous_head = grid->grid[s->pos[0].x][s->pos[0].y];
    grid->grid[s->pos[0].x][s->pos[0].y] = SNAKE;
    return previous_head;
}

int get_nb_fruit(Grid *grid)
{
    int i, j, nb_fruit = 0;
    for (i = 0; i < grid->nbl; ++i)
    {
        for (j = 0; j < grid->nbc + 1; ++j)
        {
            if (grid->grid[i][j] == FRUIT)
            {
                ++nb_fruit;
            }
        }
    }
    return nb_fruit;
}

Grid *allocate_grid(int n, int m)
{
    Grid *g = (Grid *)malloc(sizeof(Grid));
    if (g == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    }

    g->nbl = n;
    g->nbc = m;

    g->grid = (char **)malloc(n * sizeof(char *));
    if (g->grid == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++)
    {
        g->grid[i] = (char *)malloc(m * sizeof(char));
        if (g->grid[i] == NULL)
        {
            fprintf(stderr, "Erreur d'allocation dynamique.");
            exit(1);
        }
    }

    return g;
}

void free_grid(Grid *g)
{
    if (g == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    }

    int i;
    for (i = 0; i < g->nbl; i++)
    {
        free(g->grid[i]);
    }

    free(g->grid);
    free(g);
}
