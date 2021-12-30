#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define MAX 30
#include "indexation_txt.h"

void cleaning(FILE* findex, FILE* fclean){						//Fonction CLEAN
	int carac=0, curseur=0;
	if(fclean!=NULL && findex!=NULL){							//verif ouverture/creation fichiers
				
		while((carac=fgetc(findex))!=EOF){

			if(carac>64 && carac<91){							//Maj to minuscules
				fprintf(fclean,"%c",carac+32);
			}
			else if(carac==13){;}
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
				;}
				}
				else{
					while((carac=fgetc(findex))!=62){	 		//si ni date ni auteur, on ne recopie pas la balise
				;}
				}
				//fprintf(fclean,"%c",32);						//ajout d'un espace
				
			}
			else if((carac>32 && carac<48) || (carac>57 && carac<65) || (carac>90 && carac<97) || (carac>122 && carac<127)){
				;												//ponctuation non recopiée
			}
			else{
				fprintf(fclean,"%c",carac);
			}
		}
		
	}
	else{
		printf("\n Erreur ouverture/creation \n");
	}
}

int CleanToTok(FILE* fclean, FILE* ftok){						//Fonction TOKEN
	
	int stop=0;
	int nbtok=0;
	char* token = (char *)malloc(sizeof(char)*MAX);
	char* stopword = (char *)malloc(sizeof(char)*MAX);
	//char token[20],stopword[20];



	FILE* stoplist=fopen("stoplist.txt","r");				//OUVERTURE FICHIER STOPLIST

	if(fclean!=NULL && stoplist!=NULL){
	

	rewind(fclean);											//curseur au debut de fclean
	
	while(!feof(fclean)){
		fscanf(fclean,"%s",token);
		rewind(stoplist);									//curseur au debut de la stoplist

		while(!feof(stoplist)){
			fscanf(stoplist,"%s",stopword);
			if(strcmp(token,stopword)==0){					//verif si stopword
				stop=1;
				break;
			}
		}
		if(stop!=1){
			/*int cpt=0;
			while(token[cpt]!=0){
				fprintf(ftok,"%c",token[cpt]);
				cpt++;
			}
			fprintf(ftok,"\n");*/
			fprintf(ftok,"%s\n",token);								
			nbtok++;										//comptage des tokens
		}
		
	}
	}
	else{
		printf("\n Erreur ouverture/creation");
	}

	free(token);
	free(stopword);


	fclose(stoplist);										//FERMETURE FICHIER STOPLIST
	return nbtok;
	}


	DescripteurTxt initDescripteurTxt(){
		//DescripteurTxt DT = (DescripteurTxt)malloc(sizeof(DescripteurTxt));
		//DT.nbtermes=0;
		//DT.nbtokens=0;
		//DT.table=(Terme)malloc(sizeof(Terme)*5);			// taille a recup dans le .config
		//ID?

		//return DT;
	}


	DescripteurTxt indexationTxt(char* nom) 						//mettre char* nom en param

{
	int nbtok;
	DescripteurTxt DT;
	DT=initDescripteurTxt();
	
	FILE* findex=fopen(nom,"r");										//ouverture fichier en xml (doit deja exister) à remplacer par le char* nom

	FILE* fclean=fopen("test_temp.clean","w+");						//creation fichier clean en écriture

	FILE* ftok=fopen("test_toktemp.tok","w+");						//creation fichier tok

	//FILE* fliste=fopen("table_index_texte.txt","w")					//liste table mots clés et occurance dans textes identifiés par leur ID


	cleaning(findex,fclean);
	
	//nbtok=CleanToTok(fclean,ftok);



	
	fclose(fclean);
	fclose(findex);
	fclose(ftok);
	return DT;
	
}