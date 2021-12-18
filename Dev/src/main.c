#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/pwd.h"
#include "../include/interface.h"



int main(int argc, char const *argv[])
{

	/* lance l'affichage du menu principal
	  puis demande le numero du menu souhaite et lance la fonction de gestion du menu selectionne 
	  si le numero n'est pas bon on redemande un numero de menu
	  le choix numero 0 modifie la valeur de la variable event afin de sortir de la boucle et pouvoir arreter le programme
	*/
	afficheAccueil();
	printf("Appuyer sur une touche pour continuer...");
	getchar(); 
	//afficheMessageBienvenue(); | fonction à écrire |
	int event = 1 ;
	long choixMenu;
	//afficheAccueil();
	//printf("Appuyer sur une touche pour continuer...");
	//getchar(); 
	while(event != -1){
		afficheMenuPrincipal();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				if (menuAdminVerif()== 0) event = -1;
				break;
			case 2:
				if (menuUtilisateur() == 0) event = -1;
				break;
			case 0:
				//afficheMessageQuitter();
				printf("On quitte\n");
				event = -1;
				break;
			default:
				printf("Saisie Incorrecte\n");
				//afficheErreurMenu();
				break;
		}
	printf("\n");
	}
}