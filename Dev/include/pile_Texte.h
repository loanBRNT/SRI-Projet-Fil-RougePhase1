#ifndef PILE_TEXTE_H
#define PILE_TEXTE_H

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 24/12/21                         |
|       Date de derniere MAJ : 29/12/22                     |
|                                                           |
 ----------------------------------------------------------- 
 */


//------------ DEFINITION STRUCT------------------

typedef struct s_celluleT{
	DescripteurTxt Dt;
	struct s_celluleT* next;
} CelluleT;


typedef CelluleT* PILE_Texte;


//----------PROTOTYPE FONCTION-----------------------
PILE_Texte init_PILE_Texte();

void affiche_PILE_Texte(PILE_Texte );

int PILE_Texte_estVide(PILE_Texte );

PILE_Texte emPILE_Texte(PILE_Texte , DescripteurTxt );

PILE_Texte dePILE_Texte(PILE_Texte,FILE*);

PILE_Texte dePILE_Texte_Sans_Sauvegarde(PILE_Texte);

PILE_Texte Charger_Pile_DescripteurTexte(PILE_Texte);

#endif 