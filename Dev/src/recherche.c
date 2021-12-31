#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/indexation.h"
#include "../include/img.h"
#include "../include/pile_Img.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"
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

    fflush(stdout);
    system(commande);

    ptr_fic = fopen("fic_temp2", "r");

    fscanf(ptr_fic, "%d", &id);

    fclose(ptr_fic);

    return id;    
}

void recupNomDUFic(int id, int type,char* nom){
    char chemin[100];
    char commande[150];
    char id_fic[10];
    FILE* ptr_fic;

    sprintf(id_fic,"%d",id);

    strcpy(chemin,"./Database/Descripteur");
    if (type == 2){
        strcat(chemin, "/liste_base_image.txt");
    }

    strcpy(commande, "cat ");
    strcat(commande, chemin);
    strcat(commande, " | grep ");
    strcat(commande, id_fic);
    strcat(commande, "| cut -f 2 -d \" \"");
    strcat(commande, " > fic_temp2 ");

    fflush(stdout);
    system(commande);

    ptr_fic = fopen("fic_temp2", "r");

    fscanf(ptr_fic, "%s", nom);

    fclose(ptr_fic);
}

DESCRIPTEUR_IMAGE getDescripteurImageViaPile(char* nom_fichier){

    PILE_Img pile = Charger_Pile_DescripteurImg(init_PILE_Img());
    if (pile == NULL){
        DESCRIPTEUR_IMAGE* d = (DESCRIPTEUR_IMAGE*) malloc(sizeof(DESCRIPTEUR_IMAGE));
        d->ID = 0;
        return *d;
    }

    int idFic = recupIdDuFic(nom_fichier, 2);

    CelluleI* c = pile;
    while (c->Di.ID != idFic){
        c = c->next;
        if (c == NULL){
            break;
        }
    }
    DESCRIPTEUR_IMAGE d = c->Di;
    dePILE_Img_Sans_Sauvegarde(pile);
    return d;
}



//Fonction d'appel de la recherche Par nom. Fonction Principale
int lanceRechercheViaNom(char* nom_fichier_cible,char* chaine_resultat){

    int t = getTypeDuFichier(nom_fichier_cible);
    char CHEMIN_INDEXATION[100];

    if (t == 1){
         printf("Le fichier est un fichier Texte\n");
    } else if (t == 2){
        printf("Le fichier est un fichier Image Couleur\n");

        DESCRIPTEUR_IMAGE descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            strcpy(CHEMIN_INDEXATION,"../Database/Image/RGB/");
            strcat(CHEMIN_INDEXATION,nom_fichier_cible);
            printf("On lance l'indexation de %s\n",CHEMIN_INDEXATION);
            descFic = indexer_image(CHEMIN_INDEXATION,recupNbBitsDuConfig());
        } else {
            descFic = getDescripteurImageViaPile(nom_fichier_cible);
        }
        if (descFic.ID == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECUPERATION DU DESCRIPTEUR A ECHOUE");
            return 2;
        }

        PILE_DESCRIPTEUR_IMAGE pileSim = rechercheImageParDescripteur(&descFic);

        if (pileSim != NULL){
            generationChaineCaracViaPileIMAGE(pileSim, &descFic,chaine_resultat);
        }
    } else if (t == 4) {
        printf("Le fichier est un fichier Image Noir & Blanc\n");

        DESCRIPTEUR_IMAGE descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            strcpy(CHEMIN_INDEXATION,"../Database/Image/NB/");
            strcat(CHEMIN_INDEXATION,nom_fichier_cible);
            printf("On lance l'indexation de %s\n",CHEMIN_INDEXATION);
            descFic = indexer_image(CHEMIN_INDEXATION,recupNbBitsDuConfig()); 
        } else {
            descFic = getDescripteurImageViaPile(nom_fichier_cible);
        }

        if (descFic.ID == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECUPERATION DU DESCRIPTEUR A ECHOUE");
            return 2;
        }
        PILE_DESCRIPTEUR_IMAGE pileSim = rechercheImageParDescripteur(&descFic);

        if (pileSim != NULL){
            generationChaineCaracViaPileIMAGE(pileSim, &descFic,chaine_resultat);
        }
    } else if (t == 3 ){
        printf("Le fichier est un fichier Audio\n");
    } else {
        strcpy(chaine_resultat, "Erreur de lecture du fichier :\nType non reconnu\n");
        return 1;
    }
    return 0;
}



// ------------------------------------------------------------------------------------------------------------------------

PILE_DESCRIPTEUR_IMAGE rechercheImageParDescripteur(DESCRIPTEUR_IMAGE* ptr_descFic){
    PILE_DESCRIPTEUR_IMAGE pile = Charger_Pile_DescripteurImg(init_PILE_Img());
    PILE_DESCRIPTEUR_IMAGE pileSim = init_PILE_Img();
    int tauwSim = recupTauxSimmilaritudeDuConfig(), tauxAct;

    if (pile == NULL){
        printf("ERREUR : ECHEC CHARGEMENT DE LA PILE DES IMAGES\n");
        return pileSim;
    }

    CelluleI* ptr_Cel = pile;
    while (ptr_Cel != NULL){
        if (ptr_Cel->Di.ID != ptr_descFic->ID){
            tauxAct = comparaisonFichiersImage(ptr_descFic,&(ptr_Cel->Di));
            printf("%d sim à %d%\n",ptr_Cel->Di.ID,tauxAct);
            if (tauxAct >= tauwSim){
                pileSim = emPILE_Img(pileSim , ptr_Cel->Di);
            }
        }
        ptr_Cel = ptr_Cel->next;
    }
    dePILE_Img_Sans_Sauvegarde(pile);
    return pileSim;
}



int generationChaineCaracViaPileIMAGE(PILE_DESCRIPTEUR_IMAGE pile, DESCRIPTEUR_IMAGE* ptr_descFic,char* chaine){
    char chaine_nom[50];
    PILE_DESCRIPTEUR_IMAGE ptr_cell = pile;

    recupNomDUFic(ptr_descFic->ID,2,chaine_nom);

    strcpy(chaine,"Voici les resultats suite a votre recherche : [");
    strcat(chaine, chaine_nom);
    strcat(chaine,"]\n");

    while (ptr_cell != NULL){
        recupNomDUFic(ptr_cell->Di.ID,2,chaine_nom);
        strcat(chaine,"- ");
        strcat(chaine,chaine_nom);
        strcat(chaine, "\n");
        ptr_cell = ptr_cell->next;
    }

    dePILE_Img_Sans_Sauvegarde(pile);
    return 0;
}



/*

Deplacer le fichier qui sera déposé dans la requete








*/