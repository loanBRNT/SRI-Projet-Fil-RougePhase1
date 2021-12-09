#ifndef RECHERCHE_H
#define RECHERCHE_H 

typedef DESCRIPTEUR_AUDIO* PILE_DESCRIPTEUR_AUDIO;
typedef DESCRIPTEUR_IMAGE* PILE_DESCRIPTEUR_IMAGE;
typedef DESCRIPTEUR_TEXTE* PILE_DESCRIPTEUR_TEXTE;

/*
Permet d'ouvrir un fichier selon son type
*/
int ouvrirFichier(FILE* fichier);

PILE_DESCRIPTEUR_AUDIO recupPileDescripteurAudio();

PILE_DESCRIPTEUR_TEXTE recupPileDescripteurTexte();

PILE_DESCRIPTEUR_IMAGE recupPileDescripteurImage();

//---------------------- FONCTION DE RECHERCHE SPECIALISE -------------------------

//Effectue une recherche via un mot cle
PILE_DESCRIPTEUR_TEXTE rechercheTexteParMotCle(char* mot_cle);

//Effectue une recherche via un descripteur de fichier texte
PILE_DESCRIPTEUR_TEXTE rechercheTexteparDescripteur(DESCRIPTEUR_TEXTE descripteur_texte_cible);

//Effectue une recherche via un descripteur de fichier image
PILE_DESCRIPTEUR_IMAGE rechercheImageParDescripteur(DESCRIPTEUR_IMAGE descripteur_image_cible);

//Effectue une recherche via un descripteur de fichier Audio
PILE_DESCRIPTEUR_AUDIO rechercheAudioParDescripteur(DESCRIPTEUR_AUDIO descripteur_audio_cible);


//----------------------- FONCTION APPELLE DEPUIS L'INTERFACE ----------------------

//Lance une recherche via l'adresse d'un fichier
char* lanceRechercheViaAdresse(char* adresse_fichier_cible);

//Lance une recherche via le nom d'un fichier
char* lanceRechercheViaNom(char* nom_fichier_cible);

//Lance une recherche via le fichier (selectione depuis une liste deroulante)
char* lanceRechercheViaSelection(char* id_fichier);

//----------------------------------------------------------------------------------

#endif