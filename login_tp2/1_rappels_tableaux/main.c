#include <stdio.h>
#include <stdlib.h>

int max_tab(int *tab, int size);

void copy_tab(const int arr1[], const int size1, int arr2[], const int size2);

void copy_tab_v2(int arr1[], const int size1, const int arr2[], const int size2, const int arr3[], const int size3);

int charSize(const char str[]);

int higherPrefixSize(const char str1[], const char str2[]);

int main(int argc, char *argv[])
{
    int size, i;
    printf("Entrez la taille de votre tableau : ");
    scanf("%d", &size);
    int *tab = (int *)calloc(size, sizeof(int));
    printf("Entrez les %d éléments de votre tableau : ", size);
    for (i = 0; i < size; ++i)
    {
        scanf("%d", &tab[i]);
    }
    printf("Le maximum du tableau est %d.", max_tab(tab, size));
    return 0;
}

int max_tab(int *tab, int size)
{
    int max = 0, i;
    for (i = 0; i < size; ++i)
    {
        max = max < tab[i] ? tab[i] : max;
    }
    return max;
}

void copy_tab(const int arr1[], const int size1, int arr2[], const int size2)
{
    const int maxSize = size1 > size2 ? size1 : size2, minSize = size1 < size2 ? size1 : size2;
    int i;
    for (i = 0; i < maxSize; i++)
    {
        if (i < minSize)
        {
            arr2[i] = arr1[i];
        }
    }
}

void copy_tab_v2(int arr1[], const int size1, const int arr2[], const int size2, const int arr3[], const int size3)
{
    copy_tab(arr2, size2, arr1, size1);
    copy_tab(arr3, size3, arr1, size1);
}

int charSize(const char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i;
}

int higherPrefixSize(const char str1[], const char str2[])
{
    const int minSize = charSize(str1) < charSize(str2) ? charSize(str1) : charSize(str2);
    char higherPrefix[minSize];
    int i;
    for (i = 0; i < minSize; i++)
    {
        if (str1[i] == str2[i])
        {
            higherPrefix[i] = str1[i];
        }
    }
    return charSize(higherPrefix);
}