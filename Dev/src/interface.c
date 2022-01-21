

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

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
#include "../include/interface.h"
#include "../include/pwd.h"


//########## FONCTIONS DE GESTION DES MENUS ###############

void afficheAccueil(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#            BIENVENUE DANS LA            #\n");
	printf("#                                         #\n");
	printf("#            DESQL CORPORATION            #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#                                         #\n");
	printf("#          ***************                #\n");
	printf("#          ****************               #\n");
	printf("#          ****          ***              #\n");
	printf("#          *** *        * ***             #\n");
	printf("#          ***  *      *   ***            #\n");
	printf("#          ***   *    *     ***           #\n");
	printf("#          ***    *  *       ***          #\n");
	printf("#          ***     **         ***         #\n");
	printf("#          ***     **         ***         #\n");
	printf("#          ***    *  *       ***          #\n");
	printf("#          ***   *    *     ***           #\n");
	printf("#          ***  *      *   ***            #\n");
	printf("#          *** *        * ***             #\n");
	printf("#          ****          ***              #\n");
	printf("#          ***************                #\n");
	printf("#          **************                 #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

//########## FONCTIONS D AFFICHAGE DES MENUS ##############
void afficheMenuPrincipal(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#            MENU PRINCIPAL               #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#            1:ADMINISTRATEUR             #\n");
	printf("#                                         #\n");
	printf("#            2:UTILISATEUR                #\n");
	printf("#                                         #\n");
	printf("#            3:QUITTER                    #\n");
	printf("#                                         #\n");
	printf("#       !! choisissez le Mode !!          #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void afficheMenuAdmin(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#  Bienvenue sur le MODE ADMINISTRATEUR   #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#         1: OUVRIR PANNEAU CONFIG        #\n");
	printf("#                                         #\n");
	printf("#         2: LANCER INDEXATION            #\n");
	printf("#                                         #\n");
	printf("#         3: RETOUR MENU PRINCIPAL        #\n");
	printf("#                                         #\n");
	printf("#         4: QUITTER                      #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void afficheMenuPointConfig(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#         PANNEAU DE CONFIGURATION        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        1: TAUX DE SIMILARITE            #\n");
	printf("#                                         #\n");
	printf("#        2: NB MOTS PAR TEXTE             #\n");
	printf("#                                         #\n");
	printf("#        3: SEUIL OCCURENCE MOTS          #\n");
	printf("#                                         #\n");
	printf("#        4: NB INTERVALLE                 #\n");
	printf("#                                         #\n");
	printf("#        5: NB POINTS PAR FENETRE         #\n");
	printf("#                                         #\n");
	printf("#        6: NB BITS DE QUANTIFICATION     #\n");
	printf("#                                         #\n");
	printf("#        7: AFFICHER VALEUR .CONFIG       #\n");
	printf("#                                         #\n");
	printf("#        8: RETOUR MENU ADMIN             #\n");
	printf("#                                         #\n");
	printf("#        9: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void afficheErreurMenu(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#  SAISIE INCORRECTE VEUILLEZ RÉESSAYER   #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void afficheMenuUtilisateur(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#    Bienvenue sur le MODE UTILISATEUR    #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("# << choisissez le type de recherche: >>  #\n");
	printf("#                                         #\n");
	printf("#        1: PAR MOT CLÉ                   #\n");
	printf("#                                         #\n");
	printf("#        2: PAR NOM                       #\n");
	printf("#                                         #\n");
	printf("#        3: PAR CHEMIN                    #\n");
	printf("#                                         #\n");
	printf("#        4: PAR SELECTION                 #\n");
	printf("#                                         #\n");
	printf("#        5: RETOUR MENU PRINCIPAL         #\n");
	printf("#                                         #\n");
	printf("#        6: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}



void afficheRechercheParMot(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#  Vous avez lance la RECHERCHE PAR MOT   #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#    Veuillez saisir le MOT CLE :         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}

void afficheRechercheParNom(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#  Vous avez lance la RECHERCHE PAR NOM   #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#    Veuillez saisir le nom du fichier :  #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}


void afficheRechercheChemin(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("# Vous avez lance la RECHERCHE PAR CHEMIN #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#    Veuillez saisir le chemin d'acces    #\n");
	printf("#               du fichier :              #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}


void afficheDataSelection(){
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#Vous avez lance la RECHERCHE PAR SELECTION#\n");
	printf("#                                          #\n");
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#    Veuillez choisir un fichier de la     #\n");
	printf("#                database :                #\n");
	printf("#                                          #\n");
	printf("###########################################\n");
}

void afficheRechercheSelection(){
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#Vous avez lance la RECHERCHE PAR SELECTION#\n");
	printf("#                                          #\n");
	printf("############################################\n");
	printf("#                                          #\n");
	printf("#    Veuillez choisir le type de fichier   #\n");
	printf("#                                          #\n");
	printf("#               1-TEXTE                    #\n");
	printf("#                                          #\n");
	printf("#               2-AUDIO                    #\n");
	printf("#                                          #\n");
	printf("#               3-IMAGE                    #\n");
	printf("#                                          #\n");
	printf("###########################################\n");
}

void affichageSaisieTauxSim(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#     MODIFIER LE TAUX DE SIMILARITE      #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupTauxSimmilaritudeDuConfig());
	printf("#                                         #\n");
	printf("#        DOIT ETRE COMPRIS ENTRE          #\n");
	printf("#                1 ET 100                 #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void affichageSaisieNbMot(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#     MODIFIER LE NB DE MOTS PAR TEXTE    #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupNbMotParTexteDuConfig());
	printf("#                                         #\n");
	printf("#        DOIT ETRE SUPERIEUR A            #\n");
	printf("#                 0                       #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void affichageSaisieOccurenceMot(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#     MODIFIER SEUIL OCCURENCE MOTS       #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupSeuilOccurenceMotDuConfig());
	printf("#                                         #\n");
	printf("#        DOIT ETRE SUPERIEUR A            #\n");
	printf("#                 0                       #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}
void affichageSaisieNbIntervalle(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        MODIFIER NB INTERVALLE           #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupNbIntervalleDuConfig());
	printf("#                                         #\n");
	printf("#        DOIT ETRE SUPERIEUR A            #\n");
	printf("#                 0                       #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}
void affichageSaisieNbPoint(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        MODIFIER NB POINTS               #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupNbPointsDuConfig());
	printf("#                                         #\n");
	printf("#                                         #\n");
	printf("#     DOIT ETRE UNE PUISSANCE DE 2        #\n");
	printf("#                                         #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void affichageSaisieNbBits(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#  MODIFIER LE NB BITS DE QUANTIFICATION  #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        VALEUR ACTUELLE : %d             #\n",recupNbBitsDuConfig());
	printf("#                                         #\n");
	printf("#        DOIT ETRE COMPRIS ENTRE          #\n");
	printf("#                1 ET 4                   #\n");
	printf("#                                         #\n");
	printf("#        << Saisissez un entier >>        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}


void afficheValeurConfig(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#         PANNEAU DE CONFIGURATION        #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        TAUX DE SIMILARITE: %d           #\n",recupTauxSimmilaritudeDuConfig());
	printf("#                                         #\n");
	printf("#        NB MOTS PAR TEXTE: %d            #\n",recupNbMotParTexteDuConfig());
	printf("#                                         #\n");
	printf("#        SEUIL OCCURENCE MOTS: %d         #\n",recupSeuilOccurenceMotDuConfig());
	printf("#                                         #\n");
	printf("#        NB INTERVALLE: %d                #\n",recupNbIntervalleDuConfig());
	printf("#                                         #\n");
	printf("#        NB POINTS PAR FENETRE: %d        #\n",recupNbPointsDuConfig());
	printf("#                                         #\n");
	printf("#        NB BITS DE QUANTIFICATION: %d    #\n",recupNbBitsDuConfig());
	printf("#                                         #\n");
	printf("###########################################\n");

}

//#################################################################################################################################


// ======================================================================================================
// ======================================================================================================

int menuAdminVerif(){
	int cpt = 1;
	int valeur=1;
	int choix = 1;
	while(cpt != (-1)) {
		printf("La verif du mot de passe se lance\n\n");
		//on informe l'utilisateur qui rentre sur un menu prive
        // on verifie la valeur de retour de verifierPwdAdmin pour savoir si l'utilisateur a saisi le bon mot de passe
        cpt = verifierPwdAdmin();
        // si le mot de passe est faux on demande a l'utilisateur si il veut reesayer la saisie car une erreur de frappe peut arriver
        if(cpt==1 && choix!=3)//si identifiant ou mdp mauvais alors retourne 1 sinon 0
        {
			if (choix == 2){
				printf("###########################################\n");
 				printf("#             !! ATTENTION !!             #\n");
  				printf("#                                         #\n");
  				printf("#          Il vous reste 1 essai          #\n");
 				printf("###########################################\n");
				printf("\n");
				choix = choix+1;
            	cpt=1; //on rerentre ds la boucle pour verif mdp
            	valeur=cpt;
			}
			else if (choix == 1){
				printf("###########################################\n");
 				printf("#             !! ATTENTION !!             #\n");
  				printf("#                                         #\n");
  				printf("#          Il vous reste 2 essai          #\n");
 				printf("###########################################\n");
				printf("\n");
				choix = choix+1;
            	cpt=1; //on rerentre ds la boucle pour verif mdp
            	valeur=cpt;
			}
			else{
				choix = choix+1;
            	cpt=1; //on rerentre ds la boucle pour verif mdp
            	valeur=cpt;
			}
		}

            /*
            Il faut coder la vérification du mot de passe à partir de mdp/admin.txt
            */
        else if (choix == 3){
        	afficheErreurMenu();
        	cpt =-1;
        	valeur=cpt;
        }
        else {
            cpt=-1;
            valeur=menuAdmin();
            }
    }
    return valeur;
}

int menuAdmin(){
	int event = 1 ;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheMenuAdmin();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				if (menuPointConfig() == 0){
					event = 0; //si la valeur de retour du menu suivant est 0 alors on doit quitter
				}
				break;
			case 2:
				printf("indexation en cours ...");
				Indexation();
				break;
			case 3:
				event = -1;
				break;
			case 4:
				event = 0;
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}

int menuPointConfig(){
	//On a besoin du pointeur pour les modifications
	PTR_CONFIG ptr_sur_config = ouvrirPanneauDeConfiguration();

	int event = 1 ;
	int maj=0;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheMenuPointConfig();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				event=menuModifierTauxSim(ptr_sur_config);
				getchar();
				break;
			case 2:
				event=menuModifierNbMaxMot(ptr_sur_config );
				system("echo ' ' > ./Database/Descripteur/liste_base_texte.txt");
				system("echo ' ' > ./Database/Descripteur/dT.txt");
				maj=1;
				getchar();
				break;
			case 3:
				event= menuModifierSeuilOccurence(ptr_sur_config);
				system("echo ' ' > ./Database/Descripteur/liste_base_texte.txt");
				system("echo ' ' > ./Database/Descripteur/dT.txt");
				maj=1;
				getchar();
				break;
			case 4:
				event=menuModifierNbIntervalle(ptr_sur_config);
				system("echo ' ' > ./Database/Descripteur/liste_base_audio.txt");
				system("echo ' ' > ./Database/Descripteur/dA.txt");
				maj=1;
				getchar();
				break;
			case 5:
				event=menuModifierNbPoints(ptr_sur_config);
				system("echo ' ' > ./Database/Descripteur/liste_base_audio.txt");
				system("echo ' ' > ./Database/Descripteur/dA.txt");
				maj=1;
				getchar();
				break;
			case 6:
				event=menuModifierNbBits(ptr_sur_config);
				system("echo ' ' > ./Database/Descripteur/liste_base_image.txt");
				system("echo ' ' > ./Database/Descripteur/dI.txt");
				maj=1;
				getchar();
				break;
			case 7:
				afficheValeurConfig();
				break;
			case 8:
				event = -1; //retour menu d'avant
				break;
			case 9:
				event = 0; //quitte le logiciel
				break;
			default:
				afficheErreurMenu();
				break;  
		}
	fflush(stdin);
	printf("\n");
	}

	//On libere l'espace memoire
	fermerPanneauDeConfiguration(ptr_sur_config);
	if(maj==1){
		printf("indexation avec les nouvelles valeurs en cours ...");
		Indexation();
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)

}

int menuModifierTauxSim(PTR_CONFIG config){
	affichageSaisieTauxSim();
	int event=0;
	int choix = 0; //Pour lire l'entree
	int retour;
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerTauxSimmilaritude(config, choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}
	
		

int menuModifierNbMaxMot(PTR_CONFIG config ){
	affichageSaisieNbMot();
	int event=0;
	int choix = 0; //Pour lire l'entree
	int retour; // verif retour scanf
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerNbMotParTexte(config, choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}

int menuModifierSeuilOccurence(PTR_CONFIG  config){	
	affichageSaisieOccurenceMot();
	int event=0;
	int choix = 0; //Pour lire l'entree
	int retour;
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerSeuilOccurence(config, choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}
	



int menuModifierNbIntervalle(PTR_CONFIG config ){
	affichageSaisieNbIntervalle();
	int event=0;
	int choix = 0; //Pour lire l'entree
	int retour;
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerNbIntervalle(config,choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}

int menuModifierNbPoints(PTR_CONFIG config){
	affichageSaisieNbPoint();
	int event=0;
	int choix = 0; //Pour lire l'entree
	int retour;
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerNbPoints(config, choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}


int menuModifierNbBits(PTR_CONFIG config){
	affichageSaisieNbBits();
		int event=0;
	int choix = 0; //Pour lire l'entree
	int retour;
	while(event==0){
		retour=scanf("%d",&choix);
		if(retour==0 ){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
		}
		else{
			event=changerNbBits(config,choix);
			if(event==0){
			printf("Veuillez choisir un nombre superieur a 0 \n");
			viderBuffer();
			}
			
		}
	} 
	fflush(stdin);
	
	return 1;
}


//#################################################################################################################################
//######### MENUS DE LA PARTIE UTILISATEUR ########################################################################################

int menuUtilisateur(){
	int event = 1 ;
	long choixMenu;
	char nomRecherche[50], chaine_result[10000];
	char motRecherche[50];
	char adresse[100];
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheMenuUtilisateur();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				recupMotRecherche(motRecherche);
				lanceRechercheViaMotCle(motRecherche,chaine_result);
				printf("%s\n",chaine_result);
				getchar(); 
				break;
			case 2:
				recupNomRecherche(nomRecherche);
				lanceRechercheViaNom(nomRecherche,chaine_result);
				printf("%s\n",chaine_result);
				getchar(); 
				break;
			case 3:
				recupAdresseRecherche(adresse);
				lanceRechercheViaAdresse(adresse,chaine_result);
				printf("%s\n",chaine_result);
				getchar();
				break;
			case 4:
				recupSelectionRecherche(adresse);
				lanceRechercheViaNom(adresse, chaine_result);
				printf("%s\n",chaine_result);
				getchar(); 
				break;
			case 5:
				event = -1; //retour menu d'avant
				break;
			case 6:
				event = 0; //quitte le logiciel
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}


void recupMotRecherche(char* mot){
		
	printf("\n");
	afficheRechercheParMot();
	scanf("%s", mot);
	fflush(stdin);
}


void recupNomRecherche(char* nom){
		
	printf("\n");
	afficheRechercheParNom();
	scanf("%s", nom);
	fflush(stdin);
}

void recupAdresseRecherche(char* adresse){
		
	printf("\n");
	afficheRechercheChemin();
	scanf("%s",adresse);
	fflush(stdin);
}

void recupSelectionRecherche(char* id_fichier){

	int event;
	printf("\n");
	afficheRechercheSelection();
	long choixMenu;
while(event != 0){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				event=0;
				afficheDataSelection();
				system("ls  ./Database/Texte/");
				printf("Veuillez choisir un fichier\n");
				break;
			case 2:
				event=0;
				afficheDataSelection();
				system("ls  ./Database/Audio/ | grep wav$");
				printf("Veuillez choisir un fichier\n");
				break;
			case 3:
				event=0;
				afficheDataSelection();
				system("ls ./Database/Image/NB | grep bmp$");
				system("ls  ./Database/Image/RGB| grep jpg$");
				printf("Veuillez choisir un fichier\n");
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}
	
	scanf("%s",id_fichier);
	fflush(stdin);
}
