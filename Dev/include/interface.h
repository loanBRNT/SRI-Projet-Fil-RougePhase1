#ifndef INTERFACE_H
#define INTERFACE_H

// ------------ fonction afffichage des differents menus --------------

void afficheMenuAdmin();
void afficheMenuControleur();

//void afficheErreurMenu(); CETTE FONCTION N'EXISTE PAS

// void afficheMessageQuitter(); CETTE FONCTION N'EXISTE PAS

void afficheMenuPrincipal();
void afficheMenuPointConfig();

// CETTE FONCTION N'EXISTE PAS  : void afficheMessageBienvenue();

void affichageSaisieTauxSim();

// ----------------- LES FONCTIONS POUR MODIFIER LE .CONFIG -------------------

int menuModifierTauxSim(PTR_CONFIG config);


//---------------------- LES FONCTIONS DES MENUS -----------------------


int menuUtilisateur();

int menuAdminVerif();

int menuAdmin();

int menuPointConfig();

#endif