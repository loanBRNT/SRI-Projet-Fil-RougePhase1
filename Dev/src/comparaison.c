#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/comparaison.h"
/*#include "../include/"

Mettre les bon includes
*/

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
    int sim1,sim2;
    if (v1 != 0){
        sim1 = 100 - (abs(v1 - v2)*100)/ v1;
    } else {
        sim1 = 100;
    }
    if (v2 != 0){
        sim2 = 100 - (abs(v1 - v2)*100)/ v2;
    } else {
        sim2 = 100;
    }
    if (sim1 < sim2) return sim1;
    return sim2;
}


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE image1, DESCRIPTEUR_IMAGE image2){
    int nbValeur, tauxSim=0;
    if (image1.t_max != image2.t_max) return 0;

    nbValeur = image1.t_max;
    if (nbValeur==0) return -1;

    for (int i = 0 ; i < nbValeur ; i++){
        tauxSim = tauxSim + calculSimValeur(image1.histogramme[i],image2.histogramme[i]);
    }

    return (tauxSim/nbValeur);
}

