#ifndef IMG_H_INCLUS
#define IMG_H_INCLUS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "time.h"

static const int conversion_masques[8]= {0x80 ,0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};

/* DECLARATIONS DES TYPES */

typedef int* TAB;

typedef struct Descripteur {
    int ID;
    int t_max;
    int* histogramme;
}Descripteur;

/* DECLARATIONS DES FONCTIONS */

Descripteur initDescripteur(int nb_composantes, int n);

int decalageRouge(int val, int n);

int decalageVert(int val, int n);

int decalageBleu(int val, int n);

void quantificationRGB(int longueur, int hauteur, Descripteur *des, FILE* fichier, int n);

void quantificationNB(Descripteur *descripteur, int longueur, int hauteur, FILE* fichier, int n);

int generationIdUnique(int choix);

Descripteur indexer_image(char* adresse, int n);

#endif