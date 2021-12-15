#include <stdio.h>
#include <stdlib.h>
#include "../include/interface.h"
#include "../include/pwd.h"

int main(int argc, char const *argv[])
{

	/* lance l'affichage du menu principal
	  puis demande le numero du menu souhaite et lance la fonction de gestion du menu selectionne 
	  si le numero n'est pas bon on redemande un numero de menu
	  le choix numero 4 modifie la valeur de la variable event afin de sortir de la boucle et pouvoir arreter le programme
	*/

	//afficheMessageBienvenue(); | fonction à écrire |
	int event = 1 ;
	long choixMenu;
	while(event != -1){
		afficheMenuPrincipal();
		choixMenu=lireLong();
		printf("\n");
		switch(choixMenu)
		{
			case 1:
				if (menuAdminVerif() == 0) event = -1;
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