#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/indexation.h"
#include "../include/indexation_txt.h"
#include "../include/pile_Texte.h"
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

// =============================================================================================

void changerExtension(char* extensionActuelle, char* nouvelleExtension){
    for (int i = 0 ; i < strlen(nouvelleExtension) ; i++){
        extensionActuelle[i]= *(nouvelleExtension+i);
    }
}

//Permet de savoir de quel type est le fichier dont le nom est passe en parametre
int getTypeDuFichierEtChangeLextension(char* nom_fichier_cible){
    char* ptr_debutExtension = strrchr(nom_fichier_cible,'.');
    if (ptr_debutExtension == NULL) return 0;
    int type = 0;
    if (!strcmp(ptr_debutExtension,".xml")){
        type = 1;
    } else if (!strcmp(ptr_debutExtension,".jpg")){
        type = 2;
        changerExtension(ptr_debutExtension,".txt");
    } else if (!strcmp(ptr_debutExtension,".wav")){
        type = 3;
        changerExtension(ptr_debutExtension,".bin");
    } else if (!strcmp(ptr_debutExtension,".bmp")){
        type = 4;
        changerExtension(ptr_debutExtension,".txt");
    }

    return type;
}

int getTypeDuFichier(char* nom_fichier_cible){
    char* ptr_debutExtension = strrchr(nom_fichier_cible,'.');    
    if (ptr_debutExtension == NULL) return 0;

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
    strcat(commande, " | grep \" ");
    strcat(commande, nom_fic);
    strcat(commande, "$\" >fic_temp2 ");

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
        changerExtension(extension,".wav");
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


// -=========================================================================================================================

//Lance une recherche via l'adresse d'un fichier
int lanceRechercheViaAdresse(char* adresse_fichier_cible, char* chaine_resultat){
    char commande[300];
    char cheminBase[100];
    char sauvExtension[5];
    int type = 0;

    char* ptr_debutExtension = strrchr(adresse_fichier_cible,'.');
    char* ptr_debutNom = strrchr(adresse_fichier_cible, '/');

    if (ptr_debutExtension == NULL || ptr_debutNom == NULL){
        strcpy(chaine_resultat, "ERREUR : Saisie invalide\n");
        return 1;
    }

    if (!strcmp(ptr_debutExtension,".xml")){
        type = 1;
        strcpy(cheminBase, "./Database/Texte");
    } else if (!strcmp(ptr_debutExtension,".jpg")){
        type = 2;
        strcpy(cheminBase, "./Database/Image/RGB");
        changerExtension(sauvExtension,".jpg");
    } else if (!strcmp(ptr_debutExtension,".wav")){
        type = 3;
        strcpy(cheminBase, "./Database/Audio");
        changerExtension(sauvExtension,".wav");
    } else if (!strcmp(ptr_debutExtension,".bmp")){
        type = 2;
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

    if (type != 1){

        if (type == 2) changerExtension(ptr_debutExtension,".txt");
        else changerExtension(ptr_debutExtension,".bin");

        strcpy(commande, "mv ");
        strcat(commande, adresse_fichier_cible);
        strcat(commande, " ");
        strcat(commande, cheminBase);

        fflush(stdout);
        system(commande); 

        changerExtension(ptr_debutExtension, sauvExtension);
    }
    

    lanceRechercheViaNom(ptr_debutNom+1,chaine_resultat);

    return 0;
}


//Fonction d'appel de la recherche Par nom. Fonction Principale
int lanceRechercheViaNom(char* nom_fichier_cible,char* chaine_resultat){

    int t = getTypeDuFichierEtChangeLextension(nom_fichier_cible);

    strcpy(chaine_resultat,"La recherche n'a donne aucun resultat");

    if (t == 1){

        DESCRIPTEUR_TEXTE descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            Indexation();
        }

        descFic = getDescripteurTexteViaPile(nom_fichier_cible);

        if (descFic.ID == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECHERCHE N'A PU ABOUTIR\nVERIFIEZ QUE LE PROGRAMME DISPOSE DE L'ENSEMBLE DES DROITS AUX FICHIERS NECESSAIRES\n");
            return 2;
        }
    
        PILE_DESCRIPTEUR_TEXTE pileSim = rechercheTexteParDescripteur(&descFic);

        if (pileSim != NULL){
            generationChaineCaracViaPileTexte(pileSim, &descFic,chaine_resultat);
        }

    } else if (t == 2 || t == 4){

        DESCRIPTEUR_IMAGE descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            Indexation();
        }


        descFic = getDescripteurImageViaPile(nom_fichier_cible);

        if (descFic.ID == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECHERCHE N'A PU ABOUTIR\nVERIFIEZ QUE LE PROGRAMME DISPOSE DE L'ENSEMBLE DES DROITS AUX FICHIERS NECESSAIRES\n");
            return 2;
        }

        PILE_DESCRIPTEUR_IMAGE pileSim = rechercheImageParDescripteur(&descFic);

        if (pileSim != NULL){
            generationChaineCaracViaPileIMAGE(pileSim, &descFic,chaine_resultat,t);
        }

    } else if (t == 3 ){

        DESCRIPTEUR_AUDIO descFic;

        if (!VerificationTraitee(nom_fichier_cible)){
            Indexation();
        }

        descFic = getDescripteurAudioViaPile(nom_fichier_cible);


        if (descFic.identifiant == 0){
            strcpy(chaine_resultat,"ERREUR : LA RECHERCHE N'A PU ABOUTIR\nVERIFIEZ QUE LE PROGRAMME DISPOSE DE L'ENSEMBLE DES DROITS AUX FICHIERS NECESSAIRES\n");
            return 2;
        }

        rechercheJingle(&descFic, chaine_resultat);

    } else {
        strcpy(chaine_resultat, "Erreur de lecture du fichier :\nType non reconnu\n");
        return 1;
    }
    return 0;
}

int lanceRechercheViaMotCle(char* mot, char* chaine_resultat){
    char commande[100], numChar[5], nom[50], nomSauv[50];
    int numLigne=0, id, numMax=0, num;

    strcpy(commande, "grep ^");
    strcat(commande, mot);  
    strcat(commande,"$ ./Database/Descripteur/table_index_texte.txt -n > fic_temp");
    
    system(commande);

    FILE* fTit = fopen("./fic_temp","r");
    if (fTit == NULL){
        strcpy(chaine_resultat,"Votre recherche n'a pas aboutit");
        return 0;
    }
    
    fscanf(fTit,"%d",&numLigne);

    if (numLigne == 0){
        strcpy(chaine_resultat,"Votre recherche n'a donne aucun resultat\n");
        return 0;
    }

    fclose(fTit);

    numLigne++;

    sprintf(numChar,"%d",numLigne);


    strcpy(commande, "cat ./Database/Descripteur/table_index_texte.txt | head -");
    strcat(commande, numChar);
    strcat(commande, " | tail -1 > fic");

    system(commande);

    FILE* f = fopen("./fic","r");
    if (f == NULL){
        strcpy(chaine_resultat,"Votre recherche n'a pas aboutit");
        return 0;
    }

    strcpy(chaine_resultat,"Voici les resultats pour votre recherche [");
    strcat(chaine_resultat, mot);
    strcat(chaine_resultat, "]:\n");

    while (!feof(f)){
        fscanf(f,"%d %d ",&id,&num);
        sprintf(numChar,"%d",num);
        recupNomDUFic(id,1,nom);
        strcat(chaine_resultat, "-");
        strcat(chaine_resultat,nom);
        strcat(chaine_resultat, " : Apparait ");
        strcat(chaine_resultat,numChar);
        strcat(chaine_resultat, " fois\n");
        if (num > numMax){
            numMax = num;
            strcpy(nomSauv, nom);
        }
    }

    if (numMax > 0){
        if (!ouvertureFichier(nomSauv)){
            printf("Ouverture du fichier impossible. Verifier que xdg est correctement installe (sudo apt install xdg-utils)");
        }
    }

    return 0;

}


// ===============================================================================================

PILE_DESCRIPTEUR_IMAGE rechercheImageParDescripteur(DESCRIPTEUR_IMAGE* ptr_descFic){
    PILE_DESCRIPTEUR_IMAGE pile = Charger_Pile_DescripteurImg(init_PILE_Img());
    PILE_DESCRIPTEUR_IMAGE pileSim = init_PILE_Img();

    int tauwSim = recupTauxSimmilaritudeDuConfig(), tauxAct, tauxMax=0;

    if (pile == NULL){
        printf("ERREUR : ECHEC CHARGEMENT DE LA PILE DES IMAGES\n");
        return pileSim;
    }

    DESCRIPTEUR_IMAGE sauvMax;
    sauvMax.ID = 0;
    CelluleI* sauv;

    while (pile != NULL){
        if (pile->Di.ID != ptr_descFic->ID){
            tauxAct = comparaisonFichiersImage(ptr_descFic,&(pile->Di));
            if (tauxAct >= tauwSim){
                if (tauxAct > tauxMax){
                    if (sauvMax.ID != 0) {
                        pileSim = emPILE_Img(pileSim , sauvMax);
                    }
                    sauvMax = pile->Di;
                    tauxMax = tauxAct;
                } else {
                    pileSim = emPILE_Img(pileSim , pile->Di);
                }
            }
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Img_Sans_Sauvegarde(sauv);   
    }
    if (sauvMax.ID != 0){
        pileSim = emPILE_Img(pileSim , sauvMax);
    }
    return pileSim;
}

PILE_DESCRIPTEUR_TEXTE rechercheTexteParDescripteur(DESCRIPTEUR_TEXTE* ptr_descFic){
    PILE_DESCRIPTEUR_TEXTE pile = Charger_Pile_DescripteurTexte(init_PILE_Texte());
    PILE_DESCRIPTEUR_TEXTE pileSim = init_PILE_Texte();
    int tauwSim = recupTauxSimmilaritudeDuConfig(), tauxAct;

    if (pile == NULL){
        printf("ERREUR : ECHEC CHARGEMENT DE LA PILE DES IMAGES\n");
        return pileSim;
    }

    CelluleT* sauv;

    while (pile != NULL){
        if (pile->Dt.ID != ptr_descFic->ID){
            tauxAct = comparaisonFichiersTexte(ptr_descFic,&(pile->Dt));
            if (tauxAct >= tauwSim){
                pileSim = emPILE_Texte(pileSim, pile->Dt);
            }
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Texte_Sans_Sauvegarde(sauv);
    }
    
    return pileSim;
}


int generationChaineCaracViaPileIMAGE(PILE_DESCRIPTEUR_IMAGE pile, DESCRIPTEUR_IMAGE* ptr_descFic,char* chaine, int type){
    char chaine_nom[50], chaine_nomSauv[50];

    recupNomDUFic(ptr_descFic->ID,type,chaine_nom);

    strcpy(chaine,"Voici les resultats suite a votre recherche : [");
    strcat(chaine, chaine_nom);
    strcat(chaine,"]\n");

    CelluleI* sauv;

    if (pile == NULL) return 1;

    recupNomDUFic(pile->Di.ID,type,chaine_nom);
    strcpy(chaine_nomSauv,chaine_nom);

    while (pile != NULL){
        strcat(chaine,"- ");
        strcat(chaine,chaine_nom);
        strcat(chaine,"\n");
        sauv = pile;
        pile = pile->next;
        dePILE_Img_Sans_Sauvegarde(sauv);
        if (pile == NULL) continue;;
        recupNomDUFic(pile->Di.ID,type,chaine_nom);
    }

    if (!ouvertureFichier(chaine_nomSauv)){
        printf("Ouverture du fichier impossible. Verifier que xdg est correctement installe (sudo apt install xdg-utils)");
    }

    return 0;
}

int generationChaineCaracViaPileTexte(PILE_DESCRIPTEUR_TEXTE pile, DESCRIPTEUR_TEXTE* ptr_descFic,char* chaine){
    char chaine_nom[50], chaine_occ[3], chaine_nomSauv[50];
    int nbOcc, occMax = 0;

    recupNomDUFic(ptr_descFic->ID,1,chaine_nom);

    strcpy(chaine,"Voici les resultats suite a votre recherche : [");
    strcat(chaine, chaine_nom);
    strcat(chaine,"]\n");

    CelluleT* sauv;

    while (pile != NULL){
        recupNomDUFic(pile->Dt.ID,1,chaine_nom);
        strcat(chaine,"- ");
        strcat(chaine,chaine_nom);
        strcat(chaine, " : mots cle en commun : ");
        nbOcc = nbMotCmmunFichierTexte(ptr_descFic, &(pile->Dt));
        sprintf(chaine_occ,"%d",nbOcc);
        strcat(chaine, chaine_occ);
        strcat(chaine,"\n");

        if (nbOcc > occMax){
            occMax = nbOcc;
            strcpy(chaine_nomSauv,chaine_nom);
        }

        sauv = pile;
        pile = pile->next;
        dePILE_Texte_Sans_Sauvegarde(sauv);
    }
    if ((occMax > 0)){
        if (!ouvertureFichier(chaine_nomSauv)){
        printf("Ouverture du fichier impossible. Verifier que xdg est correctement installe (sudo apt install xdg-utils)");
    }
    }
   

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

    CelluleI* c = NULL;
    CelluleI* sauv;
    DESCRIPTEUR_IMAGE d;

    while (pile != NULL){
        if (pile->Di.ID == idFic){
            c = pile;
            pile = pile->next;
            if (pile == NULL) break;
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Img_Sans_Sauvegarde(sauv);
    }

    if (c == NULL){
        DESCRIPTEUR_IMAGE* d = (DESCRIPTEUR_IMAGE*) malloc(sizeof(DESCRIPTEUR_IMAGE));
        d->ID = 0;
        return *d;
    }

    d = c->Di;
    return d;
}

DESCRIPTEUR_AUDIO getDescripteurAudioViaPile(char* nom_fichier){

    PILE_Audio pile = Charger_Pile_DescripteurAudio(init_PILE_Audio());
    if (pile == NULL){
        DESCRIPTEUR_AUDIO* d = (DESCRIPTEUR_AUDIO*) malloc(sizeof(DESCRIPTEUR_AUDIO));
        d->identifiant = 0;
        return *d;
    }

    int idFic = recupIdDuFic(nom_fichier, 3);

    Cellule* c = NULL;
    Cellule* sauv;
    DESCRIPTEUR_AUDIO d;

    while (pile != NULL){
        if (pile->Da->identifiant == idFic){
            c = pile;
            pile = pile->next;
            if (pile == NULL) break;
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Audio_Sans_Sauvegarde(sauv);
    }


    if (c == NULL){
        DESCRIPTEUR_AUDIO* d = (DESCRIPTEUR_AUDIO*) malloc(sizeof(DESCRIPTEUR_AUDIO));
        d->identifiant = 0;
        return *d;
    }

    d = *(c->Da);

    return d;
}

DESCRIPTEUR_TEXTE getDescripteurTexteViaPile(char* nom_fichier){

    PILE_Texte pile = Charger_Pile_DescripteurTexte(init_PILE_Texte());
    if (pile == NULL){
        DESCRIPTEUR_TEXTE* d = (DESCRIPTEUR_TEXTE*) malloc(sizeof(DESCRIPTEUR_TEXTE));
        d->ID = 0;
        return *d;
    }

    int idFic = recupIdDuFic(nom_fichier, 1);

    CelluleT* c = NULL;
    CelluleT* sauv;
    DESCRIPTEUR_TEXTE d;

    while (pile != NULL){
        if (pile->Dt.ID == idFic){
            c = pile;
            pile = pile->next;
            if (pile == NULL) break;
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Texte_Sans_Sauvegarde(sauv);
    }

    if (c == NULL){
        DESCRIPTEUR_TEXTE* d = (DESCRIPTEUR_TEXTE*) malloc(sizeof(DESCRIPTEUR_TEXTE));
        d->ID = 0;
        return *d;
    }

    d = c->Dt;
    return d;
}

// -----------------------------------------------------------------------------------------

int rechercheJingle(DESCRIPTEUR_AUDIO* descFic, char* chaine_resultat){
    char chaine_nom[50], chaine_nomSauv[50];
    int pres, presMax=0;

    recupNomDUFic(descFic->identifiant,3,chaine_nom);
    strcpy(chaine_resultat,"Voici les resultats suite a votre recherche : [");
    strcat(chaine_resultat, chaine_nom);
    strcat(chaine_resultat,"]\n");

    PILE_DESCRIPTEUR_AUDIO pile = Charger_Pile_DescripteurAudio(init_PILE_Audio());
    if (pile == NULL){
        strcpy(chaine_resultat, "ERREUR : chargement de la PILE impossible");
        return 1;
    }

    Cellule* sauv;

    while (pile != NULL){
        if (pile->Da->identifiant != descFic->identifiant) {
            recupNomDUFic(pile->Da->identifiant,3,chaine_nom);
            strcat(chaine_resultat, chaine_nom);
            strcat(chaine_resultat, " : ");
            pres = comparaisonFichiersAudio(descFic,pile->Da,chaine_resultat);
            if (pres > presMax){
                presMax = pres;
                strcpy(chaine_nomSauv, chaine_nom);
            }
            strcat(chaine_resultat,"\n");
        }
        sauv = pile;
        pile = pile->next;
        dePILE_Audio_Sans_Sauvegarde(sauv);
    } 
    if (presMax > 0){
        if (!ouvertureFichier(chaine_nomSauv)){
            printf("Ouverture du fichier impossible. Verifier que xdg est correctement installe (sudo apt install xdg-utils)");
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------

int ouvertureFichier(char* nom){
    char commande[150];

    char CHEMIN[100];

    switch(getTypeDuFichier(nom)){
        case 1:
            strcpy(CHEMIN,"./Database/Texte/");
            break;
        case 2:
            strcpy(CHEMIN,"./Database/Image/RGB/");
            break;
        case 3:
            strcpy(CHEMIN,"./Database/Audio/");
            break;
        case 4:
            strcpy(CHEMIN,"./Database/Image/NB/");
            break;
        default:
            return 1;
    }

    strcpy(commande,"xdg-open ");
    strcat(commande, CHEMIN);
    strcat(commande, nom);
    strcat(commande, " 2>fic");

    system(commande);

    system("rm fic");

    return 1;
}