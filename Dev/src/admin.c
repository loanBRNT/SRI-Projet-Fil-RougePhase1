#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/admin.h"

/* 
 ----------------------- Signature -------------------------
|															|
|		Auteur : BERNAT Loan								|
|		Date de creation : 10/12/21							|
|		Date de derniere MAJ : xx/01/22						|
|															|
 ----------------------------------------------------------- 
 */

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
	
	// On parcourt chaque ligne du .config et on lest stocke en memoire a l'adresse pointe par config

	do {
		fscanf(ptr_fic,"%s %d", nomAttribut, &valeur);
		if (!affectAttributConfig(config,nomAttribut,valeur)){
			fprintf(stderr,"ERREUR : Parametre %s du .config inconu",nomAttribut);
		}
	} while (!feof(ptr_fic));
	fclose(ptr_fic);

	config->maj = 0;
	return config;
}

void sauvegardeConfig(PTR_CONFIG config){
	FILE * ptr_fic = fopen(".config","w");
	if (ptr_fic == NULL){
		fprintf(stderr, "ERREUR : probleme d'acces a .config");
	} else {
		fprintf(ptr_fic, "tauxSim %d\nnbMaxMotParTexte %d\nseuilOccurenceMot %d\nnombreIntervalleAudio %d\nnombreFenetreAudio %d\nnombreBitsQuantification %d",
		config->tauxSim, config->nbMotParTxt, config->seuilOccMot, config->nbIntervalle, config->nbFenetre, config->nbBits);
	}
	fclose(ptr_fic);
}

void fermetureConfig(PTR_CONFIG config){
	if (config->maj == 1){
		sauvegardeConfig(config);
	}
	free(config);
}

int changerTauxSimmilaritude(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if ((nb > 0) && (nb <= 100)){
			config->tauxSim = nb;
			return 1;
		}
	}
	return 0;
}

int recupTauxSimmilaritudeDuConfig(){

	//utilisation d'une fonction generale pour parcourir et avec 2 param recup la bonne ligne

	return 0;
}


void main(void)
{
	PTR_CONFIG config = ouvrirPanneauDeConfiguration();
	fermetureConfig(config);
}