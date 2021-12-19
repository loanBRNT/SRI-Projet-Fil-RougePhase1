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

typedef struct s_descrpiteurAudio{
	char* identifiant;
	Histogramme histo;	
} * DescrpiteurAudio;

// ------------------- FONCTION Initialisation --------------------------------
Histogramme init_histo( int );
DescrpiteurAudio init_descripteurAudio(char*);
// ------------------- FONCTION Affichage --------------------------------
void Affiche_DescripteurAudio(DescrpiteurAudio);
void Affiche_histogramme(Histogramme);
// ------------------- FONCTION PRINCIPALE --------------------------------
DescrpiteurAudio IndexationFichierAudio(const char*,int ,int);

#endif 