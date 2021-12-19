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

// ----------------- LES FONCTIONS POUR MODIFIER LE .CONFIG -------------------

int menuModifierTauxSim(PTR_CONFIG config);


//---------------------- LES FONCTIONS DES MENUS -----------------------
int menuRechercheParMot();

int menuRechercheParNom();

int menuUtilisateur();

int menuAdminVerif();

int menuAdmin();

int menuPointConfig();

#endif