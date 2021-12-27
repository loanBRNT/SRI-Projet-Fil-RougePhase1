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
   PILE_Img PI=init_PILE_Img();
   PI=Charger_Pile_DescripteurImg( PI);
  	affiche_PILE_Img(PI);
   dePILE_Img_Sans_Sauvegarde(PI);



	return 0;

};