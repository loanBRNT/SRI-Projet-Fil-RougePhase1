#ifndef RECHERCHE_H
#define RECHERCHE_H 

#include "../include/img.h"

typedef struct s_DescripteurAudio DESCRIPTEUR_AUDIO;
typedef Descripteur DESCRIPTEUR_IMAGE;
typedef float DESCRIPTEUR_TEXTE;

typedef PILE_Audio PILE_DESCRIPTEUR_AUDIO;
typedef PILE_Img PILE_DESCRIPTEUR_IMAGE;
typedef DESCRIPTEUR_TEXTE* PILE_DESCRIPTEUR_TEXTE;

/*
Permet d'ouvrir un fichier selon son type
*/
int ouvrirFichier(FILE* fichier);

//---------------------- FONCTION DE RECHERCHE SPECIALISE -------------------------

//Effectue une recherche via un mot cle
PILE_DESCRIPTEUR_TEXTE rechercheTexteParMotCle(char* mot_cle);

//Effectue une recherche via un descripteur de fichier texte
PILE_DESCRIPTEUR_TEXTE rechercheTexteparDescripteur(DESCRIPTEUR_TEXTE descripteur_texte_cible);

//Effectue une recherche via un descripteur de fichier image
PILE_DESCRIPTEUR_IMAGE rechercheImageParDescripteur(DESCRIPTEUR_IMAGE* descripteur_image_cible);

//Effectue une recherche via un descripteur de fichier Audio
PILE_DESCRIPTEUR_AUDIO rechercheAudioParDescripteur(DESCRIPTEUR_AUDIO descripteur_audio_cible);

//----------------------- FONCTION APPELLE DEPUIS L'INTERFACE ----------------------

//Lance une recherche via l'adresse d'un fichier
int lanceRechercheViaAdresse(char* adresse_fichier_cible, char* chaine_resultat);

//Lance une recherche via le nom d'un fichier
int lanceRechercheViaNom(char* nom_fichier_cible, char* chaine_resultat);

//Lance une recherche via le fichier (selectione depuis une liste deroulante)
int lanceRechercheViaSelection(char* id_fichier, char* chaine_resultat);

//Lance une recherche via le fichier (selectione depuis une liste deroulante)
int lanceRechercheViaMotCle(char* mot, char* chaine_resultat);

//----------------------------------------------------------------------------------

int getTypeDuFichierEtChangeLextension(char* nom); //Renvoie 1 pour un Texte, 2 pour Image, 3 pour son, 0 pour une erreur de lecture.

int getTypeDuFichier(char* nom); //Renvoie 1 pour un Texte, 2 pour Image, 3 pour son, 0 pour une erreur de lecture.

void changerExtension(char* actuelleExt, char* nouvelleExt); //Change l'extension pour que les fonctions d'indexation puissent fonctionner

DESCRIPTEUR_IMAGE getDescripteurImageViaPile(char* nom_fichier);

int recupIdDuFic(char* nom_fic, int type);

void recupNomDUFic(int id, int type, char* chaine);

int generationChaineCaracViaPileIMAGE(PILE_DESCRIPTEUR_IMAGE pile, DESCRIPTEUR_IMAGE* ptr_descFic,char* chaine, int type);

#endif