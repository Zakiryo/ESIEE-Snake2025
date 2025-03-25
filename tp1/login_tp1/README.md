# TP N°1 : Découverte de la bibliothèque lMLV - Yohan RUDNY E3FR 3R

## Introduction

L'objectif de ce TP est l'initiation à la bibliothèque "lMLV" permettant de manipuler des interfaces graphiques et des formes.

Le travail réalisé se trouve dans le fichier [main.c](https://git.esiee.fr/rudnyy/tp1/-/blob/main/main.c) et les réponses aux questions posées dans le sujets se trouvent ci-dessous.

## Essaie de compilation de `01_hello_world.c`

Même si la bibliothèque est installée sur notre OS : la compilation avec la commande `gcc 01_hello_world.c` ne fonctionne pas. On obtient des erreurs du type :
> 01_hello_world.c:(.text+0x2e) : référence indéfinie vers « MLV_... »

## Essaie de compilation avec `gcc -c 01_hello_world.c`

Si l'on réessaye la compilation en ajoutant le paramètre `-c`, on observe qu'on génère effectivement un fichier objet `01_hello_world.o`. On devine ainsi qu'il faut que l'on précise, lors de la compilation, que l'on veut utiliser la bibliothèque `lMLV` pour que l'éditeur de lien prenne celle-ci en compte.

## Essaie de compilation avec `gcc 01_hello_world.o -lMLV`

Avec notre fichier objet, on compile en ajoutant le paramètre `-lMLV` pour dire à l'éditeur de lien d'ajouter cette bibliothèque. Si l'on essaye la compilation, on obtiens bien un fichier de sortie `a.out`.

## Création du makefile

J'ai donc créé un makefile permettant d'exécuter toutes les commandes précédentes automatiquement à l'aide seulement de la commande "make". Le code de celui-ci se trouve dans le fichier [makefile](https://git.esiee.fr/rudnyy/tp1/-/blob/main/makefile) et prend en compte les instructions de compilation de l'ESIEE avec les paramètres `-Wall -ansi`.
