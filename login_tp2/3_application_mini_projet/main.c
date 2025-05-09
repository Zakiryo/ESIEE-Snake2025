#include <stdio.h>
#include <stdlib.h>

void debug(char matrix[][7], int nbl, int nbc);

int main(int argc, char *argv[])
{
    char grid[8][7] = {
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr"};
    debug(grid, 8, 7);
    return 0;
}

void debug(char matrix[][7], int nbl, int nbc)
{
    int i, j;
    for (i = 0; i < nbl; ++i)
    {
        printf("\n");
        for (j = 0; j < nbc; ++j)
        {
            printf("%c", matrix[i][j]);
        }
    }
}
