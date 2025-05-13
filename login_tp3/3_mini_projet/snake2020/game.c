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
    char grid[NBL][NBC + 1] = {
        "w                                  w",
        "                                    ",
        "               f                    ",
        "                                    ",
        "     f               f              ",
        "                                    ",
        "                                    ",
        "               f                    ",
        "                                    ",
        "                                    ",
        "         wwwwwwwwww                 ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                  f                 ",
        "                                    ",
        "         f                f         ",
        "                                    ",
        "                 f                  ",
        "w                                  w"};
    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    int width = 640, height = 480;
    MLV_create_window("SNAKE", "3R-IN1B", width, height);
    MLV_change_frame_rate(24);
    Snake serpent = {
        .pos = {
            {1, 3},
            {1, 2},
            {1, 1},
            {1, 0}}};
    serpent.dir = RIGHT;
    place_snake(grid, serpent);

    while (MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == MLV_NONE || touche != MLV_KEYBOARD_ESCAPE)
    {
        MLV_clear_window(MLV_COLOR_BROWN);
        draw_grid(grid);
        MLV_actualise_window();
        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();
        move_snake(serpent, grid);
    }

    MLV_free_window();
    return 0;
}
