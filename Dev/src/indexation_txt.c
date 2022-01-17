#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define MAX 30
#include "../include/img.h"
#include "indexation_txt.h"

//------------------------------------------------------------------------------------------------------------------------

void cleaning(char* nom){												//Fonction CLEAN (ajouter le param char*)
	FILE* fclean=fopen("test_temp.clean","w+");	
	FILE* findex=fopen(nom,"r");										//mettre le char*	
	int carac=0;
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
	FILE* stoplist=fopen("./Database/Descripteur/stoplist.txt","r");							//OUVERTURE FICHIER STOPLIST
	
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

DescripteurTxt Counting(DescripteurTxt Dt, int nbocc, int nbterme){
	
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

		if (motDejaConnu(Dt.tableau,mot,nbterme) == 0) continue;

		while(!feof(fictemp)){
			fscanf(fictemp,"%s\n",comp);
			if(strcmp(mot,comp)==0){
				occurence++;
			}
		}
		if(occurence > nbocc && (strlen(mot)>1)){
			cpt=0;
			actTerme =(Dt.tableau[cpt]);
			while(cpt < nbterme){
				actTerme = (Dt.tableau[cpt]);
				if((occurence > actTerme.nboccurence)){
					intercalerTerme(Dt.tableau, mot, occurence, cpt, nbterme);
					break;
				}
				if (actTerme.nboccurence == 0) break;
				cpt++;
				
			}
			if(cpt < nbterme){
				Dt.tableau[cpt] = ajouterTerme(actTerme, mot, occurence);
			}
			
		}
		rewind(fictemp);
		occurence=0;

	}

	fclose(fictemp);
	fclose(ftok);
	return Dt;
}

//---------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------

DescripteurTxt initDescripteurTxt(int nbterme){
	DescripteurTxt DT;
	DT.ID=generationIdUnique(1);
	DT.nbtermes=nbterme;
	DT.nbtokens=0;
	DT.tableau=(Terme*) malloc(sizeof(Terme) * nbterme);						// taille a recup dans le .config
	for(int i=0; i<nbterme ; i++){
		DT.tableau[i].nboccurence = 0;
		strcpy(DT.tableau[i].token, "123");
	}

	return DT;
	}

//---------------------------------------------------------------------------------------------------------------------------

DescripteurTxt indexationTxt(char* nom, int nbterme, int nbocc) 		//mettre char* nom en param

{

	DescripteurTxt DT;
	DT=initDescripteurTxt(nbterme);

	cleaning(nom);															

	DT.nbtokens=CleanToTok();

	DT = Counting(DT, nbocc, nbterme);

	return DT;
	
}

//---------------------------------------------------------------------------------------------------------------------------

void printDescripteurTxt(DescripteurTxt Dt, FILE* fdescri){

	fprintf(fdescri,"%d\n",Dt.ID);
	fprintf(fdescri,"%d\n",Dt.nbtermes);
	fprintf(fdescri,"%d\n",Dt.nbtokens);

	for(int i=0; i<Dt.nbtermes ; i++){
		if (Dt.tableau[i].nboccurence == 0) break;
		fprintf(fdescri,"%s %d \n",Dt.tableau[i].token , Dt.tableau[i].nboccurence);
	}
	fprintf(fdescri,"\n");

}

DescripteurTxt LireDescripteurTexte( FILE*f,int id, int nbtermes, int nbtokens){
    char *lu =(char *) malloc(30*sizeof(char));
    int valeur;
    int i=0;
    DescripteurTxt DT=initDescripteurTxt(nbtermes);;
    DT.ID=id;
    DT.nbtokens=nbtokens;
    fscanf(f,"%s",lu);
    while(i<nbtermes){
    	strcpy(DT.tableau[i].token, lu);
    	fscanf(f,"%s",lu);
        valeur=atoi(lu);
        DT.tableau[i].nboccurence = valeur;
        fscanf(f,"%s",lu);
        i++;
    }
    return DT;

}

//---------------------------------------------------------------------------------------------------------------------------

void printLinkTxtDescripteur(DescripteurTxt Dt, char* nom, FILE* fdtxt){
	
	fprintf(fdtxt,"%d %s\n",Dt.ID,nom);

}

//---------------------------------------------------------------------------------------------------------------------------

Terme ajouterTerme(Terme actTerme, char* mot, int occ){
	strcpy(actTerme.token,mot);
	actTerme.nboccurence=occ;
	return actTerme;
}

//---------------------------------------------------------------------------------------------------------------------------

void intercalerTerme(Terme* tableau, char* mot, int occ, int cpt, int nbterme){
	for (int i = nbterme-1; i > cpt; i--)
	{
		tableau[i] = tableau[i-1];
	}

	tableau[cpt].nboccurence = occ;
	strcpy(tableau[cpt].token, mot);

}

//---------------------------------------------------------------------------------------------------------------------------

int motDejaConnu(Terme* tableau, char* mot, int nbterme){
	int pasConnu = 1;
	for (int i = 0; i < nbterme; ++i)
	{
		if(!strcmp(tableau[i].token,mot)){
			pasConnu = 0;
		}
	}
	return pasConnu;
}

//---------------------------------------------------------------------------------------------------------------------------

int sauvegardeMotCle(){				
	char commande[100];
	char chaine[1000];
	char mot[30];
	char motcpy[30];
	char temp1[30], temp2[30];
	int nbterme,nbtermecpy,nbtok,nbtokcpy,ID,Idcpy,occ, occcpy;;

	strcpy(commande,"cat ./Database/Descripteur/dT.txt > ./Database/Descripteur/dtcopy.txt");
	fflush(stdin);
	system(commande);

	FILE* fdT=fopen("./Database/Descripteur/dT.txt","r");
	FILE* fcopy=fopen("./Database/Descripteur/dtcopy.txt","r");
	FILE* fkeyword=fopen("./Database/Descripteur/table_index_texte.txt","w+");

	if (fdT == NULL || fcopy == NULL || fkeyword == NULL ){
		printf("ERREUR\n");
		return 1;
	}

	//vidage de la chaine
	strcpy(chaine,"");

	rewind(fdT);
	while(!feof(fdT)){
		fscanf(fdT,"%d\n",&ID);
		fscanf(fdT,"%d\n",&nbterme);
		fscanf(fdT,"%d\n",&nbtok);

		for(int i=0; i<nbterme ; i++){
			rewind(fcopy);

			fscanf(fdT,"%s %d ",mot,&occ);

			if(strstr(chaine,mot)==NULL){

				strcat(chaine,mot);
				strcat(chaine,"\n");

				while(!feof(fcopy)){

					fscanf(fcopy,"%d\n",&Idcpy);
					fscanf(fcopy,"%d\n",&nbtermecpy);
					fscanf(fcopy,"%d\n",&nbtokcpy);

					for(int j=0; j<nbtermecpy; j++){

						fscanf(fcopy,"%s %d ",motcpy,&occcpy);

						if(strcmp(motcpy,mot)==0){
							sprintf(temp1,"%d",Idcpy);
							sprintf(temp2,"%d",occcpy);
							strcat(chaine,temp1);
							strcat(chaine," ");
							strcat(chaine,temp2);
							strcat(chaine," ");
						}
					}
				}
				strcat(chaine,"\n\n");
			}
		}

	}

	fprintf(fkeyword,"%s",chaine);
	
	fclose(fkeyword);
	fclose(fcopy);
	fclose(fdT);
	return 0;
}