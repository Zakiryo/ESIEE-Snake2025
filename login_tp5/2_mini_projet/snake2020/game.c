#include <MLV/MLV_all.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

void print_help(FILE *stream, int exit_code)
{
    fprintf(stream,
            "Usage : snake2025 <options>\n"
            "-h --help : afficher l'aide\n"
            "-i --input source : spécifier le chemin vers la grille de jeu\n");
    exit(exit_code);
}

int count_nb_line(FILE *stream)
{
    int count = 0;
    char *buf = NULL;
    size_t size = 0;

    while (getline(&buf, &size, stream) != -1)
    {
        count++;
    }

    free(buf);
    return count;
}

void copy(const char *src, char *dest, int nbc)
{
    for (int i = 0; i < nbc; i++)
    {
        dest[i] = src[i];
    }
}

Grid *get_input(char *inputFile)
{
    int nbl, nbc;
    size_t size_buf = 0;
    FILE *stream;
    char *buf = NULL;
    Grid *g;
    int i;

    stream = fopen(inputFile, "r");
    nbl = count_nb_line(stream); /* fonction a écrire */
    rewind(stream);              /* pour remettre la position de lecture du fichier au début, voir la manpage */
    nbc = getline(&buf, &size_buf, stream);
    if (nbc == -1)
    { /* erreur, le fichier est certainement mal formé */
        fprintf(stderr, "Erreur : fichier vide ou mal formé\n");
        fclose(stream);
        exit(1);
    }
    else
        nbc--; /* getline compte le retour à la ligne */

    g = allocate_grid(nbl, nbc);
    copy(buf, g->grid[0], nbc); /* fonction a écrire, qui ne copie que les caractères que l'on veut (pas \0 ni \n) */
    for (i = 1; i < nbl; i++)
    {
        int size_tmp = getline(&buf, &size_buf, stream);
        if (size_tmp != nbc + 1)
        {
            /* il y a un probleme, il faut quitter le programme */
            fprintf(stderr, "Erreur : la ligne %d n'a pas la bonne taille (%d attendu, %d lu)\n", i + 1, nbc + 1, size_tmp);
            free(buf);
            free_grid(g);
            fclose(stream);
            exit(1);
        }
        copy(buf, g->grid[i], nbc);
    }
    free(buf);
    fclose(stream);
    return g;
}

void stop_game(int width, int height, int win, int mur)
{
    char *message =
        mur ? "Vous avez perdu !\nVous vous êtes pris un mur."
            : "Vous avez perdu !\nVotre serpent s'est mordu la queue.";
    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    while (MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                         NULL) == MLV_NONE ||
           touche != MLV_KEYBOARD_ESCAPE)
    {
        int largeur_boite = 300;
        int hauteur_boite = 100;

        int x = (width - largeur_boite) / 2;
        int y = (height - hauteur_boite) / 2;

        MLV_draw_filled_rectangle(x, y, largeur_boite, hauteur_boite,
                                  MLV_COLOR_LIGHT_GREEN);
        MLV_draw_rectangle(x, y, largeur_boite, hauteur_boite, MLV_COLOR_BLACK);

        if (win)
        {
            MLV_draw_text_box(x, y, largeur_boite, hauteur_boite, "Vous avez gagné !",
                              9, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                              MLV_COLOR_LIGHT_GREEN, MLV_TEXT_CENTER,
                              MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        }
        else
        {
            MLV_draw_text_box(x, y, largeur_boite, hauteur_boite, message, 9,
                              MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_LIGHT_BLUE,
                              MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER,
                              MLV_VERTICAL_CENTER);
        }

        MLV_actualise_window();
    }
    MLV_free_window();
    exit(0);
}

int main(int argc, char *argv[])
{
    int next_option;
    Grid *grid = get_input("./levels/default");
    const char *const short_options = "hi:";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'}, {"input", 1, NULL, 'i'}, {NULL, 0, NULL, 0}};

    next_option = getopt_long(argc, argv, short_options, long_options, NULL);

    switch (next_option)
    {
    case 'h':
        print_help(stdout, 0);
        break;
    case 'i':
        free_grid(grid);
        grid = get_input(optarg);
        break;
    case '?':
        print_help(stderr, 1);
        break;
    case -1:
        break;
    default:
        abort();
    }

    int nb_fruit = get_nb_fruit(grid);
    int loop_count = 0;
    MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    int width = 1280, height = 720;

    MLV_create_window("SNAKE", "3R-IN1B", width, height);
    MLV_change_frame_rate(24);
    Snake serpent = {.pos = {{1, 3}, {1, 2}, {1, 1}, {1, 0}}};
    serpent.dir = RIGHT;
    place_snake(grid, serpent);

    while (1)
    {
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

        loop_count = (loop_count + 1) % DIFFICULTY;

        if (loop_count == 0)
        {
            switch (move_snake(&serpent, grid))
            {
            case FRUIT:
                --nb_fruit;
                break;
            case WALL:
                stop_game(width, height, 0, 1);
                break;
            case SNAKE:
                stop_game(width, height, 0, 0);
                break;
            default:
                break;
            }

            if (nb_fruit < 1)
            {
                stop_game(width, height, 1, 0);
            }
        }

        MLV_clear_window(MLV_COLOR_BROWN);
        draw_grid(grid);
        MLV_actualise_window();

        switch (touche)
        {
        case MLV_KEYBOARD_DOWN:
            serpent.dir = BOTTOM;
            break;
        case MLV_KEYBOARD_UP:
            serpent.dir = TOP;
            break;
        case MLV_KEYBOARD_RIGHT:
            serpent.dir = RIGHT;
            break;
        case MLV_KEYBOARD_LEFT:
            serpent.dir = LEFT;
            break;
        case MLV_KEYBOARD_ESCAPE:
            MLV_free_window();
            return 0;
        default:
            break;
        }

        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();
    }
    MLV_free_window();
    return 0;
}
