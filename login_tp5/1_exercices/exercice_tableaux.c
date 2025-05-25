#include <stdio.h>
#include <stdlib.h>

int **alloue(int n, int m)
{
    int **tab = malloc(sizeof(int) * n);
    if (tab == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    };

    int i;
    for (i = 0; i < n; ++i)
    {
        tab[i] = malloc(sizeof(int) * m);
        if (tab[i] == NULL)
        {
            fprintf(stderr, "Erreur d'allocation dynamique.");
            exit(1);
        };
    }
    return tab;
}

void libere(int **tab, int n, int m)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        free(tab[i]);
    }
    free(tab);
}

int main()
{
    int **tab = alloue(20, 20);
    libere(tab, 20, 20);
    return 0;
}
