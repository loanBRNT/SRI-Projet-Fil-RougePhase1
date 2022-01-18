#ifndef PILE_TEXTE_H
#define PILE_TEXTE_H


typedef struct s_celluleT{
	DescripteurTxt Dt;
	struct s_celluleT* next;
} CelluleT;


typedef CelluleT* PILE_Texte;

PILE_Texte init_PILE_Texte();

void affiche_PILE_Texte(PILE_Texte );

int PILE_Texte_estVide(PILE_Texte );

PILE_Texte emPILE_Texte(PILE_Texte , DescripteurTxt );

PILE_Texte dePILE_Texte(PILE_Texte,FILE*);

PILE_Texte dePILE_Texte_Sans_Sauvegarde(PILE_Texte);

PILE_Texte Charger_Pile_DescripteurTexte(PILE_Texte);

#endif 