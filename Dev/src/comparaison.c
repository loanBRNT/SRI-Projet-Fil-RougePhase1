#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/admin.h"
#include "../include/indexation.h"
#include "../include/indexation_txt.h"
#include "../include/img.h"
#include "../include/pile_Img.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"
#include "../include/recherche.h"
#include "../include/comparaison.h"

/* 
 ----------------------- Signature -------------------------
|															|
|		Auteur : BERNAT Loan								|
|		Date de creation : 23/12/21							|
|		Date de derniere MAJ : xx/01/22						|
|															|
 ----------------------------------------------------------- 
 */

// ________________________________________________________________________________________________


void calculSimValeur(double* somme, int fVal1, int fVal2, long* val1, long* val2 ){
    if (fVal1 > fVal2) *(somme) +=  fVal1 - fVal2;
    else *(somme) +=  fVal2 - fVal1;
    *val1 += (long)fVal1;
    *val2 += (long)fVal2;
}

// ________________________________________________________________________________________________

int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* image1, DESCRIPTEUR_IMAGE* image2){
    double taux=0;
    long val1=0, val2=0;
    if (image1->t_max != image2->t_max) return 0;

    if (image1->t_max==0) return -1;

    for (int i = 0 ; i < image1->t_max ; i++){
        calculSimValeur( &taux, image1->histogramme[i], image2->histogramme[i], &val1, &val2);
    }
    
    taux = (taux * -100) / (val1 + val2) + 100;

    return ((int)taux);
}

// ________________________________________________________________________________________________

int comparaisonFichiersAudio(DESCRIPTEUR_AUDIO* jingle, DESCRIPTEUR_AUDIO* corpus, char* chaine_resultat){
    char tab[20];
    int taux = 0;
    float s;
    if (jingle == NULL || corpus == NULL) return 0;
    if (jingle->taille > corpus->taille) return 0;
    Histogramme ptr_JingleHisto = jingle->histo;
    Histogramme ptr_CorpusHisto = corpus->histo;
    for (int i = 0; i < corpus->taille-jingle->taille; ++i)
    {
        if (ptr_CorpusHisto == NULL) break;

        taux = calculSimHisto(ptr_JingleHisto,ptr_CorpusHisto);

        if (taux >= 80){
            taux = verifierSim(ptr_JingleHisto,ptr_CorpusHisto,jingle->taille);
            if (taux >= 80){
                s = calculSeconde(i);
                sprintf(tab,"%f",s);
                strcat(chaine_resultat,tab);
                strcat(chaine_resultat, "s ");
                for (int j = 0 ; j < jingle->taille-1 ; j++){
                    if (ptr_CorpusHisto == NULL) break;
                    ptr_CorpusHisto = ptr_CorpusHisto->fenetre_suivante;
                    i++;
                }
            }
        }
        
        if (ptr_CorpusHisto == NULL) break;
        ptr_CorpusHisto = ptr_CorpusHisto->fenetre_suivante;

    }
    return 0;
}

int calculSimHisto(Histogramme histoJingle, Histogramme histoCorpus){
    double taux=0;
    long val1=0, val2=0;
    if (histoJingle == NULL || histoCorpus == NULL){
        printf("ERREUR\n");
        return 0;
    }

    for (int i = 0 ; i < histoJingle->taille ; i++){
        calculSimValeur( &taux, histoJingle->histo_fenetre[i],histoCorpus->histo_fenetre[i], &val1, &val2);
    }

    taux = (taux * -100) / (val1 + val2) + 100;
    
    return (int)taux;
}

int verifierSim(Histogramme histoJingle, Histogramme histoCorpus, int repetition){
    int taux = 0;
    Histogramme ptr_JingleHisto = histoJingle;
    Histogramme ptr_CorpusHisto = histoCorpus;

    for (int i = 0 ; i < repetition ; i++) {
        taux = taux + calculSimHisto(ptr_JingleHisto,ptr_CorpusHisto);

        if (histoJingle == NULL || histoCorpus == NULL){
            break;
        }
        ptr_JingleHisto = ptr_JingleHisto->fenetre_suivante;
        ptr_CorpusHisto = ptr_CorpusHisto->fenetre_suivante;
    }
    taux = taux / repetition;
    return taux;
}

float calculSeconde(int ligneActuelle){
    int nbPoints = recupNbPointsDuConfig();
    float nouvelleRefLigne = ( ( (float)nbPoints) * 15.8 ) / 1024;
    nouvelleRefLigne = (float)ligneActuelle / nouvelleRefLigne;
    return nouvelleRefLigne;
}

// ________________________________________________________________________________________________