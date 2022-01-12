#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define MAX 30
#include "indexation_txt.h"

//------------------------------------------------------------------------------------------------------------------------

void cleaning(){												//Fonction CLEAN (ajouter le param char*)
	FILE* fclean=fopen("test_temp.clean","w+");	
	FILE* findex=fopen("03-Mimer_un_signal_nerveux_pour.xml","r");		//mettre le char*	
	int carac=0, curseur=0;
	rewind(findex);
	if(fclean!=NULL && findex!=NULL){							//verif ouverture/creation fichiers
				
		while((carac=fgetc(findex))!=EOF){
		
			if(carac>64 && carac<91){							//Maj to minuscules
				fprintf(fclean,"%c",carac+32);
			}
			else if(carac=='\n'){
				fprintf(fclean,"\n");}
			else if(carac==32){
				fprintf(fclean,"%c",13);
			}
			else if(carac==39){									//apostrophe to apostrophe+RC
				fprintf(fclean,"%c%c",carac,13);
			}
			else if(carac==60){
				carac=fgetc(findex);																		
				if(carac==97 || carac==100){					//test si auteur ou date
					fseek(findex,6,SEEK_CUR);					//on se decale vers l'avant de 7 (taille > a une balise auteur et date)
					while((carac=fgetc(findex))!=62){	 		//et on attend la fin de la section date ou auteur balisee
				continue;}
				}
				else{
					while(carac!=62){	 		//si ni date ni auteur, on ne recopie pas la balise
						carac=fgetc(findex);
				}
				}
				//fprintf(fclean,"%c",32);						//ajout d'un espace
				
			}
			else if(carac==45){
				fprintf(fclean,"%c",32);
			}
			else if((carac>32 && carac<48) || (carac>57 && carac<65) || (carac>90 && carac<97) || (carac>122 && carac<127)){
				continue;											//ponctuation non recopiée
			}
			else{
				fprintf(fclean,"%c",carac);
			}
		}
		
	}
	else{
		printf("\n Erreur ouverture/creation \n");
	}
	fclose(fclean);
	fclose(findex);
}

//------------------------------------------------------------------------------------------------------------------------

int CleanToTok(){	
																		//Fonction TOKEN
	FILE* fclean=fopen("test_temp.clean","r");							
	FILE* ftok=fopen("test_toktemp.tok","w+");							//CREATION FICHIER .TOK
	FILE* stoplist=fopen("stoplist.txt","r");							//OUVERTURE FICHIER STOPLIST
	
	if (fclean == NULL || ftok == NULL || stoplist == NULL){
		printf("ERREUR OUVERTURE\n");
		return 1;
	}

	int stop=0;
	int nbtok=0;

	char token[30],stopword[30];

	
	if(fclean!=NULL || stoplist!=NULL){
	
	rewind(fclean);														//curseur au debut de fclean
	
	while(!feof(fclean)){

		fscanf(fclean,"%s\n",token);
		rewind(stoplist);												//curseur au debut de la stoplist

		while(!feof(stoplist)){
			
			fscanf(stoplist,"%s\n",stopword);
			if(strcmp(token,stopword)==0){								//verif si stopword
				stop=1;
			}

		}
		if(stop!=1){
			fprintf(ftok,"%s\n",token);								
			nbtok++;													//comptage des tokens
		}
		stop=0;
		
	}

	}

	else{
		printf("\nERREUR OUVERTURE");
	}
	

	fclose(stoplist);													//FERMETURE FICHIERS
	fclose(ftok);
	fclose(fclean);
	return nbtok;
	}


//---------------------------------------------------------------------------------------------------------------------------

void Counting(DescripteurTxt Dt, int nbocc, int nbterme){
	
	char mot[30];
	char comp[30];
	int occurence=0;
	char commande[40];
	int cpt;
	Terme actTerme;

	strcpy(commande,"cat test_toktemp.tok > toktemp2.tok");

	fflush(stdin);
	system(commande);

	FILE* ftok=fopen("test_toktemp.tok","r");
	FILE* fictemp=fopen("toktemp2.tok","r");

	rewind(ftok);
	rewind(fictemp);
	while(!feof(ftok)){
		fscanf(ftok,"%s\n",mot);

		while(!feof(fictemp)){
			fscanf(fictemp,"%s\n",comp);
			if(strcmp(mot,comp)==0){
				occurence++;
			}
			if(occurence > nbocc && (strlen(mot)>1)){
				cpt=0;
				actTerme =(Dt.tableau[cpt]);
				while(cpt < nbterme){
					actTerme = (Dt.tableau[cpt]);
					if((occurence > actTerme.nboccurence) && (strcmp(mot,actTerme.token)!=0)){
						//intercalerTerme(ptrSurTerme, mot, occurence, cpt, nbterme);

					}
					if (actTerme.nboccurence == 0) break;
					cpt++;
					
				}
				if(cpt < nbterme){
					Dt.tableau[cpt] = ajouterTerme(actTerme, mot, occurence);
					printf("%d %d\n",Dt.tableau[cpt].nboccurence,occurence);
				}
				
			}
			
		}
		printf("%s : %d\n",mot,occurence);
		rewind(fictemp);
		occurence=0;

	}

	for(int i=0; i<nbterme ; i++){
		printf("%d : %s / %d \n",i,Dt.tableau[i].token , Dt.tableau[i].nboccurence);
	}

	fclose(fictemp);
	fclose(ftok);
}

//---------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------

DescripteurTxt initDescripteurTxt(int nbterme){
	DescripteurTxt DT;
	DT.nbtermes=nbterme;
	DT.nbtokens=0;
	DT.tableau=(Terme*) malloc(sizeof(Terme) * nbterme);						// taille a recup dans le .config
	for(int i=0; i<nbterme ; i++){
		DT.tableau[i].nboccurence = 0;
		DT.tableau[i].token = "123";
	}

	return DT;
	}

//---------------------------------------------------------------------------------------------------------------------------

DescripteurTxt indexationTxt(char* nom, int nbterme, int nbocc) 		//mettre char* nom en param

{
	int nbtok;
	DescripteurTxt DT;
	DT=initDescripteurTxt(nbterme);


	//FILE* fliste=fopen("table_index_texte.txt","w")					//liste table mots clés et occurance dans textes identifiés par leur ID


	cleaning();															//ajouter le char* nom en param

	DT.nbtokens=CleanToTok();

	Counting(DT, nbocc, nbterme);


	return DT;
	
}

//---------------------------------------------------------------------------------------------------------------------------

void printDescripteurTxt(FILE* fdescri){


}

//---------------------------------------------------------------------------------------------------------------------------

void printLinkTxtDescripteur(DescripteurTxt Dt, char* nom){
	/*FILE* findex=fopen();												//ouvrir/creer le fichier liant nom et ID

	fprintf(findex,"%s ",nom);
	fprintf(findex,"%d\n",DT.ID);

	fclose(findex);*/
}

//---------------------------------------------------------------------------------------------------------------------------

Terme ajouterTerme(Terme actTerme, char* mot, int occ){
	actTerme.token=mot;
	actTerme.nboccurence=occ;
	return actTerme;
}

//---------------------------------------------------------------------------------------------------------------------------
/*
void intercalerTerme(Terme* ptrSurTerme, char* mot, int occ, int cpt, int nbterme){
	Terme* ptrCopy=(Terme*)malloc(sizeof(Terme));
	Terme* ptrParcours=ptrSurTerme;

	ptrCopy->next=ptrSurTerme->next;
	//ptrCopy->token=ptrSurTerme->token;
	ptrCopy->nboccurence=ptrSurTerme->nboccurence;

	ptrSurTerme->token=mot;
	ptrSurTerme->nboccurence=occ;
	ptrSurTerme->next=ptrCopy;

	while(ptrParcours->next != NULL || cpt<nbterme){
		ptrParcours=ptrParcours->next;
		cpt++;
	}

	if (cpt == nbterme && ptrParcours != NULL){
		free(ptrParcours->next);
		ptrParcours->next=NULL;
	}

}
*/
//---------------------------------------------------------------------------------------------------------------------------