#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/admin.h"

/* 
 ----------------------- Signature -------------------------
|															|
|		Auteur : BERNAT Loan								|
|		Date de creation : 10/12/21							|
|		Date de derniere MAJ : 14/12/22						|
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
	} else if (!strcmp(nomAttribut, "nombrePointsAudio")){
		config->nbPoints = valeur;
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

void fermerPanneauDeConfiguration(PTR_CONFIG config){
	if (config->maj == 1){
		sauvegarderConfig(config);
	}
	free(config);
}

void sauvegarderConfig(PTR_CONFIG config){
	FILE * ptr_fic = fopen(".config","w");
	if (ptr_fic == NULL){
		fprintf(stderr, "ERREUR : probleme d'acces a .config");
	} else {
		fprintf(ptr_fic, "tauxSim %d\nnbMaxMotParTexte %d\nseuilOccurenceMot %d\nnombreIntervalleAudio %d\nnombrePointsAudio %d\nnombreBitsQuantification %d",
		config->tauxSim, config->nbMotParTxt, config->seuilOccMot, config->nbIntervalle, config->nbPoints, config->nbBits);
	}
	fclose(ptr_fic);
}

int recupUnAttributConfig(char* nomAttributCible){
	char nomAttribut[30];
	int valeur;
	int continuerBoucle = 1;

	FILE * ptr_fic = fopen(".config","r");
	if (ptr_fic == NULL){
		fprintf(stderr, "ERREUR : probleme d'acces a .config");
		return -1;
	}

	while(continuerBoucle == 1){
		fscanf(ptr_fic, "%s %d",nomAttribut,&valeur);
		if (!strcmp(nomAttribut,nomAttributCible)) {
			continuerBoucle = 0;
		} else if (feof(ptr_fic)){
			continuerBoucle =0;
			valeur = -1;
		}
	}

	fclose(ptr_fic);
	return valeur;
}

char* recupNomRecherche(){
	//char result[500];
    char* nom = malloc(sizeof(char) * 20);
		

	printf("\n");
	printf("Vous avez lancer la recherche par nom\n");
	scanf("%s", nom);
	printf("Vous avez chercher le fichier s'appellant %s \n", nom);
	//lanceRechercheViaNom(nom, result);
	
	return nom;
}

// -----------------  FONCTIONS SET -----------------------

int changerTauxSimmilaritude(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if ((nb > 0) && (nb <= 100)){
			config->tauxSim = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

int changerNbMotParTexte(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if (nb > 0){
			config->nbMotParTxt = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

int changerSeuilOccurence(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if (nb > 0){
			config->seuilOccMot = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

int changerNbIntervalle(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if (nb > 0){
			config->nbIntervalle = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

int changerNbPoints(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if ((nb > 0) && ( (nb & ( nb - 1)) == 0)){ //on test ici si c'est une puissance de 2
			config->nbPoints = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

int changerNbBits(PTR_CONFIG config, int nb){
	if (config != NULL) {
		if ((nb > 0) && (nb < 9)){
			config->nbBits = nb;
			config->maj = 1;
			return 1;
		}
	}
	return 0;
}

// ----------------- FONCTIONS GET ------------------------

int recupTauxSimmilaritudeDuConfig(){
	return recupUnAttributConfig("tauxSim");
}

int recupNbMotsParTexteDuConfig(){
	return recupUnAttributConfig("nbMaxMotParTexte");
}

int recupSeuilOccurenceDuConfig(){
	return recupUnAttributConfig("seuilOccurenceMot");
}

int recupNbIntervalleDuConfig(){
	return recupUnAttributConfig("nombreIntervalleAudio");
}

int recupNbPointsDuConfig(){
	return recupUnAttributConfig("nombrePointsAudio");
}

int recupNbBitsDuConfig(){
	return recupUnAttributConfig("nombreBitsQuantification");
}

int getTauxSimmilaritudeDuConfig(PTR_CONFIG c){
	return c->tauxSim;
}

int getNbMotsParTexteDuConfig(PTR_CONFIG c){
	return c->nbMotParTxt;
}

int getSeuilOccurenceDuConfig(PTR_CONFIG c){
	return c->seuilOccMot;
}

int getNbIntervalleDuConfig(PTR_CONFIG c){
	return c->nbIntervalle;
}

int getNbPointsDuConfig(PTR_CONFIG c){
	return c->nbPoints;
}

int getNbBitsDuConfig(PTR_CONFIG c){
	return c->nbBits;
}