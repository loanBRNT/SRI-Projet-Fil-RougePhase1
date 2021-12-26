#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#include "../include/indexation.h"
#include "../include/descripteurAudio.h"
#include "../include/img.h"
#include "../include/pile_Audio.h"
#include "../include/pile_Img.h"
#include "../include/admin.h"
/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 10/12/21                         |
|       Date de derniere MAJ : 22/12/21                     |
|                                                           |
 ----------------------------------------------------------- 
*/


int VerificationTraitee(char* nom_fic){
	// V1 => si fichier perso meme nom que un fichier de la base de données alors renvoie deja traitee
	FILE * ptr_fic;
	char commande[1000] ;
	char CHEMIN_FICHIER_INDEXEE[100];
	char valeur[5];
	int traite;
	if (strstr(nom_fic, ".xml")){
    	strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/liste_base_texte.txt");
    }
    else if(strstr(nom_fic, ".bin")){
		strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/liste_base_audio.txt");
    }
    else if(strstr(nom_fic, ".txt")){
    	strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/liste_base_image.txt");
    }
    else{
    	fprintf(stderr, "ERREUR :  PB avec type du fichier\n");
    	return 0;
    } 
    strcpy(commande, "cat ");
	strcat(commande, CHEMIN_FICHIER_INDEXEE);
	strcat(commande, " |grep "); 
	strcat(commande, nom_fic);
	strcat(commande, " | wc -l >fic_temp2 ");
	printf("execution de %s\n", commande);
	fflush(stdout);
	system(commande);

	ptr_fic = fopen("fic_temp2", "r");

	if( ptr_fic != NULL){
		fscanf(ptr_fic, "%s", valeur);
		if(strstr(valeur, "1")){
			traite=1;
		}
		else
			traite=0;
	}
	else{
   		fprintf(stderr, "ERREUR :  PB avec liste_rep\n");
   	}
   	fclose(ptr_fic);
	return traite;	
		// supp fic-temp2
};




//Integrer indexation texte

void Indexation(){

	// mettre un chemin vers un rpertoire qui ne contient que des fichiers//
	char CHEMIN_TEXTE [100] =  "../Database/Texte/";
	char CHEMIN_AUDIO [100] =  "../Database/Audio/";
	char CHEMIN_IMAGE_NB [100] =  "../Database/Image/NB/";
	char CHEMIN_IMAGE_RGB [100] =  "../Database/Image/RGB/";
	char commande[1000] ;
	char nom_fic[100];
	char CHEMIN_INDEXATION [100];
	char* id = malloc(10*sizeof(char));	
	FILE * ptr_fic; 
	PILE_Audio pA =init_PILE_Audio();
	PILE_Img pI=init_PILE_Img();

	// recuperation des valeurs du .config
	//int recupTauxSimmilaritudeDuConfig();
	//int recupNbMotsParTexteDuConfig();
	//int recupSeuilOccurenceDuConfig();
	int intervalleAudio=recupNbIntervalleDuConfig();
	int nbrPointAudio =recupNbPointsDuConfig();
	int bitQ=recupNbBitsDuConfig();

/*




	// creation de la commande a executer ==> doit etre une chaine de carcatere//

	//------------------------------------------------------//
	// RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN_TEXTE //
	//------------------------------------------------------//
	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_TEXTE);
	strcat(commande, " > fic_temp"); 
	printf("execution de %s\n", commande); 
	fflush(stdout);
	system(commande);
	//---------------------------------------------------------------------//
	// AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE//
	//---------------------------------------------------------------------//
	system("cat fic_temp");
	printf("---------------------------------\n");

	ptr_fic = fopen("fic_temp", "r");

	if( ptr_fic != NULL){   

	    //POUR CHAQUE LIGNE CONTENUE DANS LE FICHIER, ON RECUPERE LE NOM DU FICHIER //
 	    // FORMAT DE LA LIGNE :  -rw-r--r--   1 ferrane  minfg       4834 Sep 23  2008 28-Danse___Robyn_Orlin_et.xml //

	    fscanf( ptr_fic, "%*s %*s");    //  SAUTER LA PREMIERE LIGNE CONSTITUEE DE 2 CHAINES total xxxx //
    
	    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);  // %*s INGNORE LA CHAINE LUE //
 	    while ( !feof(ptr_fic) ){
 	    	if(VerificationTraitee(nom_fic)){
 	    		fprintf(stderr, "fichier deja indexee\n");
 	    	}
 	    	else{
     			if (strstr(nom_fic, ".xml")){
     				strcpy(CHEMIN_INDEXATION,"../Database/Texte/");	
    				strcat(CHEMIN_INDEXATION,nom_fic);
     				// attention la seuelement nom du fichier et pas son chemin
    				//fonction indexation texte  ;
    				printf("indexation d'un fichier texte\n");
    				strcpy(commande, "echo ");
    				strcat(commande, ID);
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/dT.txt"); 
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


*/


	//------------------------------------------------------//
	// RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN_AUDIO //
	//------------------------------------------------------//

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_AUDIO);
	strcat(commande, "| grep bin$ > fic_temp"); 
	printf("execution de %s\n", commande); 
	fflush(stdout);
	system(commande);

	//---------------------------------------------------------------------//
	// AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE//
	//---------------------------------------------------------------------//
	system("cat fic_temp");
	printf("---------------------------------\n");
	ptr_fic = fopen("fic_temp", "r");
	if( ptr_fic != NULL){   

	    //POUR CHAQUE LIGNE CONTENUE DANS LE FICHIER, ON RECUPERE LE NOM DU FICHIER //
 	    // FORMAT DE LA LIGNE :  -rw-r--r--   1 ferrane  minfg       4834 Sep 23  2008 28-Danse___Robyn_Orlin_et.xml //
    
	    fscanf(ptr_fic, "%*s %*s %*s %*s %*s %*s %*s %*s %s", nom_fic);  // %*s INGNORE LA CHAINE LUE //
	   
 	    while ( !feof(ptr_fic) ){
 	    	 printf("%s", nom_fic);
 	    	if(VerificationTraitee(nom_fic)){
 	    		fprintf(stderr, "fichier deja indexee\n");
 	    	}
 	    	else{
    			if(strstr(nom_fic, ".bin")){
    				strcpy(CHEMIN_INDEXATION,"../Database/Audio/");	
    				strcat(CHEMIN_INDEXATION,nom_fic);
    				DescripteurAudio DA =IndexationFichierAudio(CHEMIN_INDEXATION,intervalleAudio,nbrPointAudio);
    				pA=emPILE_Audio(pA,DA);
    				sprintf(id,"%d", DA->identifiant);
    				strcpy(commande, "echo ");
    				strcat(commande,id);
    				strcat(commande," " );
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/liste_base_audio.txt");
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









	//------------------------------------------------------//
	// RECUPERATION DU CONTENU DU REPERTOIRE CHEMIN_IMAGE_NB//
	//------------------------------------------------------//

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_IMAGE_NB);
	strcat(commande, "| grep txt$ > fic_temp"); 
	printf("execution de %s\n", commande);
	fflush(stdout); 
	system(commande);


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
    			if(strstr(nom_fic, ".txt")){
    				strcpy(CHEMIN_INDEXATION,"../Database/Image/NB/");	
    				strcat(CHEMIN_INDEXATION,nom_fic);
    				Descripteur DI=indexer_image(CHEMIN_INDEXATION, bitQ);
    				pI=emPILE_Img(pI,DI);
    				sprintf(id,"%d", DI.ID);
    				strcpy(commande, "echo ");
    				strcat(commande, id );
    				strcat(commande," " );
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/liste_base_image.txt");
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


	//-------------------------------------------------------//
	// RECUPERATION DU CONTENU DU REPERTOIRE CHEMIN_IMAGE_RGB//
	//-------------------------------------------------------//

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_IMAGE_RGB);
	strcat(commande, "| grep txt$ > fic_temp"); 
	printf("execution de %s\n", commande);
	fflush(stdout); 
	system(commande);


	//---------------------------------------------------------------------//
	// AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE//
	//---------------------------------------------------------------------//
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
    			if(strstr(nom_fic, ".txt")){
    				strcpy(CHEMIN_INDEXATION,"../Database/Image/RGB/");	
    				strcat(CHEMIN_INDEXATION,nom_fic);
    				Descripteur DI=indexer_image(CHEMIN_INDEXATION, bitQ);
    				pI=emPILE_Img(pI,DI);
    				sprintf(id,"%d", DI.ID);
    				strcpy(commande, "echo ");
    				strcat(commande, id );
    				strcat(commande," " );
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/liste_base_image.txt");
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






	//---------------------------------------------------------------------//
	// Sauvegarde des descripteurs dans un fichier                         //
	//---------------------------------------------------------------------//

	FILE * f;
    f=fopen("../Database/Descripteur/dA.txt","a+");
	while(!PILE_Audio_estVide(pA)){
		pA=dePILE_Audio(pA,f);
	}
	fclose(f);


	f=fopen("../Database/Descripteur/dI.txt","a+");
	while(!PILE_Img_estVide(pI)){
		pI=dePILE_Img(pI,f);
	}
	fclose(f);
	strcpy(commande, "rm fic_temp fic_temp2 ");
	system(commande); 

};
