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
	DescripteurTxt DT=initDescripteurTxt(4);
	cleaning();
	 
	nbtoktest=CleanToTok();
	printf("%d\n",nbtoktest);
	Counting(DT, 2, 4);

	/* Passer par fctn indexationTxt(char* nom, int occ, int nb) qui renvoie le descri */
}