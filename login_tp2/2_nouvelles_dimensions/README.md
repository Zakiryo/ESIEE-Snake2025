# TP N°2, Partie 2 - Yohan RUDNY E3FR 3R

## Comparaison des temps d'exécution entre les deux programmes

On observe que le programme 1 s'exécute plus rapidement que le deuxième. Le premier programme parcourt la matrice ligne par ligne, ce qui est naturel pour le langage C. Le deuxième, lui, parcourt la matrice colonnes par colonne et doit donc retrouver en mémoire la ligne correspondante pour chaque élément du tableau. Le premier programme ne devant pas effectuer ces sauts, il est donc plus rapide.

## Fonctions demandées dans la seconde partie

Toutes les fonctions demandées dans la seconde partie du TP2 ont été codées dans le fichier [main.c](https://git.esiee.fr/rudnyy/snake2025/-/blob/main/tp2/login_tp2/2_nouvelles_dimensions/main.c).