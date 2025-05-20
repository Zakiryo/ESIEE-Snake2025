#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *inputFile = fopen("lecture.txt", "r+");
    char c;
    while ((fscanf(inputFile, "%c", &c)) != EOF)
    {
        printf("%c", c);
    }
    fclose(inputFile);
    return 0;
}
