#ifndef PILE_IMG_H
#define PILE_IMG_H


typedef struct s_celluleI{
	Descripteur Di;
	struct s_celluleI* next;
} CelluleI;


typedef CelluleI* PILE_Img;

PILE_Img init_PILE_Img();

void affiche_PILE_Img(PILE_Img );

int PILE_Img_estVide(PILE_Img );

PILE_Img emPILE_Img(PILE_Img , Descripteur);

PILE_Img dePILE_Img(PILE_Img,FILE*);

PILE_Img dePILE_Img_Sans_Sauvegarde(PILE_Img );

PILE_Img Charger_Pile_DescripteurImg(PILE_Img );



#endif 