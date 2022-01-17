#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/indexation_txt.h"
#include "../include/pile_Texte.h"

PILE_Texte init_PILE_Texte(){
	PILE_Texte p=(PILE_Texte)malloc(sizeof(struct s_celluleT));
	p=NULL;
	return p;
}
/*
void affiche_PILE_Texte(PILE_Texte p){
	CelluleI* c = p;
	while(c!=NULL){
		Affiche_DescripteurTexte(c->Di);
		c=c->next;
	}
}
*/

int PILE_Texte_estVide(PILE_Texte p){
	return(p==NULL);
}

PILE_Texte emPILE_Texte(PILE_Texte p, DescripteurTxt e){
	CelluleT* cell=(CelluleT*)malloc(sizeof(struct s_celluleT));
	cell->Dt=e;
	cell->next=p;
	p=cell;
	return p;
}

PILE_Texte dePILE_Texte(PILE_Texte p,FILE* f){
	CelluleT*c=p;
	printDescripteurTxt(p->Dt,f);
	p=p->next;
	free(c);
	return p;
}
PILE_Texte dePILE_Texte_Sans_Sauvegarde(PILE_Texte p){
	CelluleT*c=p;
	p=p->next;
	free(c);
	return p;
};


PILE_Texte Charger_Pile_DescripteurTexte(PILE_Texte PT){
	FILE* f;
    char *lu =(char *) malloc(30*sizeof(char));
    int nbtermes;
    int nbtokens;
    int id;
    f=fopen("./Database/Descripteur/dT.txt","r"); //modif
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Image"); //modif
    }
    else{
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            nbtermes=atoi(lu);
            fscanf(f,"%s",lu);
            nbtokens=atoi(lu);
            if(!feof(f)){
            	DescripteurTxt DT =LireDescripteurTexte( f,id,nbtermes,nbtokens);
    				PT=emPILE_Texte(PT,DT); 
            }
            
         }
      }
	return PT;

};



