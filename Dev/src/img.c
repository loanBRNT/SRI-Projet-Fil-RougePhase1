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

void quantificationRGB(int longueur, int hauteur, Descripteur *des){
    int val;
    TAB tempo;

    tempo = malloc(longueur*hauteur*sizeof(long));
    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification rouge dans temporaire
        scanf("%d", &val);
        tempo[cptemp] = ( (val & conversion_masques[n-1]) >> 2 );
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){
        printf("%ld\n",tempo[cptemp]);
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification verte dans temporaire
        scanf("%d", &val);
        tempo[cptemp] = tempo[cptemp] + ( (val & conversion_masques[n-1]) >> 4 );
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){     //Sauvegarde de la quantification bleu dans temporaire
        scanf("%d", &val);
        tempo[cptemp] = tempo[cptemp] + ( (val & conversion_masques[n-1]) >> 6 );
    }

    for (int cptemp = 0; cptemp < longueur*hauteur; cptemp ++){
        (*des).histogramme[tempo[cptemp]]++;
    }
    free(tempo);
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

void indexer_image(char* nom){

    // Declaration varibales
    int longueur , hauteur, d;
    Descripteur descripteur;
    FILE* fichier = NULL;

    //Récupération de la valeur n du .config

    // Ouverture de l'image

    // Récupération des données image
    scanf("%d", &longueur);
    scanf("%d", &hauteur);
    scanf("%d", &d);

    // Initialisation en fonction du fichier
    descripteur = initDescripteur(d);
    descripteur.ID = 234;

    switch(d){
        case 1 : // Quantification NB
            quantificationNB(&descripteur,longueur,hauteur);

            break;
        case 3 : // Quantification RGB
            quantificationRGB(longueur,hauteur,&descripteur);
            break;
        default : printf("Format de l'image pas supporté\n");
        exit(0);
    }

    // Ecriture du descripteur dans la pile
    fichier = fopen("/Database/Descripteur/dI.txt","w");
    if (fichier != NULL)
    {
        fprintf(fichier, "{%d,%d,",descripteur.ID,descripteur.t_max);
        for(int i = 0; i<descripteur.t_max; i++){
            fprintf(fichier, "%d ",descripteur.histogramme[i]);
        }
        fprintf(fichier, "}\n");
        fclose(fichier);
    }
    else printf("echec");
}