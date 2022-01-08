#ifndef COMPARAISON_H
#define COMPARAISON_H 


// ----------------------------- FONCTION SPECIALISE ---------------------------

/*
Les fonctions renvoient ici un entier compris entre 0 et 100
0 : TOTALEMENT DIFFERENT
100 : IDENTIQUE
*/

int comparaisonFichiersTexte(DESCRIPTEUR_TEXTE* texte1, DESCRIPTEUR_TEXTE* texte2);


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* Image1, DESCRIPTEUR_IMAGE* Image2);


int comparaisonFichiersAudio(DESCRIPTEUR_AUDIO* Audio1, DESCRIPTEUR_AUDIO* Audio2,char* chaine_result);


int calculSimHisto(Histogramme histoJingle, Histogramme histoCorpus);



int verifierSim(Histogramme histoJingle, Histogramme histoCorpus, int repet);

float calculSeconde(int ligneActuelle);

int calculSimValeur(int v1, int v2);














#endif