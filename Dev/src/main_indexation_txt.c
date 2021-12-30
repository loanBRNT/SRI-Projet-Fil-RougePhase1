#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>


#include "indexation_txt.h"
	


	/*
int counting(FILE* ftok){
	Terme tab[]=(Terme)malloc(sizeof(Terme)*3);
	int cpt=1;
	char* chaine=(char *)malloc(MAX);

	while(!feof(ftok)){
		fgets(chaine,MAX,ftok);
		while
	}
}
*/







void main(int argc, char const *argv[])

{
	int nbtoktest=0;
	FILE* ftest=fopen("03-Mimer_un_signal_nerveux_pour.xml","r");										//ouverture fichier en xml (doit deja exister) à remplacer par le char* nom

	FILE* fclean=fopen("test_temp.clean","w+");						//creation fichier clean en écriture

	FILE* ftok=fopen("test_toktemp.tok","w+");	

	cleaning(ftest,fclean);

	//nbtoktest=CleanToTok(fclean,ftok);


	/* Passer par fctn indexationTxt(char* nom) qui renvoie le descri */
}