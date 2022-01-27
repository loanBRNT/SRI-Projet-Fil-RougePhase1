#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/img.h"
#include "../include/pile_Img.h"


/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 21/12/21                         |
|       Date de derniere MAJ : 26/01/22                     |
|                                                           |
 ----------------------------------------------------------- 
*/
/*init_PILE_Img() initialise une pile_img en mémoire
return la pile initialisée
*/
PILE_Img init_PILE_Img(){
	PILE_Img p=(PILE_Img)malloc(sizeof(struct s_celluleI));
	p=NULL;
	return p;
}
/*  affiche_PILE_Img(PILE_Img p) affiche sur le terminal le contenu de la  pile p*/
void affiche_PILE_Img(PILE_Img p){
	CelluleI* c = p;
	while(c!=NULL){
		Affiche_DescripteurImg(c->Di);
		c=c->next;
	}
}

/* PILE_Img_estVide(PILE_Img p) verifie si la pile p vaut NULL 
return 1 si  pile vide 0 sinon */
int PILE_Img_estVide(PILE_Img p){
	return(p==NULL);
}

/*emPILE_Img(PILE_Img p, Descripteur e) empile le descripteur e sur la pile e */
PILE_Img emPILE_Img(PILE_Img p, Descripteur e){
	CelluleI* cell=(CelluleI*)malloc(sizeof(struct s_celluleI));
	cell->Di=e;
	cell->next=p;
	p=cell;
	return p;
}

/*dePILE_Img(PILE_Img p,FILE* f) depile l'element au sommet de la pile p et le sauvegarde dans le fichier f*/
PILE_Img dePILE_Img(PILE_Img p,FILE* f){
	CelluleI*c=p;
	Sauvegarder_DescripteurImage(p->Di,f);
	p=p->next;
	free(c);
	return p;
}

/*dePILE_Img(PILE_Img p,FILE* f) depile l'element au sommet de la pile p */
PILE_Img dePILE_Img_Sans_Sauvegarde(PILE_Img p){
	CelluleI*c=p;
	p=p->next;
	free(c);
	return p;
};

/*Charger_Pile_DescripteurImg(PILE_Img PI) charge la pile en mémoire a partir du fichier de sauvegarde des descripteur image
return la pile chargée*/
PILE_Img Charger_Pile_DescripteurImg(PILE_Img PI){
	FILE* f;
    char *lu =(char *) malloc(10*sizeof(char));
    int taille;
    int id;
    //gestion de l'ouverture du fichier
    f=fopen("./Database/Descripteur/dI.txt","r"); //modif
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Image"); //modif
    }
    else{
    	//tant qu'on est pas a la fin du fichier on vient lire 2 valeurs l'id puis la taille d'un descripteur
        while(!feof(f)){
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            taille=atoi(lu);
            if(!feof(f)){
            	Descripteur DI =LireDescripteurImg( f,taille,id);
            	// on empile le DI dans la pile
    				PI=emPILE_Img(PI,DI); 
            }
            
         }
      }
	return PI;

};


