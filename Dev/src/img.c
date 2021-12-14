#include "img.h"
#include "math.h"

Descripteur initDescripteur(int nb_composantes){
    Descripteur descri;
    descri.t_max = pow(2,(n*nb_composantes));
    descri.histogramme = NULL;
    descri.histogramme = malloc(descri.t_max*sizeof(int));
    if(descri.histogramme == NULL) {
        printf("Erreur du malloc");
        exit(0);
    }
    for (int i = 0 ; i < descri.t_max; i++) {
        descri.histogramme[i] = 0;
    }
    return descri;
}

void quantificationRGB(TAB *temporaire, int longueur, int hauteur){
    int val;
    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){
        scanf("%d", &val);
        *temporaire[cptemp] = val & conversion_masques[n-1];
    }
}

void quantificationNB(Descripteur *descripteur, int longueur, int hauteur){
    int val;
    for (int cpt = 0; cpt < longueur*hauteur; cpt++){
            scanf("%d", &val);
            val = ( (val & conversion_masques[n-1]) >> (8-n));
            //printf("Indice : %d, Valeur : %d\n",cpt, val);
            (*descripteur).histogramme[val] ++;
    }
}

void indexer_image(/*char* nom*/){

    // Declaration varibales
    int longueur , hauteur, d;
    Descripteur descripteur;
    TAB tempo;

    // Ouverture de l'image

    // Récupération des données image
    scanf("%d", &longueur);
    scanf("%d", &hauteur);
    scanf("%d", &d);
    tempo = malloc(longueur*hauteur*sizeof(int));

    // Initialisation en fonction du fichier
    descripteur = initDescripteur(d);
    descripteur.ID = 234;

    switch(d){
        case 1 : // Quantification NB
            quantificationNB(&descripteur,longueur,hauteur);

            break;
        case 3 : // Quantification RGB
            quantificationRGB(&tempo,longueur,hauteur);
            break;
        default : printf("Erreur sur le nombre de composantes de l'image\n");
        exit(0);
    }
    printf("ID du fichier : %d\n",descripteur.ID);
    printf("Taille du tableau : %d\n",descripteur.t_max);
    for(int i = 0; i<descripteur.t_max; i++){
        printf("%d\n",descripteur.histogramme[i]);
    }
}