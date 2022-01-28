#ifndef COMPARAISON_H
#define COMPARAISON_H 


// ========================= FONCTION DE RECHERCHE ========================

// ------------------------------------------------------------------------
/*
Les fonctions renvoient ici un entier compris entre 0 et 100
0 : TOTALEMENT DIFFERENT
100 : IDENTIQUE
*/

int comparaisonFichiersTexte(DESCRIPTEUR_TEXTE* texte1, DESCRIPTEUR_TEXTE* texte2); //fonction de base qui lance la compraison entre deux textes (renvoie le taux de similarité)


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* Image1, DESCRIPTEUR_IMAGE* Image2); //fonction de base qui lance la comparaison entre image (renvoie le taux de similarité)

// ------------------------------------------------------------------------

//Ecrit dans chaine result les apparitions de l'Audio1 dans Audio2
int comparaisonFichiersAudio(DESCRIPTEUR_AUDIO* Audio1, DESCRIPTEUR_AUDIO* Audio2,char* chaine_result); //ecrit dans chaine_result les s d'apparitions de Audio1 dans Audio2


// ============================================================================

//Fonctions de comparaison entre audio

int calculSimHisto(Histogramme histoJingle, Histogramme histoCorpus);

int verifierSim(Histogramme histoJingle, Histogramme histoCorpus, int repet); //Permet de vérifier que, à partir de la première ligne détecté simillaire, les autres le sont aussi.

// ==========================================================================

float calculSeconde(int ligneActuelle); //calcul la seconde d'apparition du jingle en fonction de sa ligne dans le desc

void calculSimValeur(double* somme, int fVal1, int fVal2, long* val1, long* val2 ); //Ajoute la somme de la différence à som et respectivement fval1 à val1 et fval2 à val2


// ==========================================================================

int nbMotCmmunFichierTexte(DESCRIPTEUR_TEXTE* texte1, DESCRIPTEUR_TEXTE* texte2); //Renvoie le nombre de mot clé en commun des textes.

#endif