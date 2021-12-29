#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/recherche.h"

/* 
 ----------------------- Signature -------------------------
|															|
|		Auteur : BERNAT Loan								|
|		Date de creation : 07/12/21							|
|		Date de derniere MAJ : xx/01/22						|
|															|
 ----------------------------------------------------------- 
 */
void changerExtension(char* nom_fic, int rangP){
    nom_fic[rangP+1]='t';
    nom_fic[rangP+2]='x';
    nom_fic[rangP+3]='t';
}

//Permet de savoir de quel type est le fichier dont le nom est passe en parametre
int getTypeDuFichier(char* nom_fichier_cible){
    char caractere ='a';
    int rangDebutExtension=0, tailleFic = 0;

    while (caractere != '\0'){
        caractere = nom_fichier_cible[tailleFic];
        if (caractere == '.') rangDebutExtension = tailleFic;
        tailleFic++;
    }
    tailleFic--;

    if (tailleFic - rangDebutExtension != 4) return 0;

    char extension[4];
    for (int i = 1; i < 4; ++i)
    {
        extension[i-1] = nom_fichier_cible[rangDebutExtension+i];
    }
    extension[3] = '\0';

    changerExtension(nom_fichier_cible,rangDebutExtension);

    if (!strcmp(extension,"xml")){
        return 1;
    } else if (!strcmp(extension,"jpg")){
        return 2;
    } else if (!strcmp(extension,"wav")){
        return 3;
    } else if (!strcmp(extension,"bmp")){
        return 4;
    }
    return 0;
}

DESCRIPTEUR_IMAGE getDescripteurImageViaPile(){

}



//Fonction d'appel de la recherche Par nom. Fonction Principale
char* lanceRechercheViaNom(char* nom_fichier_cible){
    int t = getTypeDuFichier(nom_fichier_cible);
    char chemin_indexation[100];
    switch(t){
        case 1:
            printf("Le fichier est un fichier Texte\n");
            break;
        case 2:
            printf("Le fichier est un fichier Image Couleur\n");
            if (!VerificationTraitee(nom_fichier_cible)){
                strcpy(CHEMIN_INDEXATION,"../Database/Image/RGB/");
                strcat(CHEMIN_INDEXATION,nom_fic);
                DESCRIPTEUR_IMAGE descFic = indexer_image("../Database/Image/RGB/",recupNbBitsDuConfig()); //changer le premier param pr trouver le fichier
            } else {
                DESCRIPTEUR_IMAGE descFic = getDescripteurImageViaPile();
            }
            break;
        case 4:
            printf("Le fichier est un fichier Image Couleur\n");
            if (!VerificationTraitee(nom_fichier_cible)){
                strcpy(CHEMIN_INDEXATION,"../Database/Image/NB/");
                strcat(CHEMIN_INDEXATION,nom_fic);
                DESCRIPTEUR_IMAGE descFic = indexer_image("../Database/Image/NB/",recupNbBitsDuConfig()); 
            } else {
                DESCRIPTEUR_IMAGE descFic = getDescripteurImageViaPile();
            }
            break;
        case 3:
            printf("Le fichier est un fichier Audio\n");
            break;
        default:
            return("Erreur de lecture du fichier :\nType non reconnu\n");
            break;
    }
    return "";
}



/*

Deplacer le fichier qui sera déposé dans la requete








*/