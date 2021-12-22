#ifndef PILE_AUDIO_H
#define PILE_AUDIO_H


typedef struct s_cellule{
	DescripteurAudio Da;
	struct s_cellule* next;
} Cellule;


typedef Cellule* PILE_Audio;

PILE_Audio init_PILE_Audio();

void affiche_PILE_Audio(PILE_Audio );

int PILE_Audio_estVide(PILE_Audio );

PILE_Audio emPILE_Audio(PILE_Audio , DescripteurAudio );

PILE_Audio dePILE_Audio(PILE_Audio,FILE*);


#endif 