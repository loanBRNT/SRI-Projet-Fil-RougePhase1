#ifndef PILE_AUDIO_H
#define PILE_AUDIO_H

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 19/12/21                         |
|       Date de derniere MAJ : 29/12/22                     |
|                                                           |
 ----------------------------------------------------------- 
 */

//------------ DEFINITION STRUCT------------------

typedef struct s_cellule{
	DescripteurAudio Da;
	struct s_cellule* next;
} Cellule;


typedef Cellule* PILE_Audio;

//----------PROTOTYPE FONCTION-----------------------

PILE_Audio init_PILE_Audio();

void affiche_PILE_Audio(PILE_Audio );

int PILE_Audio_estVide(PILE_Audio );

PILE_Audio emPILE_Audio(PILE_Audio , DescripteurAudio );

PILE_Audio dePILE_Audio(PILE_Audio,FILE*);

PILE_Audio dePILE_Audio_Sans_Sauvegarde(PILE_Audio);

PILE_Audio Charger_Pile_DescripteurAudio(PILE_Audio);

#endif 