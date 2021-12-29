#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/indexation.h"
#include "../include/img.h"
#include "../include/pile_Img.h"
#include "../include/descripteurAudio.h"
#include "../include/admin.h"
#include "../include/recherche.h"
#include "../include/comparaison.h"

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

int recupIdDuFic(char* nom_fic, int type){
    char chemin[100];
    char commande[150];
    int id;
    FILE* ptr_fic;

    strcpy(chemin,"./Database/Descripteur");
    if (type == 2){
        strcat(chemin, "/liste_base_image.txt");
    } else {
        printf("ERREUR : TYPE INCONNU");
        return 0;
    }
    strcpy(commande, "cat ");
    strcat(commande, chemin);
    strcat(commande, " | grep ");
    strcat(commande, nom_fic);
    strcat(commande, " >fic_temp2 ");
    printf("execution de %s\n", commande);
    fflush(stdout);
    system(commande);

    ptr_fic = fopen("fic_temp2", "r");

    fscanf(ptr_fic, "%d", &id);

    fclose(ptr_fic);

    return id;    
}

DESCRIPTEUR_IMAGE getDescripteurImageViaPile(char* nom_fichier){
    PILE_Img pile = Charger_Pile_DescripteurImg(init_PILE_Img());
    int idFic = recupIdDuFic(nom_fichier, 2);
    printf("%d\n",idFic);
    DESCRIPTEUR_IMAGE* d = (DESCRIPTEUR_IMAGE*) malloc(sizeof(DESCRIPTEUR_IMAGE));
    return *d;
}



//Fonction d'appel de la recherche Par nom. Fonction Principale
char* lanceRechercheViaNom(char* nom_fichier_cible){
    int t = getTypeDuFichier(nom_fichier_cible);
    char CHEMIN_INDEXATION[100];
    switch(t){
        case 1:
            printf("Le fichier est un fichier Texte\n");
            break;
        case 2:
            printf("Le fichier est un fichier Image Couleur\n");
            if (!VerificationTraitee(nom_fichier_cible)){
                strcpy(CHEMIN_INDEXATION,"../Database/Image/RGB/");
                strcat(CHEMIN_INDEXATION,nom_fichier_cible);
                printf("On lance l'indexation de %s\n",CHEMIN_INDEXATION);
                //DESCRIPTEUR_IMAGE descFic = indexer_image("CHEMIN_INDEXATION",recupNbBitsDuConfig()); //changer le premier param pr trouver le fichier
            } else {
                //DESCRIPTEUR_IMAGE descFic = NULL;
            }
            break;
        case 4:
            printf("Le fichier est un fichier Image Noir & Blanc\n");
            if (!VerificationTraitee(nom_fichier_cible)){
                strcpy(CHEMIN_INDEXATION,"../Database/Image/NB/");
                strcat(CHEMIN_INDEXATION,nom_fichier_cible);
                printf("On lance l'indexation de %s\n",CHEMIN_INDEXATION);
                //DESCRIPTEUR_IMAGE descFic = indexer_image(".CHEMIN_INDEXATION",recupNbBitsDuConfig()); 
            } else {
                printf("ON A RECUP LE DESCRIP\n");
                DESCRIPTEUR_IMAGE descFic = getDescripteurImageViaPile(nom_fichier_cible);
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