#ifndef ADMIN_H
#define ADMIN_H

typedef struct s_config{
	int tauxSim;
	int nbMotParTxt;
	int seuilOccMot;
	int nbIntervalle;
	int nbFenetre;
	int nbBits;
	int maj; //vaut 0 a chaque ouverture. Et mit a 1 si un des attributs subit un changement.
}*PTR_CONFIG;

//Permet de mettre en memoire
PTR_CONFIG ouvrirPanneauDeConfiguration();

//Permet d'affecter un attribut a sa valeur depuis le .config. 
//Renvoie 0 si le nomAttribut n'est pas reconnu. 1 si l'affectation c'est bien deroule
int affectAttributConfig(PTR_CONFIG config, char* nomAttribut, int valeur);

//Permet de sauvegarder Apres modif
void sauvegarderConfig(PTR_CONFIG config);

//libere l'espace memoire
void fermetureConfig(PTR_CONFIG config);

// ---------------- PERMET DE CHANGER DES ATTRIBUTS DU .CONFIG ---------------
//Renvoie 0 s'il y a eu une erreur, 1 sinon.

int changerTauxSimmilaritude(PTR_CONFIG config, int nb);

int changerNbMotParTexte(PTR_CONFIG config, int nb);

int changerSeuilOccurenceMot(PTR_CONFIG config, int nb);

int changerNbIntervalle(PTR_CONFIG config, int nb);

int changerNbFenetre(PTR_CONFIG config, int nb);

int changerNbBits(PTR_CONFIG config, int nb);


//-------------------- ACCESSEUR ---------------------------

int recupTauxSimmilaritudeDuConfig();

int recupNbMotParTexteDuConfig();

int recupSeuilOccurenceMotDuConfig();

int recupNbIntervalleDuConfig();

int recupNbFenetreDuConfig();

int recupNbBitsDuConfig();

#endif