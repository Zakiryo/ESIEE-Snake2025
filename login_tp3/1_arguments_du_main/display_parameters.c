#include <stdio.h>

void toUpper(char *s);

int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; ++i)
    {
        toUpper(argv[i]);
    }
    return 0;
}

void toUpper(char *s)
{
    char c;
    while ((c = *s++) != '\0')
    {
        c = (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
        printf("%c", c);
    }
    printf("\n");
}