#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/indexation.h"
#include "../include/descripteurAudio.h"
#include "../include/img.h"
/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 10/12/21                         |
|       Date de derniere MAJ : 19/12/21                     |
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
    	strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/dT.txt");
    }
    else if(strstr(nom_fic, ".bin")){
		strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/dA.txt");
    }
    else if(strstr(nom_fic, ".txt")){
    	strcpy( CHEMIN_FICHIER_INDEXEE,"../Database/Descripteur/dI.txt");
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

void Indexation(){

	/* mettre un chemin vers un rpertoire qui ne contient que des fichiers */
	char CHEMIN_TEXTE [100] =  "../Database/Texte/";
	char CHEMIN_AUDIO [100] =  "../Database/Audio/";
	char CHEMIN_IMAGE_NB [100] =  "../Database/Image/NB/";
	char CHEMIN_IMAGE_RGB [100] =  "../Database/Image/RGB/";
	char commande[1000] ;
	char nom_fic[100];
	char ID[10]= "101";
	FILE * ptr_fic; 

	/* creation de la commande a executer ==> doit etre une chaine de carcatere */

	/*------------------------------------------------------*/
	/* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN_TEXTE  */
	/*------------------------------------------------------*/
	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_TEXTE);
	strcat(commande, " > fic_temp"); 
	printf("execution de %s\n", commande); 
	fflush(stdout);
	system(commande);
	/*---------------------------------------------------------------------*/
	/* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
	/*---------------------------------------------------------------------*/
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

	/*------------------------------------------------------*/
	/* RECUPERATION DU CONTENU DU REPERTOIRE  CHEMIN_AUDIO  */
	/*------------------------------------------------------*/

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_AUDIO);
	strcat(commande, "| grep bin$ > fic_temp"); 
	printf("execution de %s\n", commande); 
	fflush(stdout);
	system(commande);

	/*---------------------------------------------------------------------*/
	/* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
	/*---------------------------------------------------------------------*/
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
    			if(strstr(nom_fic, ".bin")){
    				DescrpiteurAudio DA =IndexationFichierAudio(nom_fic,100,1024);
    				Affiche_DescripteurAudio(DescrpiteurAudio DA);
    				strcpy(commande, "echo ");
    				strcat(commande, ID);
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/dA.txt");
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

	/*------------------------------------------------------*/
	/* RECUPERATION DU CONTENU DU REPERTOIRE CHEMIN_IMAGE_NB*/
	/*------------------------------------------------------*/

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_IMAGE_NB);
	strcat(commande, "| grep txt$ > fic_temp"); 
	printf("execution de %s\n", commande);
	fflush(stdout); 
	system(commande);

	/*-------------------------------------------------------*/
	/* RECUPERATION DU CONTENU DU REPERTOIRE CHEMIN_IMAGE_RGB*/
	/*-------------------------------------------------------*/

	strcpy(commande, "ls -l ");
	strcat(commande, CHEMIN_IMAGE_RGB);
	strcat(commande, "| grep txt$ >> fic_temp"); 
	printf("execution de %s\n", commande);
	fflush(stdout); 
	system(commande);


	/*---------------------------------------------------------------------*/
	/* AFFICHAGE DU CONTENU DU FICHIER CREE LORS DE LA PRECEDENTE COMMANDE */
	/*---------------------------------------------------------------------*/
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
    			if(strstr(nom_fic, ".txt")){
    				//fonction indexation image;
    				printf("indexation d'un fichier image\n");
    				strcpy(commande, "echo ");
    				strcat(commande, ID);
					strcat(commande, nom_fic);
					strcat(commande, " >> ../Database/Descripteur/dI.txt");
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


	// enregistrer descritpeur dans le fichier correspondant
	// supp fic-temp
	// a tester avec fich-temp trier(sort) pour voir si chaque fichier et bien traiter selon son type
};
