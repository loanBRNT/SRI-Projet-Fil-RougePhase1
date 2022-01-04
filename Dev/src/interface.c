#include <stdlib.h>
#include <stdio.h>
#include "../include/admin.h"
#include "../include/pwd.h"
#include "../include/interface.h"



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
	printf("#            0:QUITTER                    #\n");
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
	printf("#         0: QUITTER                      #\n");
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
	printf("#        7: RETOUR MENU ADMIN             #\n");
	printf("#                                         #\n");
	printf("#        0: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}

void afficheErreurMenu(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#    SAISIE INCORECT VEUILLEZ RÉESSAYER   #\n");
	printf("#                                         #\n");
	printf("#                                         #\n");
	printf("#       VEUILLEZ APPUYER SUR ESPACE       #\n");
	printf("#            POUR CONTINUER...            #\n");
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
	printf("#        3: PAR ADRESSE                   #\n");
	printf("#                                         #\n");
	printf("#        4: PAR selection                 #\n");
	printf("#                                         #\n");
	printf("#        5: RETOUR MENU PRINCIPAL         #\n");
	printf("#                                         #\n");
	printf("#        0: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}


void afficheRechercheMotCle(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#          RECHERCHE PAR MOT CLÉ          #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        1: // AFFICHAGE DES DIFF CONFIG  #\n");
	printf("#                                         #\n");
	printf("#        2: RETOUR MENU ADMIN             #\n");
	printf("#                                         #\n");
	printf("#        0: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}


void afficheRechercheNom(){
	char* result = recupNomRecherche();
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#            RECHERCHE PAR NOM            #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#      1: Vous avez chercher le fichier:%s   #\n",result);
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
    free(result);
}


void afficheRechercheChemin(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#           RECHERCHE PAR CHEMIN          #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        1: // AFFICHAGE DES DIFF CONFIG  #\n");
	printf("#                                         #\n");
	printf("#        2: RETOUR MENU ADMIN             #\n");
	printf("#                                         #\n");
	printf("#        3: RETOUR MENU PRINCIPAL         #\n");
	printf("#                                         #\n");
	printf("#        0: QUITTER                       #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
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

//#################################################################################################################################


// ======================================================================================================
// ======================================================================================================

int menuAdminVerif(){
	int cpt = 1;
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
			}
			else{
				choix = choix+1;
            	cpt=1; //on rerentre ds la boucle pour verif mdp
			}
		}

            /*
            Il faut coder la vérification du mot de passe à partir de mdp/admin.txt
            */
        else if (choix == 3){
        	afficheErreurMenu();
        	cpt =-1;
        }
        else {
            printf("pas troupe sort de la boucle");
            cpt = -1; //on sort
            menuAdmin();
            }
    }
    return cpt;
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
				if (menuPointConfig() == 0) event = 0; //si la valeur de retour du menu suivant est 0 alors on doit quitter
				break;
			case 2:
				//LancerIdexation();
				printf("On lance L'indexation\n");
				break;
			case 3:
				event = -1;
				break;
			case 0:
				event = 0;
				break;
			default:
				afficheErreurMenu();
				getchar();
				fflush(stdin);
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
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheMenuPointConfig();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				event = -1; //retour menu d'avant
				break;
			case 0:
				event = 0; //quitte le logiciel
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}

	//On libere l'espace memoire
	fermerPanneauDeConfiguration(ptr_sur_config);

	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)

}

int menuModifierTauxSim(PTR_CONFIG config){
	affichageSaisieTauxSim();
	/*int choix = 0; //Pour lire l'entree
	if (changerTauxSimmilaritude(config, choix) == 0){
		printf("Veuillez choisir un taux de similarité entre 0 et 100");
	} else {
		printf("ca c'est bien passe");
	}*/
	
	return -1;
}

//#################################################################################################################################
//######### MENUS DE LA PARTIE UTILISATEUR ########################################################################################

int menuUtilisateur(){
	int event = 1 ;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheMenuUtilisateur();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				//lancer recherche mot cle
				if (menuRechercheParMot() == 0) event = 0; //si la valeur de retour du menu suivant est 0 alors on doit quitter
				break;
			case 2:
				//lancer recherche Nom
			if (menuRechercheParNom() == 0) event = 0; //si la valeur de retour du menu suivant est 0 alors on doit quitter
				break;
			case 3:
				//lancer recherche chemin
			if (menuRechercheParchemin() == 0) event = 0; //si la valeur de retour du menu suivant est 0 alors on doit quitter
				break;
			case 4:
				//LancerRecherche Selection
				break;
			case 5:
				event = -1; //retour menu d'avant
				break;
			case 0:
				event = 0; //quitte le logiciel
				break;
			default:
				printf("SAISIE INCORRECTE\n");
				//afficheErreurMenu(); CETTE FONCTION N'EXISTE PAS
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}

int menuRechercheParMot(){
	int event = 1 ;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheRechercheMotCle();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				printf("Vous avez lancer la recherche par Mot");
				break;
			case 2:
				event = -1; //retour menu utilisateur
				break;
			case 0:
				event = 0; //quitte le logiciel
				break;
			default:
				printf("SAISIE INCORRECTE\n");
				//afficheErreurMenu(); CETTE FONCTION N'EXISTE PAS
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}

int menuRechercheParNom(){
	int event = 1 ;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheRechercheNom();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1: ;
				char* nom = recupNomRecherche();
                // print
                printf("%s", nom);
                free(nom);
				break;
			case 2:
				event = -1; //retour menu utilisateur
				break;
			case 0:
				event = 0; //quitte le logiciel
				break;
			default:
				printf("SAISIE INCORRECTE\n");
				//afficheErreurMenu(); CETTE FONCTION N'EXISTE PAS
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}

int menuRechercheParchemin(){
	int event = 1 ;
	long choixMenu;
	while((event != -1) && (event != 0)){ //Event 0 représente une fermeture du programme, -1 pour un retour simple au menu précédent
		afficheRechercheChemin();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				printf("Vous avez lancer la recherche par chemin");
				break;
			case 2:
				event = -1; //retour menu utilisateur
				break;
			case 0:
				event = 0; //quitte le logiciel
				break;
			default:
				printf("SAISIE INCORRECTE\n");
				//afficheErreurMenu(); CETTE FONCTION N'EXISTE PAS
				break;
		}
	printf("\n");
	}
	return event; //pr indiquer au menu précédent s'il doit tourner (retour simple -1) ou s'arrêter lui aussi (quitter 0)
}