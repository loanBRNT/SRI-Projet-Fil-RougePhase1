#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/img.h"
#include "../include/pile_Img.h"

PILE_Img init_PILE_Img(){
	PILE_Img p=(PILE_Img)malloc(sizeof(struct s_celluleI));
	p=NULL;
	return p;
}

void affiche_PILE_Img(PILE_Img p){
	CelluleI* c = p;
	while(c!=NULL){
		Affiche_DescripteurImg(c->Di);
		c=c->next;
	}
}

int PILE_Img_estVide(PILE_Img p){
	return(p==NULL);
}

PILE_Img emPILE_Img(PILE_Img p, Descripteur e){
	CelluleI* cell=(CelluleI*)malloc(sizeof(struct s_celluleI));
	cell->Di=e;
	cell->next=p;
	p=cell;
	return p;
}

PILE_Img dePILE_Img(PILE_Img p,FILE* f){
	CelluleI*c=p;
	Sauvegarder_DescripteurImage(p->Di,f);
	p=p->next;
	free(c);
	return p;
}
PILE_Img dePILE_Img_Sans_Sauvegarde(PILE_Img p){
	CelluleI*c=p;
	p=p->next;
	free(c);
	return p;
};

PILE_Img Charger_Pile_DescripteurImg(PILE_Img PI){
	FILE* f;
    char *lu =(char *) malloc(10*sizeof(char));
    int taille;
    int id;
    f=fopen("../Database/Descripteur/dI.txt","r");
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Audio");
    }
    else{
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            taille=atoi(lu);
            if(!feof(f)){
            	Descripteur DI =LireDescripteurImg( f,taille,id);
    				PI=emPILE_Img(PI,DI); 
            }
            
         }
      }
	return PI;

};


