#include "snake.h"

#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

void crawl(Snake *s, int nbl, int nbc)
{
    int head_pos_x = s->pos[0].x, head_pos_y = s->pos[0].y;
    switch (s->dir)
    {
    case TOP:
        head_pos_x = (s->pos[0].x - 1 + nbl) % nbl;
        break;
    case BOTTOM:
        head_pos_x = (s->pos[0].x + 1) % nbl;
        break;
    case LEFT:
        head_pos_y = (s->pos[0].y - 1 + nbc) % nbc;
        break;
    case RIGHT:
        head_pos_y = (s->pos[0].y + 1) % nbc;
        break;
    }
    int i;
    for (i = 1; i < SNAKE_SIZE; ++i)
    {
        s->pos[SNAKE_SIZE - i] = s->pos[SNAKE_SIZE - (i + 1)];
    }

    s->pos[1] = s->pos[0];
    s->pos[0].x = head_pos_x;
    s->pos[0].y = head_pos_y;
}
