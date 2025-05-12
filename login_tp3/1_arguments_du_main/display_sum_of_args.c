#include <stdio.h>

int isNumeric(char *s);

int main(int argc, char *argv[])
{
    int i, n, sum = 0;
    for (i = 1; i < argc; ++i)
    {
        if (isNumeric(argv[i]))
        {
            sscanf(argv[i], "%d", &n);
            sum += n;
        }
    }
    printf("%d\n", sum);
    return 0;
}

int isNumeric(char *s)
{
    char c;
    if (s[0] == '-') // Gestion des nombres négatifs
    {
        c = *s++;
    }
    while ((c = *s++) != '\0')
    {
        if (c < '0' || c > '9')
        {
            return 0;
        }
    }
    return 1;
}
