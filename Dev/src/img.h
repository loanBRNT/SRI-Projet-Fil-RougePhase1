#ifndef IMG_H_INCLUS
#define IMG_H_INCLUS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 2

static const int conversion_masques[8]= {0x80 ,0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};

/* DECLARATIONS DES TYPES */

typedef long* TAB;

typedef struct Descripteur {
    int ID;
    int t_max;
    int* histogramme;
}Descripteur;

/* DECLARATIONS DES FONCTIONS */

Descripteur initDescripteur(int nb_composantes);

void quantificationRGB(int longueur, int hauteur, Descripteur *des);

void quantificationNB(Descripteur *descripteur, int longueur, int hauteur);

void indexer_image(/*char* nom*/);

#endif