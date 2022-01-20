#ifndef RECHERCHE_H
#define RECHERCHE_H 

#include "../include/img.h"

typedef struct s_DescripteurAudio DESCRIPTEUR_AUDIO;
typedef Descripteur DESCRIPTEUR_IMAGE;
typedef DescripteurTxt DESCRIPTEUR_TEXTE;

typedef PILE_Audio PILE_DESCRIPTEUR_AUDIO;
typedef PILE_Img PILE_DESCRIPTEUR_IMAGE;
typedef PILE_Texte PILE_DESCRIPTEUR_TEXTE;

//---------------------- FONCTION DE RECHERCHE SPECIALISE -------------------------

//Effectue une recherche via un mot cle
PILE_DESCRIPTEUR_TEXTE rechercheTexteParMotCle(char* mot_cle);

//Effectue une recherche via un descripteur de fichier texte
PILE_DESCRIPTEUR_TEXTE rechercheTexteParDescripteur(DESCRIPTEUR_TEXTE* descripteur_texte_cible);

//Effectue une recherche via un descripteur de fichier image
PILE_DESCRIPTEUR_IMAGE rechercheImageParDescripteur(DESCRIPTEUR_IMAGE* descripteur_image_cible);

//Effectue une recherche via un descripteur de fichier Audio
PILE_DESCRIPTEUR_AUDIO rechercheAudioParDescripteur(DESCRIPTEUR_AUDIO descripteur_audio_cible);

//Recupere le descripteur associe au fichier Image passe en param
DESCRIPTEUR_IMAGE getDescripteurImageViaPile(char* nom_fichier);

//Recupere le descripteur associe au fichier Audio passe en param
DESCRIPTEUR_AUDIO getDescripteurAudioViaPile(char* nom_fichier);

DESCRIPTEUR_TEXTE getDescripteurTexteViaPile(char* nom_fichier);

//Ecrit dans chaine_resultat les secondes ou apparait le jingle du descfic dans les autres fichiers de la base
int rechercheJingle(DESCRIPTEUR_AUDIO* descFic, char* chaine_resultat);

//Ecrit dans chaine le contenue de la pile passe en param et du descripteur du fichier selon leur type (2,4)
int generationChaineCaracViaPileIMAGE(PILE_DESCRIPTEUR_IMAGE pile, DESCRIPTEUR_IMAGE* ptr_descFic,char* chaine, int type);

int generationChaineCaracViaPileTexte(PILE_DESCRIPTEUR_TEXTE pile, DESCRIPTEUR_TEXTE* ptr_descFic,char* chaine);

//----------------------- FONCTION APPELLE DEPUIS L'INTERFACE ----------------------

//Lance une recherche via l'adresse d'un fichier
int lanceRechercheViaAdresse(char* adresse_fichier_cible, char* chaine_resultat);

//Lance une recherche via le nom d'un fichier
int lanceRechercheViaNom(char* nom_fichier_cible, char* chaine_resultat);

//Lance une recherche via le fichier (selectione depuis une liste deroulante)
int lanceRechercheViaSelection(char* id_fichier, char* chaine_resultat);

//Lance une recherche via le fichier (selectione depuis une liste deroulante)
int lanceRechercheViaMotCle(char* mot, char* chaine_resultat);

//----------------------------- FONCTIONS SECONDAIRES  ------------------------------

int getTypeDuFichierEtChangeLextension(char* nom); //Renvoie 1 pour un Texte, 2 pour Image RGB, 3 pour son, 4 pour Image NB & 0 pour une erreur de lecture. ET Change l'extension selon le type

int getTypeDuFichier(char* nom); //Renvoie 1 pour un Texte, 2 pour Image RGB, 3 pour son, 4 pour Image NB & 0 pour une erreur de lecture.

void changerExtension(char* actuelleExt, char* nouvelleExt); //Remplace l'extension du fichier passe en parametre par celle passe en 2nd param

int recupIdDuFic(char* nom_fic, int type); //Renvoie l'ID du fichier passé en param selon son type (1,2,3,4)

void recupNomDUFic(int id, int type, char* chaine); //Ecrit dans chaine le nom du fichier correspondant à l'ID passe en param selon son type (1,2,3,4)

int ouvertureFichier(char* nom);

#endif