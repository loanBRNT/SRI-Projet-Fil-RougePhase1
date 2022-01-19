#ifndef INTERFACE_H
#define INTERFACE_H
#include "admin.h"

// ------------ fonction afffichage des differents menus --------------

void afficheMenuAdmin();
void afficheMenuControleur();
void afficheAccueil();
void afficheErreurMenu();

// void afficheMessageQuitter(); CETTE FONCTION N'EXISTE PAS

void afficheMenuPrincipal();
void afficheMenuPointConfig();

void affichageSaisieTauxSim();
void affichageSaisieNbMot();
void affichageSaisieOccurenceMot();
void affichageSaisieNbIntervalle();
void affichageSaisieNbPoint();
void affichageSaisieNbBits();
void afficheValeurConfig();

// ----------------- LES FONCTIONS POUR MODIFIER LE .CONFIG -------------------

int menuModifierTauxSim(PTR_CONFIG );


int menuModifierNbMaxMot(PTR_CONFIG );

int menuModifierSeuilOccurence(PTR_CONFIG );

int menuModifierNbIntervalle(PTR_CONFIG );

int menuModifierNbPoints(PTR_CONFIG );

int menuModifierNbBits(PTR_CONFIG );

//---------------------- LES FONCTIONS DES MENUS -----------------------
int menuRechercheParMot();

int menuRechercheParNom();

void recupNomRecherche(char* ch);
void recupMotRecherche(char* mt);

int menuRechercheParchemin();

int menuUtilisateur();

int menuAdminVerif();

int menuAdmin();

int menuPointConfig();

#endif