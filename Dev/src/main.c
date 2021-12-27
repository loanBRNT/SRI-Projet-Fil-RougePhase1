#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../include/admin.h"
#include "../include/img.h"
#include "../include/indexation.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"
#include "../include/pile_Img.h"

int main(int argc, char const *argv[])
{


	//srand(time(NULL));

	Indexation();
   PILE_Audio PA=init_PILE_Audio();
   PA=Charger_Pile_DescripteurAudio( PA);
  	affiche_PILE_Audio(PA);
   dePILE_Audio_Sans_Sauvegarde(PA);



	return 0;

};