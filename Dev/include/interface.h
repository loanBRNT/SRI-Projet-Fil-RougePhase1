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

void affichageSaisieTauxSim(PTR_CONFIG config);
void affichageSaisieNbMaxMot(PTR_CONFIG config);
void affichageSaisieSeuilOccurence(PTR_CONFIG config);
void affichageSaisieNbIntervalle(PTR_CONFIG config);
void affichageSaisieNbPoints(PTR_CONFIG config);
void affichageSaisieNbBits(PTR_CONFIG config);

// ----------------- LES FONCTIONS POUR MODIFIER LE .CONFIG -------------------

int menuModifierTauxSim(PTR_CONFIG config);

int menuModifierTauxSim(PTR_CONFIG ptr_sur_config);

int menuModifierNbMaxMot(PTR_CONFIG ptr_sur_config);

int menuModifierSeuilOccurence(PTR_CONFIG ptr_sur_config);

int menuModifierNbIntervalle(PTR_CONFIG ptr_sur_config);

int menuModifierNbPoints(PTR_CONFIG ptr_sur_config);

int menuModifierNbBits(PTR_CONFIG ptr_sur_config);

//---------------------- LES FONCTIONS DES MENUS -----------------------
int menuRechercheParMot();

int menuRechercheParNom();

int menuRechercheParchemin();

int menuUtilisateur();

int menuAdminVerif();

int menuAdmin();

int menuPointConfig();

#endif