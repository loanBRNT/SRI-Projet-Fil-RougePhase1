#ifndef Indexation_txt_h
#define Indexation_txt_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_termes{
	char token[30];
	int nboccurence;
}Terme;

typedef struct s_descripteurtxt
{
	int ID;
	int nbtermes;
	int nbtokens;
	Terme* tableau;								

}DescripteurTxt;



DescripteurTxt indexationTxt(char* nom, int occ, int nbterme);
DescripteurTxt initDescripteurTxt();
void cleaning(char* nom);
int CleanToTok();
void printDescripteurTxt(DescripteurTxt DT, FILE* fdescri);
DescripteurTxt Counting(DescripteurTxt Dt, int nbocc, int nbterme);
Terme ajouterTerme(Terme actTerme, char* mot, int occ);
void intercalerTerme(Terme* tab, char* mot, int occ, int cpt, int nbterme);
int incrementerNbTerme(int nb, int nbtermeMAX);
int motDejaConnu(Terme* tableau, char* mot, int nbterme);
int sauvegardeMotCle();





#endif