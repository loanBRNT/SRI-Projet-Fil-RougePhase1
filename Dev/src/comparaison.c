#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/admin.h"
#include "../include/indexation.h"
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

//Renvoie le plus petit des taux de similarité des deux valeurs.
int calculSimValeur(int v1, int v2){
    int ecart;
    int max = v2, min=v1;
    if (v1 > v2) {
        max=v1;
        min=v2;
    }

    if (max == 0){
        ecart = 0;
    } else {
        ecart = ((max - min)*100) / max;
    }
    return (100 - ecart);
}


int comparaisonFichiersImage(DESCRIPTEUR_IMAGE* image1, DESCRIPTEUR_IMAGE* image2){
    int nbValeur, tauxSim=0;
    if (image1->t_max != image2->t_max) return 0;

    nbValeur = image1->t_max;
    if (nbValeur==0) return -1;

    for (int i = 0 ; i < nbValeur ; i++){
        tauxSim = tauxSim + calculSimValeur(image1->histogramme[i],image2->histogramme[i]);
    }
    
    tauxSim = tauxSim/nbValeur;

    return (tauxSim);
}

float calculSeconde(int ligneActuelle){
    int nbPoints = recupNbPointsDuConfig();
    float nouvelleRefLigne = ( ( (float)nbPoints) * 15.8 ) / 1024;
    nouvelleRefLigne = (float)ligneActuelle / nouvelleRefLigne;
    return nouvelleRefLigne;
}


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
    if (histoJingle == NULL || histoCorpus == NULL){
        printf("ERREUR\n");
        return 0;
    }
    int taux = 0;
    for (int i = 0 ; i < histoJingle->taille ; i++){
        taux = taux + calculSimValeur(histoJingle->histo_fenetre[i],histoCorpus->histo_fenetre[i]);
    }
    taux = taux / (histoJingle->taille);
    return taux;
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