
#include <MLV/MLV_all.h>

int main(int argc, char *argv[])
{
    MLV_create_window("Découverte - Maison", "shapes", 640, 480);

    MLV_draw_filled_rectangle(200, 200, 200, 200, MLV_COLOR_RED);

    int i, j;
    for (j = 220; j <= 360; j += 40)
    {
        for (i = 220; i <= 360; i += 40)
        {
            MLV_draw_filled_rectangle(i, j, 20, 20, MLV_COLOR_WHITE);
        }
    }

    MLV_draw_filled_circle(550, 100, 50, MLV_COLOR_YELLOW);

    int coordonnee1_x[3] = {200, 300, 400};
    int coordonnee1_y[3] = {200, 100, 200};
    MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_GREEN);

    MLV_actualise_window();
    MLV_wait_seconds(10);
    MLV_free_window();
    return 0;
}
