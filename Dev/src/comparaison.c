#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/indexation.h"
#include "../include/img.h"
#include "../include/pile_Img.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"
#include "../include/recherche.h"
#include "../include/comparaison.h"

/* 
 ----------------------- Signature -------------------------
|															|
|		Auteur : BERNAT Loan								|
|		Date de creation : 23/12/21							|
|		Date de derniere MAJ : xx/01/22						|
|															|
 ----------------------------------------------------------- 
 */

//Renvoie le plus petit des taux de similarité des deux valeurs.
int calculSimValeur(int v1, int v2){
    int ecart;
    int max = v2, min=v1;
    if (v1 > v2) {
        max=v1;
        min=v2;
    }

    if (max == 0){
        ecart = 0;
    } else {
        ecart = ((max - min)*100) / max;
    }
    return (100 - ecart);
}


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* image1, DESCRIPTEUR_IMAGE* image2){
    int nbValeur, tauxSim=0;
    if (image1->t_max != image2->t_max) return 0;

    nbValeur = image1->t_max;
    if (nbValeur==0) return -1;

    for (int i = 0 ; i < nbValeur ; i++){
        tauxSim = tauxSim + calculSimValeur(image1->histogramme[i],image2->histogramme[i]);
    }

    tauxSim = tauxSim/nbValeur;

    return (tauxSim);
}

