#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *inputFile = fopen("lecture.txt", "a+");
    /*
    Utilisation de "a+" pour "appending" pour pouvoir écrire à la suite du texte existant
    */
    fprintf(inputFile, "%s\n", "bonjour");
    fclose(inputFile);
    return 0;
}
