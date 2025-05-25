#include <stdio.h>
#include <stdlib.h>

void display_tab(int *tab, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d\n", tab[i]);
    }
}

int charSize(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}

char *concat(char *s1, char *s2)
{
    int size_s1 = charSize(s1), size_s2 = charSize(s2), i;
    char *s = malloc(size_s1 + size_s2 + 1);
    if (s == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    };
    for (i = 0; i < size_s1; ++i)
    {
        s[i] = s1[i];
    }
    for (i = 0; i < size_s2; ++i)
    {
        s[size_s1 + i] = s2[i];
    }
    s[size_s1 + size_s2] = '\0';
    return s;
}

int main()
{
    int *tab = (int *)malloc(sizeof(int) * 30);
    if (tab == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    };
    display_tab(tab, 30); /*Les valeurs affichées après "malloc" sont celles présentes de base aux adresses mémoires*/
    free(tab);

    tab = (int *)calloc(30, sizeof(int));
    if (tab == NULL)
    {
        fprintf(stderr, "Erreur d'allocation dynamique.");
        exit(1);
    };
    display_tab(tab, 30); /*Les valeurs affichées après "calloc" sont 0 car toutes initialisées à 0*/
    free(tab);

    char *s = concat("sa", "lut");
    printf("%s\n", s);
    free(s);

    return 0;
}
