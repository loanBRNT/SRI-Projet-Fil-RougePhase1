#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/admin.h"
#include "../include/img.h"
#include "../include/indexation.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"

int main(int argc, char const *argv[])
{

    Indexation();
    


/*
   // char CHEMIN_TEXTE [100] =  "../Database/Texte/";
	char CHEMIN_AUDIO [100] =  "../Database/Audio/";
	//char CHEMIN_IMAGE_NB [100] =  "../Database/Image/NB/";
	//char CHEMIN_IMAGE_RGB [100] =  "../Database/Image/RGB/";
	char commande[1000] ;
	char nom_fic[100];
	char CHEMIN_INDEXATION [100];	
	FILE * ptr_fic; 
	PILE_Audio p =init_PILE_Audio();
    strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_AUDIO);
	strcat(commande, "| grep bin$ > fic_temp"); 
	printf("execution de %s\n", commande); 
	fflush(stdout);
	system(commande);
	DescripteurAudio DA;
	//---------------------------------------------------------------------//
	// AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE //
	//--------------------------------------------------------------------//
	system("cat fic_temp");
	printf("---------------------------------\n");
	ptr_fic = fopen("fic_temp", "r");
	if( ptr_fic != NULL){   

	    //POUR CHAQUE LIGNE CONTENUE DANS LE FICHIER, ON RECUPERE LE NOM DU FICHIER //
 	    // FORMAT DE LA LIGNE :  -rw-r--r--   1 ferrane  minfg       4834 Sep 23  2008 28-Danse___Robyn_Orlin_et.xml //
    
	    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);  // %*s INGNORE LA CHAINE LUE //
	   
 	    while ( !feof(ptr_fic) ){
 	    	if(VerificationTraitee(nom_fic)){
 	    		fprintf(stderr, "fichier deja indexee\n");
 	    	}
 	    	else{
    			if(strstr(nom_fic, ".bin")){
    				strcpy(CHEMIN_INDEXATION,"../Database/Audio/");	
    				strcat(CHEMIN_INDEXATION,nom_fic);
    				DA=IndexationFichierAudio(CHEMIN_INDEXATION,100,1024);
    				p=emPILE_Audio(p,DA);
    				affiche_PILE_Audio( p);
    				printf("%d\n",PILE_Audio_estVide(p));
    				strcpy(commande, "echo ");
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/FicIndexA.txt");
					system(commande); 
    			}
    			else{
    			fprintf(stderr, "ERREUR :  PB avec type du fichier\n");
    			}    		
 	    	}
		 	// nom de fichier suivant //
			fscanf( ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);
    	}
    	fclose(ptr_fic);
    }
	else
	{
   		fprintf(stderr, "ERREUR :  PB avec liste_rep\n");
	}


    FILE * f;
    f=fopen("../Database/Descripteur/dA.txt","w");
	while(!PILE_Audio_estVide(p)){
		p=dePILE_Audio(p,f);
	}
	fclose(f);


*/
	return 0;

};