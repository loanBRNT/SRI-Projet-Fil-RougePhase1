

int main(int argc, char const *argv[])
{

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
				menuAdminVerification(reseau);
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