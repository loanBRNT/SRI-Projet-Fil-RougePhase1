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

    if (!strcmp(extension,"xml")){
        return 1;
    } else if (!strcmp(extension,"jpg")){
        return 2;
    } else if (!strcmp(extension,"wav")){
        return 3;
    }
    return 0;
}



//Fonction d'appel de la recherche Par nom. Fonction Principale
char* lanceRechercheViaNom(char* nom_fichier_cible){
    int t = getTypeDuFichier(nom_fichier_cible);
    switch(t){
        case 1:
            printf("Le fichier est un fichier Texte\n");
            break;
        case 2:
            printf("Le fichier est un fichier Image\n");
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

