<<<<<<< HEAD
#include <stdio.h>
#include "img.h"

#define n 2

int main(int argc, char const *argv[])
{
    Descripteur descripteur;

	printf("Tout commence ici....\n");
    descripteur = indexer_image("../Database/Image/RGB/50.txt", n);
        printf("{%d,%d,", descripteur.ID, descripteur.t_max);
        for (int i = 0; i < descripteur.t_max; i++) {
            printf("%d ", descripteur.histogramme[i]);
        }
        printf("}\n");
	return 0;
=======
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
	int event = 1 ;
	long choixMenu;
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
			case 3:
				event = -1;
				break;
			default:
				afficheErreurMenu();
				break;
		}
	printf("\n");
	}
	printf("###########################################\n");
 	printf("#       fermeture de 'lapplication        #\n");
 	printf("###########################################\n");


	return 0;
>>>>>>> interfaceEliott
}