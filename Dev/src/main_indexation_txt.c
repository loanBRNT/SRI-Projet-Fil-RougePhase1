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
	DescripteurTxt DT=initDescripteurTxt(8);
	cleaning("03-Mimer_un_signal_nerveux_pour.xml");
	 
	nbtoktest=CleanToTok();
	printf("%d\n",nbtoktest);
	Counting(DT, 2, 8);

	printf("=============================\n");
	for(int i=0; i<8 ; i++){
		if (DT.tableau[i].nboccurence == 0) break;
		printf("%d : %s / %d \n",i,DT.tableau[i].token , DT.tableau[i].nboccurence);
	}
	printf("=============================\n");

	/* Passer par fctn indexationTxt(char* nom, int occ, int nb) qui renvoie le descri */
}