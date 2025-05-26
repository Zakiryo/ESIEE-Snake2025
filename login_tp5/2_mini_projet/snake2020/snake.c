#include "snake.h"

#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

void crawl(Snake *s)
{
    int head_pos_x = s->pos[0].x, head_pos_y = s->pos[0].y;
    switch (s->dir)
    {
    case TOP:
        head_pos_x = (s->pos[0].x - 1 + NBL) % NBL;
        break;
    case BOTTOM:
        head_pos_x = (s->pos[0].x + 1) % NBL;
        break;
    case LEFT:
        head_pos_y = (s->pos[0].y - 1 + NBC) % NBC;
        break;
    case RIGHT:
        head_pos_y = (s->pos[0].y + 1) % NBC;
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
