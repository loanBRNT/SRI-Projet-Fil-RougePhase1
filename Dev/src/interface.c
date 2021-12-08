#include "interface.h"




//########## FONCTIONS DE GESTION DES MENUS ###############
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
	printf("#         1: ACCES POINT CONFIG           #\n");
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
	printf("#           MENU POINT CONFIG             #\n");
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

//##########################################################
//##################### MENU PRINCIPAL #####################

int afficheMenuPrincipal(){
	/* lance l'affichage du menu principale
	  puis demande le numero du menu souhaite et lance la fonction de gestion du menu selectionne 
	  si le numero n'est pas bon on redemande un numero de menu
	  le choix numero 4 modifie la valeur de la variable event afin de sortir de la boucle et pouvoir arreter le programme
	*/
	afficheMessageBienvenue();
	int event = 1 ;
	long choixMenu;
	while(event != -1){
		afficheMenuPrincipal();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				menuAdminVerification();
				break;
			case 2:
				menuClient(reseau);
				break;
			case 3:
				afficheMessageQuitter();
				event = -1;
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
}

//##########################################################
//######### MENUS DE LA PARTIE ADMINISTRATEUR ##############

int cpt = 0;
int choix = 0;
int menuAdminVerification(){
	//on informe l'utilisateur qui rentre sur un menu prive
 //ici je voulais mettre les const
	printf("\n");
	printf("###########################################\n");
	printf("# Vous avez choisi le menu ADMINISTRATEUR #\n");
	printf("#       Vous etes sur un menu prive       #\n");
	printf("###########################################\n");
	printf("\n");
	
	while(cpt != (-1))
	{
		// on verifie la valeur de retour de verifierPwdAdmin pour savoir si l'utilisateur a saisi le bon mot de passe
 		cpt=verifierPwdAdmin();
 		// si le mot de passe est faux on demande a l'utilisateur si il veut reesayer la saisie car une erreur de frappe peut arriver
 		if(cpt==4)//si identifiant mauvais alors retourne 4
 		{

 			while(choix != 4)
			{
				long option = 0;// pourquoi long
				printf("###########################################\n");
 				printf("#          voulez vous reessayer ?        #\n");
 				printf("#                 1- OUI                  #\n");
 				printf("#                 2- NON                  #\n");
 				printf("###########################################\n");
				printf("\n");
 				option=lireLong();
				printf("\n");

				/* si l'utilisateur ne choisit pas un choix propose on lui repose la question 
				   si il choisit 1 on le laisse dans la boucle qui lance 3 essais pour la verification du mot de passe
				   si il choisit 2 on le sort de la boucle et on fini la fonction menuAdminVerification ce qui nous ramene dans la fonction main du programme
				*/ 
 				switch(option)
				{
					case 1:
						choix++; //au bout de 3 essai choix = 3
						cpt=1;//rentre dans la boucle verif mdp
						break;
					case 2:
						choix=1;
						cpt=-1;
						break;
					default:
						printf("###########################################\n");
				 		printf("#      Vous n'avez pas choisi 1 ou 2      #\n");
						printf("###########################################\n");
						break;
 				}
 			}
 		}
 		/* si le mot de passe est correct on lance la fonction menuAdmin
 		 lorsque la fonction menuAdmin ce termine on sort de la boucle
 		 pour finir la fonction menuAdminVerification ce qui nous ramene dans la fonction main du programme */
 		else{
 			menuAdmin(r);
 			cpt=-1;
 		}
	}
}



			if (choix == 4){
				printf("###########################################\n");
 				printf("#      Trop de tentative effectuer !      #\n");
  				printf("#                                         #\n");
  				printf("#      Vous êtes sortie du mode Admin     #\n");
 				printf("###########################################\n");
				printf("\n");
				choix=3;
				cpt=-1;
			}
			else if (choix == 3){
				printf("###########################################\n");
 				printf("#             !! ATTENTION !!             #\n");
  				printf("#                                         #\n");
  				printf("#          Il vous reste 1 essai          #\n");
 				printf("###########################################\n");
				printf("\n");
			}
			else if (choix == 2){
				printf("###########################################\n");
 				printf("#             !! ATTENTION !!             #\n");
  				printf("#                                         #\n");
  				printf("#          Il vous reste 2 essai          #\n");
 				printf("###########################################\n");
				printf("\n");
			}
			else if (choix == 1){
				printf("###########################################\n");
 				printf("#             !! ATTENTION !!             #\n");
  				printf("#                                         #\n");
  				printf("#          Il vous reste 3 essai          #\n");
 				printf("###########################################\n");
				printf("\n");
			}
			else{choix=0;}


int menuAdmin(){
	int event = 1 ;
	long choixMenu;
	while(event != -1){
		afficheMenuAdmin();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				menuPointConfig();
				break;
			case 2:
				LancerIdexation();
				break;
			case 4:
				event = -1;
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}
	return 0;
}

int menuPointConfig(){
	afficheMenuPointConfig();
}