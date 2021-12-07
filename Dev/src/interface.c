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
	printf("#   Bienvenue sur le MODE ADMINISTRATEUR  #\n");
	printf("#                                         #\n");
	printf("#         1: CONFIG INDEXATION            #\n");
	printf("#                                         #\n");
	printf("#         2: LANCER INDEXATION            #\n");
	printf("#                                         #\n");
	printf("#         3: RETOUR MENU PRINCIPAL        #\n");
	printf("#                                         #\n");
	                  4: QUITTER

	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}
void afficheMenuUtilisateur(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#   Bienvenue sur le MODE UTILISATEUR     #\n");
	printf("#                                         #\n");
	printf("#        1: LANCER UNE RECHERCHE          #\n");
	                     mot de clé

	printf("#                                         #\n");
	printf("#        2: RETOUR MENU PRINCIPAL         #\n");
	printf("#                                         #\n");
	printf("#        << choisissez un menu >>         #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
	printf("\n");
}


//##########################################################
//######### MENUS DE LA PARTIE ADMINISTRATEUR ##############

int afficheMenuAdmin(){
	//on informe l'utilisateur qui rentre sur un menu prive
	int cpt = 0;
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
 		if(cpt==1)//mdp faux
 		{
		int choix = 0;
		while(choix != 1)
		{
			int choix = 0;
			while(choix != 3){
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
						choix =1; //au bout de 3 essai cpt = 3
						cpt=1;
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
	}
}