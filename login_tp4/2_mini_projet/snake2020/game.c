#include <MLV/MLV_all.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

void print_help(FILE *stream, int exit_code) {
  fprintf(stream,
          "Usage : snake2025 <options>\n"
          "-h --help : afficher l'aide\n"
          "-i --input source : spécifier le chemin vers la grille de jeu\n");
  exit(exit_code);
}

void get_input(char grid[NBL][NBC + 1], char *inputFile) {
  char line[NBC + 2];
  FILE *file = fopen(inputFile, "r");
  if (file != NULL) {
    int i = 0;
    while (i < NBL && fgets(line, sizeof(line), file)) {
      int j = 0;
      while (j < NBC && line[j] != '\0' && line[j] != '\n') {
        grid[i][j] = line[j];
        j++;
      }
      grid[i][j] = '\0';
      i++;
    }
    fclose(file);
  } else {
    fprintf(stderr, "Erreur : fichier introuvable ou inutilisable\n");
    exit(1);
  }
}

void stop_game(int width, int height, int win, int mur) {
  char *message =
      mur ? "Vous avez perdu !\nVous vous êtes pris un mur."
          : "Vous avez perdu !\nVotre serpent s'est mordu la queue.";
  MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
  while (MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                       NULL) == MLV_NONE ||
         touche != MLV_KEYBOARD_ESCAPE) {
    int largeur_boite = 300;
    int hauteur_boite = 100;

    int x = (width - largeur_boite) / 2;
    int y = (height - hauteur_boite) / 2;

    MLV_draw_filled_rectangle(x, y, largeur_boite, hauteur_boite,
                              MLV_COLOR_LIGHT_GREEN);
    MLV_draw_rectangle(x, y, largeur_boite, hauteur_boite, MLV_COLOR_BLACK);

    if (win) {
      MLV_draw_text_box(x, y, largeur_boite, hauteur_boite, "Vous avez gagné !",
                        9, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                        MLV_COLOR_LIGHT_GREEN, MLV_TEXT_CENTER,
                        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    } else {
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

int main(int argc, char *argv[]) {
  int next_option;
  char grid[NBL][NBC + 1] = {"w                                  w",
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
  const char *const short_options = "hi:";
  const struct option long_options[] = {
      {"help", 0, NULL, 'h'}, {"input", 1, NULL, 'i'}, {NULL, 0, NULL, 0}};

  next_option = getopt_long(argc, argv, short_options, long_options, NULL);

  switch (next_option) {
    case 'h':
      print_help(stdout, 0);
      break;
    case 'i':
      get_input(grid, optarg);
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
  MLV_change_frame_rate(60);
  Snake serpent = {.pos = {{1, 3}, {1, 2}, {1, 1}, {1, 0}}};
  serpent.dir = RIGHT;
  place_snake(grid, serpent);

  while (1) {
    MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

    loop_count = (loop_count + 1) % DIFFICULTY;

    if (loop_count == 0) {
      switch (move_snake(&serpent, grid)) {
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

      if (nb_fruit < 1) {
        stop_game(width, height, 1, 0);
      }
    }

    MLV_clear_window(MLV_COLOR_BROWN);
    draw_grid(grid);
    MLV_actualise_window();

    switch (touche) {
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
