#ifndef ADMIN_H
#define ADMIN_H

typedef struct s_config{
	int tauxSim;
	int nbMotParTxt;
	int seuilOccMot;
	int nbIntervalle;
	int nbFenetre;
	int nbBits;
}*PTR_CONFIG;

//Permet de mettre en memoire
PTR_CONFIG ouvrirPanneauDeConfiguration();

//Permet d'affecter un attribut a sa valeur depuis le .config. 
//Renvoie 0 si le nomAttribut n'est pas reconnu. 1 si l'affectation c'est bien deroule
int affectAttributConfig(PTR_CONFIG config, char* nomAttribut, int valeur);

//Permet de sauvegarder Apres modif
void sauvegarderConfig();

// ---------------- PERMET DE CHANGER DES ATTRIBUTS DU .CONFIG ---------------
//Renvoie un message d'etat.

char* changerTauxSimmilaritude(int taux);

char* changerNbMotParTexte(int nb);

char* changerSeuilOccurenceMot(int nb);

char* changerNbIntervalle(int nb);

char* changerNbFenetre(int nb);

char* changerNbBits(int nb);


//-------------------- ACCESSEUR ---------------------------

#endif