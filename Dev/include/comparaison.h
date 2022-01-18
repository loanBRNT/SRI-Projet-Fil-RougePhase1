#ifndef COMPARAISON_H
#define COMPARAISON_H 


// ========================= FONCTION DE RECHERCHE ========================

// ------------------------------------------------------------------------
/*
Les fonctions renvoient ici un entier compris entre 0 et 100
0 : TOTALEMENT DIFFERENT
100 : IDENTIQUE
*/

int comparaisonFichiersTexte(DESCRIPTEUR_TEXTE* texte1, DESCRIPTEUR_TEXTE* texte2);


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* Image1, DESCRIPTEUR_IMAGE* Image2);

// ------------------------------------------------------------------------

//Ecrit dans chaine result les apparitions de l'Audio1 dans Audio2
int comparaisonFichiersAudio(DESCRIPTEUR_AUDIO* Audio1, DESCRIPTEUR_AUDIO* Audio2,char* chaine_result);


// ============================================================================

//Fonctions de comparaison entre audio

int calculSimHisto(Histogramme histoJingle, Histogramme histoCorpus);

int verifierSim(Histogramme histoJingle, Histogramme histoCorpus, int repet);

// ==========================================================================

float calculSeconde(int ligneActuelle); //calcul la seconde d'apparition du jingle en fonction de sa ligne dans le desc

void calculSimValeur(double* somme, int fVal1, int fVal2, long* val1, long* val2 );


// ==========================================================================


#endif