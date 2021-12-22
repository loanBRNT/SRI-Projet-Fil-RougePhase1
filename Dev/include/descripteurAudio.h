#ifndef DESCRIPTEURAUDIO_H
#define DESCRIPTEURAUDIO_H

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 10/12/21                         |
|       Date de derniere MAJ : 17/12/22                     |
|                                                           |
 ----------------------------------------------------------- 
 */


// ------------------- Declaration structure --------------------------------

typedef struct s_histo{
	int * histo_fenetre;
	int taille;
	struct s_histo * fenetre_suivante;
} * Histogramme;

typedef struct s_DescripteurAudio{
	char* identifiant;
	Histogramme histo;	
} * DescripteurAudio;

// ------------------- FONCTION Initialisation --------------------------------

Histogramme init_histo( int );
DescripteurAudio init_descripteurAudio(char*);

// ------------------- FONCTION Affichage --------------------------------

void Affiche_DescripteurAudio(DescripteurAudio);
void Affiche_histogramme(Histogramme);

// -----------------  FONCTIONS Sauvegarde -----------------------

void Sauvegarde_histogramme(Histogramme,FILE*);
void Sauvegarder_DescripteurAudio(DescripteurAudio,FILE*);

// ------------------- FONCTION PRINCIPALE --------------------------------

DescripteurAudio IndexationFichierAudio(const char*,int ,int);

#endif 