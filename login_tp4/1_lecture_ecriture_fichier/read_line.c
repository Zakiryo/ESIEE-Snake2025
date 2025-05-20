#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *inputFileR = fopen("lecture.txt", "r+");
    fclose(inputFileR);
    /*
    N'a pas modifié le fichier texte
    */
    FILE *inputFileW = fopen("lecture.txt", "w+");
    fclose(inputFileW);
    /*
    A modifié le fichier texte
    */
    return 0;
}
