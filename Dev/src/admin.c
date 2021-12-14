#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/admin.h"

int affectAttributConfig(PTR_CONFIG config, char* nomAttribut, int valeur){
	if (!strcmp(nomAttribut,"tauxSim")){
		config->tauxSim = valeur;
	} else if (!strcmp(nomAttribut,"nbMaxMotParTexte")){
		config->nbMotParTxt = valeur;
	} else if (!strcmp(nomAttribut, "seuilOccurenceMot")){
		config->seuilOccMot = valeur;
	} else if (!strcmp(nomAttribut, "nombreIntervalleAudio")){
		config->nbIntervalle = valeur;
	} else if (!strcmp(nomAttribut, "nombreFenetreAudio")){
		config->nbFenetre = valeur;
	} else if (!strcmp(nomAttribut, "nombreBitsQuantification")){
		config->nbBits = valeur;
	} else {
		return 0;
	}
	return 1;
}


PTR_CONFIG ouvrirPanneauDeConfiguration(){
	char nomAttribut[30];
	int valeur;
	PTR_CONFIG config = (PTR_CONFIG) malloc(sizeof(struct s_config));

	FILE * ptr_fic = fopen(".config","r");
	if (ptr_fic == NULL){
		fprintf(stderr, "ERREUR : probleme d'acces a .config");
		return NULL;
	}

	do {
		fscanf(ptr_fic,"%s %d", nomAttribut, &valeur);
		if (!affectAttributConfig(config,nomAttribut,valeur)){
			fprintf(stderr,"ERREUR : Parametre %s du .config inconu",nomAttribut);
		}
	} while (!feof(ptr_fic));

	return config;

}


void main(void)
{
	PTR_CONFIG config = ouvrirPanneauDeConfiguration();
}