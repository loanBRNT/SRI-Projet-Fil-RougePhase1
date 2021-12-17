#include "img.h"

Descripteur initDescripteur(int nb_composantes, int n){
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

int decalageRouge(int val, int n){
    int res;
    switch(n){
        case 1 :
            res = val >> 5;
            break;
        case 2 :
            res = val >> 2;
            break;
        case 3 :
            res = val << 1;
            break;
        case 4 :
            res = val << 4;
            break;
        default :
            printf("Erreur sur la valeur de n");
    }
    return res;
}

int decalageVert(int val, int n){
    int res;
    switch(n){
        case 1 :
            res = val >> 6;
            break;
        case 2 :
            res = val >> 4;
            break;
        case 3 :
            res = val >> 2;
            break;
        case 4 :
            res = val;
            break;
        default :
            printf("Erreur sur la valeur de n");
    }
    return res;
}

int decalageBleu(int val, int n){
    int res;
    switch(n){
        case 1 :
            res = val >> 7;
            break;
        case 2 :
            res = val >> 6;
            break;
        case 3 :
            res = val >> 5;
            break;
        case 4 :
            res = val >> 4;
            break;
        default :
            printf("Erreur sur la valeur de n");
    }
    return res;
}

void quantificationRGB(int longueur, int hauteur, Descripteur *des, FILE* fichier, int n){
    int val;
    TAB tempo;

    tempo = malloc(longueur*hauteur*sizeof(long));
    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification rouge dans temporaire
        fscanf(fichier,"%d", &val);
        tempo[cptemp] = decalageRouge((val & conversion_masques[n-1]), n);
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification verte dans temporaire
        fscanf(fichier, "%d", &val);
        tempo[cptemp] = tempo[cptemp] + decalageVert((val & conversion_masques[n-1]),n );
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification bleu dans temporaire
        fscanf(fichier, "%d", &val);
        tempo[cptemp] = tempo[cptemp] + decalageBleu( (val & conversion_masques[n-1]), n);
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){
        (*des).histogramme[tempo[cptemp]]++;
    }
    free(tempo);
}

void quantificationNB(Descripteur *descripteur, int longueur, int hauteur, FILE* fichier, int n){
    int val;
    for (int cpt = 0; cpt < longueur*hauteur; cpt++){
            fscanf(fichier,"%d", &val);
            val = ( (val & conversion_masques[n-1]) >> (8-n));
            (*descripteur).histogramme[val] ++;
    }
}

Descripteur indexer_image(char* nom, int n){

    // Declaration varibales
    int longueur , hauteur, d;
    Descripteur descripteur;
    FILE* fichier = NULL;

    // Ouverture de l'image
    fichier = fopen(nom,"r");

    if (fichier != NULL) {

        // Récupération des données image
        fscanf(fichier,"%d %d %d", &longueur, &hauteur, &d);
        // Initialisation en fonction du fichier
        descripteur = initDescripteur(d,n);
        descripteur.ID = 2;

        switch(d){
            case 1 : // Quantification NB
                quantificationNB(&descripteur,longueur,hauteur,fichier,n);
                break;
            case 3 : // Quantification RGB
                quantificationRGB(longueur,hauteur,&descripteur,fichier,n);
                break;
         default : printf("Format de l'image pas supporté\n");
        }
        fclose(fichier);
    }
    else
        printf("Echec de l'ouverture de l'image à indexer");

    return descripteur;
}