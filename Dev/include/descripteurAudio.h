#ifndef DESCRIPTEURAUDIO_H
#define DESCRIPTEURAUDIO_H
//nbL variable depends de n nombre d'echantillons du'une fenetre parametrable dans le .config



typedef struct s_histo{
	int * histo_fenetre;
	int taille;
	struct s_histo * fenetre_suivante;
} * Histogramme;

typedef struct s_descrpiteurAudio{
	char* identifiant;
	Histogramme histo;	
} * DescrpiteurAudio;

Histogramme init_histo( int );
DescrpiteurAudio init_descripteurAudio(char*);
DescrpiteurAudio IndexationFichierAudio(const char*,int ,int);
void Affiche_DescripteurAudio(DescrpiteurAudio);
void Affiche_histogramme(Histogramme);



#endif 