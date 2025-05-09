#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include <MLV/MLV_all.h>

int main(int argc, char *argv[])
{
    MLV_create_window("Grille", "Grid", 400, 400);
    char grid[NBL][NBC + 1] = {
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr"};
    draw_grid(grid);
    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    while (touche != MLV_KEYBOARD_ESCAPE)
    {
        MLV_wait_keyboard(&touche, NULL, NULL);
    };
    MLV_free_window();
    return 0;
}