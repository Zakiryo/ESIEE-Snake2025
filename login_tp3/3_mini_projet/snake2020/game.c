#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include <MLV/MLV_all.h>
#include <getopt.h>

void print_help(FILE *stream, int exit_code)
{
    fprintf(stream, "Exemple texte d'aide\n");
    exit(exit_code);
}

int main(int argc, char *argv[])
{

    int next_option;
    const char *const short_options = "h";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {NULL, 0, NULL, 0}};

    next_option = getopt_long(argc, argv, short_options,
                              long_options, NULL);
    switch (next_option)
    {
    case 'h':
        print_help(stdout, 0);
    case '?':
        print_help(stderr, 1);
    case -1:
        break;
    default:
        abort();
    }

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