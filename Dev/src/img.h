#ifndef IMG_H_INCLUS
#define IMG_H_INCLUS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 2

static const int conversion_masques[8]= {0b10000000 ,0b11000000, 0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111};

/* DECLARATIONS DES TYPES */

typedef int* TAB;

typedef struct Descripteur {
    int ID;
    int t_max;
    int* histogramme;
}Descripteur;

/* DECLARATIONS DES FONCTIONS */

Descripteur initDescripteur(int nb_composantes);

void quantificationRGB(TAB *temporaire, int longueur, int hauteur);

void quantificationNB(Descripteur *descripteur, int longueur, int hauteur);

void indexer_image(/*char* nom*/);

#endif