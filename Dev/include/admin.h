#ifndef ADMIN_H
#define ADMIN_H

typedef struct s_config{
	int tauxSim;
	int nbMotParTxt;
	int seuilOccMot;
	int nbIntervalle;
	int nbPoints;
	int nbBits;
	int maj; //vaut 0 a chaque ouverture. Et mit a 1 si un des attributs subit un changement.
}*PTR_CONFIG;

// ------------------- FONCTION PRINCIPALE --------------------------------

// APPELER LORSQUE L'ON RENTRE DANS LE PANNEAU DE CONFIG DEPUIS L'INTERFACE

//Permet de mettre en memoire
PTR_CONFIG ouvrirPanneauDeConfiguration();

//libere l'espace memoire
void fermerPanneauDeConfiguration(PTR_CONFIG config);

// -------------------------------------------------------------------------



// ============== FONCTION INTERNE (Pas d'appel hors de l'unite) ===============

//Permet d'affecter un attribut a sa valeur depuis le .config. 
//Renvoie 0 si le nomAttribut n'est pas reconnu. 1 si l'affectation c'est bien deroule
int affectAttributConfig(PTR_CONFIG config, char* nomAttribut, int valeur);

//Permet de sauvegarder Apres modif
void sauvegarderConfig(PTR_CONFIG config);

// =============================================================================



// ---------------- PERMET DE CHANGER DES ATTRIBUTS DU .CONFIG ---------------
//Renvoie 0 s'il y a eu une erreur, 1 sinon.

int changerTauxSimmilaritude(PTR_CONFIG config, int nb);

int changerNbMotParTexte(PTR_CONFIG config, int nb);

int changerSeuilOccurence(PTR_CONFIG config, int nb);

int changerNbIntervalle(PTR_CONFIG config, int nb);

int changerNbPoints(PTR_CONFIG config, int nb);

int changerNbBits(PTR_CONFIG config, int nb);

// -----------------------------------------------------------------------------


//--------------------------------- ACCESSEUR ----------------------------------

int recupTauxSimmilaritudeDuConfig();

int recupNbMotParTexteDuConfig();

int recupSeuilOccurenceMotDuConfig();

int recupNbIntervalleDuConfig();

int recupNbPointsDuConfig();

int recupNbBitsDuConfig();

int getTauxSimmilaritudeDuConfig();

int getNbMotsParTexteDuConfig();

int getSeuilOccurenceDuConfig();

int getNbIntervalleDuConfig();

int getNbPointsDuConfig();

int getNbBitsDuConfig();

// ------------------------------------------------------------------------------

#endif