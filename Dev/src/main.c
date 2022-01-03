#include <stdio.h>
#include <stdlib.h>
#include "../include/indexation.h"
#include "../include/img.h"
#include "../include/pile_Img.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"
#include "../include/admin.h"
#include "../include/recherche.h"
#include "../include/comparaison.h"

int main(int argc, char *argv[])
{
	char chaine[500];
	lanceRechercheViaNom(*(argv+1),chaine);
	/*char adresse[100];
	strcpy(adresse, "./Requete/51.bmp");
	lanceRechercheViaAdresse(adresse,chaine);*/
	printf("\n==========\n%s",chaine);
	return 0;
}