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
void changerExtension(char* extensionActuelle, char* nouvelleExtension){
    for (int i = 0 ; i < strlen(nouvelleExtension) ; i++){
        extensionActuelle[i]= *(nouvelleExtension+i);
    }
}

//Permet de savoir de quel type est le fichier dont le nom est passe en parametre
int getTypeDuFichierEtChangeLextension(char* nom_fichier_cible){
    char* ptr_debutExtension = strrchr(nom_fichier_cible,'.');
    int type = 0;

    if (!strcmp(ptr_debutExtension,".xml")){
        type = 1;
    } else if (!strcmp(ptr_debutExtension,".jpg")){
        type = 2;
    } else if (!strcmp(ptr_debutExtension,".wav")){
        type = 3;
    } else if (!strcmp(ptr_debutExtension,".bmp")){
        type = 4;
    }

    changerExtension(ptr_debutExtension,".txt");

    return type;
}

int getTypeDuFichier(char* nom_fichier_cible){
    char* ptr_debutExtension = strrchr(nom_fichier_cible,'.');    

    if (!strcmp(ptr_debutExtension,".xml")){
        return 1;
    } else if (!strcmp(ptr_debutExtension,".jpg")){
        return 2;
    } else if (!strcmp(ptr_debutExtension,".wav")){
        return 3;
    } else if (!strcmp(ptr_debutExtension,".bmp")){
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
    } else if (type == 1){
        strcat(chemin, "/liste_base_texte.txt");
    }  else {
        strcat(chemin, "/liste_base_audio.txt");
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
    char extension[5];
    FILE* ptr_fic;

    sprintf(id_fic,"%d",id);

    strcpy(chemin,"./Database/Descripteur");
    if (type == 2 || type == 4){
        strcat(chemin, "/liste_base_image.txt");
        if (type == 4){
            changerExtension(extension,".bmp");
        } else {
            changerExtension(extension,".jpg");
        }  
    } else if (type == 1){
        strcat(chemin, "/liste_base_texte.txt");
        changerExtension(extension,".xml");
    }  else {
        strcat(chemin, "/liste_base_audio.txt");
        changerExtension(extension,".bin");
    }
    extension[4] = '\0';

    strcpy(commande, "cat ");
    strcat(commande, chemin);
    strcat(commande, " | grep ");
    strcat(commande, id_fic);
    strcat(commande, "| cut -f 2 -d \" \"");
    strcat(commande, " > fic_temp2 ");

    fflush(stdout);
    system(commande);

    ptr_fic = fopen("fic_temp2", "r");

    fscanf(ptr_fic,"%s",nom);

    changerExtension(strrchr(nom,'.'),extension);

    fclose(ptr_fic);
}


// ------------------------------------------------------------------------------------------------------------------------

//Lance une recherche via l'adresse d'un fichier
int lanceRechercheViaAdresse(char* adresse_fichier_cible, char* chaine_resultat){
    char commande[300];
    char cheminBase[100];
    char sauvExtension[5];

    char* ptr_debutExtension = strrchr(adresse_fichier_cible,'.');
    char* ptr_debutNom = strrchr(adresse_fichier_cible, '/');

    if (!strcmp(ptr_debutExtension,".xml")){
        strcpy(cheminBase, "./Database/Texte");
        changerExtension(sauvExtension,".xml");
    } else if (!strcmp(ptr_debutExtension,".jpg")){
        strcpy(cheminBase, "./Database/Image/RGB");
        changerExtension(sauvExtension,".jpg");
    } else if (!strcmp(ptr_debutExtension,".bin")){
        strcpy(cheminBase, "./Database/Audio");
        changerExtension(sauvExtension,".bin");
    } else if (!strcmp(ptr_debutExtension,".bmp")){
        strcpy(cheminBase, "./Database/Image/NB");
        changerExtension(sauvExtension,".bmp");
    } else {
        strcpy(chaine_resultat, "ERREUR : TYPE INCONNU\n");
        return 1;
    }

    strcpy(commande, "mv ");
    strcat(commande, adresse_fichier_cible);
    strcat(commande, " ");
    strcat(commande, cheminBase);

    fflush(stdout);
    system(commande);
 
    changerExtension(ptr_debutExtension,".txt");
    
    strcpy(commande, "mv ");
    strcat(commande, adresse_fichier_cible);
    strcat(commande, " ");
    strcat(commande, cheminBase);

    fflush(stdout);
    system(commande);

    changerExtension(ptr_debutExtension, sauvExtension);

    lanceRechercheViaNom(ptr_debutNom+1,chaine_resultat);

    return 0;
}


//Fonction d'appel de la recherche Par nom. Fonction Principale
int lanceRechercheViaNom(char* nom_fichier_cible,char* chaine_resultat){

    int t = getTypeDuFichierEtChangeLextension(nom_fichier_cible);

    if (t == 1){
         printf("Le fichier est un fichier Texte\n");
    } else if (t == 2 || t == 4){

        DESCRIPTEUR_IMAGE descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            Indexation();
        }

        descFic = getDescripteurImageViaPile(nom_fichier_cible);


        if (descFic.ID == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECHERCHE N'A PU ABOUTIR\nVERIFIEZ QUE LE PROGRAMME DISPOSE DE L4ENSEMBLE DES DROITS AUX FICHIERS NECESSAIRES\n");
            return 2;
        }

        PILE_DESCRIPTEUR_IMAGE pileSim = rechercheImageParDescripteur(&descFic);

        if (pileSim != NULL){
            generationChaineCaracViaPileIMAGE(pileSim, &descFic,chaine_resultat,t);
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
            //printf("%d sim à %d%\n",ptr_Cel->Di.ID,tauxAct);
            if (tauxAct >= tauwSim){
                pileSim = emPILE_Img(pileSim , ptr_Cel->Di);
            }
        }
        ptr_Cel = ptr_Cel->next;
    }
    dePILE_Img_Sans_Sauvegarde(pile);
    return pileSim;
}


int generationChaineCaracViaPileIMAGE(PILE_DESCRIPTEUR_IMAGE pile, DESCRIPTEUR_IMAGE* ptr_descFic,char* chaine, int type){
    char chaine_nom[50];
    PILE_DESCRIPTEUR_IMAGE ptr_cell = pile;

    recupNomDUFic(ptr_descFic->ID,type,chaine_nom);

    strcpy(chaine,"Voici les resultats suite a votre recherche : [");
    strcat(chaine, chaine_nom);
    strcat(chaine,"]\n");


    while (ptr_cell != NULL){
        recupNomDUFic(ptr_cell->Di.ID,type,chaine_nom);
        strcat(chaine,"- ");
        strcat(chaine,chaine_nom);
        strcat(chaine, "\n");
        ptr_cell = ptr_cell->next;
    }

    dePILE_Img_Sans_Sauvegarde(pile);
    return 0;
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
    DESCRIPTEUR_IMAGE d;

    while (c->Di.ID != idFic){
        c = c->next;
        if (c == NULL){
            break;
        }
    }
    if (c == NULL){
        DESCRIPTEUR_IMAGE* d = (DESCRIPTEUR_IMAGE*) malloc(sizeof(DESCRIPTEUR_IMAGE));
        d->ID = 0;
        return *d;
    }

    d = c->Di;
    dePILE_Img_Sans_Sauvegarde(pile);
    return d;
}