#ifndef Indexation_txt_h
#define Indexation_txt_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_termes{
	char* token;
	int nbocc;
}Terme;

typedef struct s_descripteurtxt
{
	char* ID;
	Terme table[5];		//taille table a recup dans le .config
	int nbtermes;
	int nbtokens;
	
}DescripteurTxt;



DescripteurTxt indexationTxt(char* nom);
DescripteurTxt initDescripteurTxt();
void cleaning(FILE* findex, FILE* fclean);
int CleanToTok(FILE* fclean, FILE* ftok);












#endif