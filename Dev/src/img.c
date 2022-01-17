#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../include/img.h"

Descripteur initDescripteur(int nb_composantes, int n){
    Descripteur descri;
    descri.t_max =pow(2,(n*nb_composantes));
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

int generationIdUnique(int choix){
    char* CHEMIN_LISTE;
    char buffer[15];
    int random,res;
    char* commande;
    switch (choix){
        //TEXTE
        case 1 :
            CHEMIN_LISTE = "./Database/Descripteur/liste_base_texte.txt";
            break;
        //IMAGE
        case 2 :
            CHEMIN_LISTE = "./Database/Descripteur/liste_base_image.txt";
            break;
        //AUDIO
        case 3 :
            CHEMIN_LISTE = "./Database/Descripteur/liste_base_audio.txt";
            break;
        default :
            printf("Erreur sur la valeur du paramètre pour la génération de l'ID unique");
    }
    //srand(time(NULL));
    do{
        commande = malloc(1000*sizeof(char));
        random = rand()%(30000-20000)+20000;
        strcat(commande, "grep -c ^");
        sprintf(buffer, "%d", random);
        strcat(commande, buffer);
        strcat(commande, " ");
        strcat(commande, CHEMIN_LISTE);
        //system(commande); // commande execute dans popen donc ici uniquement pour verifier valeur de retour de la commande
        FILE * f = popen(commande, "r");
        fscanf(f,"%d",&res);
        pclose(f);
        free(commande);
    } while(res==1);
    return random;
}

void Affiche_DescripteurImg(Descripteur Di){
    printf("%d\n",Di.ID);
    printf("%d\n",Di.t_max);
    for(int i=0;i<Di.t_max;i++){
        printf("%d\n",Di.histogramme[i]);
    }
    printf("\n");

};

Descripteur indexer_image(char* nom, int n){

    // Declaration varibales
    int longueur , hauteur, d;
    Descripteur descripteur;
    FILE* fichier = NULL;
    FILE* liste = NULL;
    char* CHEMIN_LISTE = "./Database/Descripteur/liste_base_image.txt";


    // Ouverture de l'image
    fichier = fopen(nom,"r");

    if (fichier != NULL) {

        // Récupération des données image
        fscanf(fichier,"%d %d %d", &longueur, &hauteur, &d);
        // Initialisation en fonction du fichier
        descripteur = initDescripteur(d,n);
         // Ouverture de la liste descripteur
        liste = fopen(CHEMIN_LISTE,"r+"); // A mettre en mode r/w

        if(liste != NULL){

            descripteur.ID = generationIdUnique(2);

            switch(d){
                case 1 : // Quantification NB
                    quantificationNB(&descripteur,longueur,hauteur,fichier,n);
                    break;
                case 3 : // Quantification RGB
                    quantificationRGB(longueur,hauteur,&descripteur,fichier,n);
                    break;
                default : 
                    printf("Format de l'image pas supporté\n");
                    break;
            }
            fclose(fichier);
        }
        else
            printf("Echec de l'ouverture de la liste des descripteurs");
        fclose(liste);
    }
    else
        printf("Echec de l'ouverture de l'image à indexer");

    return descripteur;
}


void Sauvegarder_DescripteurImage(Descripteur Di,FILE* f){
    fprintf(f,"%d\n",Di.ID);
    fprintf(f,"%d\n",Di.t_max);
    for(int i=0;i<Di.t_max;i++){
        fprintf(f,"%d\n",Di.histogramme[i]);
    }
    fprintf(f,"\n");
};


Descripteur LireDescripteurImg(FILE* f, int taille, int id){
    char *lu =(char *) malloc(10*sizeof(char));
    int valeur;
    int nb_composantes = log2(taille);
    
    //Descripteur DI=initDescripteur(nb_composantes, bitQ);
    Descripteur DI;
    DI.t_max =taille;
    DI.histogramme = NULL;
    DI.histogramme = malloc(DI.t_max*sizeof(int));
    DI.ID=id;
            for(int i=0;i<taille;i++){
                fscanf(f,"%s",lu);
                valeur=atoi(lu);
                DI.histogramme[i]=valeur;
            }
    return DI;

};