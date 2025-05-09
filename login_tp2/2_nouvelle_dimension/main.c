#include <stdio.h>
#include <stdlib.h>

#define NBL 3
#define NBC 3

void remplirMatrice(int matrice[NBL][NBC]);
void afficherMatrice(int matrice[NBL][NBC]);
int produitDesSommes(int matrice[NBL][NBC]);

int main(int argc, char *argv[])
{
    int matrice[NBL][NBC];
    remplirMatrice(matrice);
    afficherMatrice(matrice);
    printf("Le produit des sommes de la matrice est : %d", produitDesSommes(matrice));
}

void remplirMatrice(int matrice[NBL][NBC])
{
    int i, j;
    for (i = 0; i < NBL; i++)
    {
        for (j = 0; j < NBC; j++)
        {
            printf("Entrez la valeur pour matrice[%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void afficherMatrice(int matrice[NBL][NBC])
{
    int i, j;
    for (i = 0; i < NBL; i++)
    {
        printf("\n");
        for (j = 0; j < NBC; j++)
        {
            printf("%d", matrice[i][j]);
        }
    }
    printf("\n");
}

int produitDesSommes(int matrice[NBL][NBC])
{
    int produit = 1, somme;
    for (int i = 0; i < NBL; i++)
    {
        somme = 0;
        for (int j = 0; j < NBC; j++)
        {
            somme += matrice[i][j];
        }
        produit *= somme;
    }
    return produit;
}
