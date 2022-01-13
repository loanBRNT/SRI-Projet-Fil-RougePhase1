#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/Texte.h"
#include "../include/pile_Texte.h"

PILE_Texte init_PILE_Texte(){
	PILE_Texte p=(PILE_Texte)malloc(sizeof(struct s_celluleT));
	p=NULL;
	return p;
}

void affiche_PILE_Texte(PILE_Texte p){
	CelluleI* c = p;
	while(c!=NULL){
		Affiche_DescripteurTexte(c->Di);
		c=c->next;
	}
}

int PILE_Texte_estVide(PILE_Texte p){
	return(p==NULL);
}

PILE_Texte emPILE_Texte(PILE_Texte p, Descripteur e){
	CelluleT* cell=(CelluleT*)malloc(sizeof(struct s_celluleI));
	cell->Dt=e;
	cell->next=p;
	p=cell;
	return p;
}

PILE_Texte dePILE_Texte(PILE_Texte p,FILE* f){
	CelluleI*c=p;
	Sauvegarder_DescripteurTexte(p->Dt,f); // a implementer dans descpriteurTexte.txt
	p=p->next;
	free(c);
	return p;
}
PILE_Texte dePILE_Texte_Sans_Sauvegarde(PILE_Texte p){
	CelluleI*c=p;
	p=p->next;
	free(c);
	return p;
};

PILE_Texte Charger_Pile_DescripteurTexte(PILE_Texte PT){
	FILE* f;
    //char *lu =(char *) malloc(10*sizeof(char));
    //int taille;
    int id;
    f=fopen("./Database/Descripteur/dT.txt","r"); //modif
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Image"); //modif
    }
    else{
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);

            //faire la lecture d'un descripteur texte;

            if(!feof(f)){
            	Descripteur DI =LireDescripteurTexte( f,taille,id);
    				PI=emPILE_Texte(PT,DI); 
            }
            
         }
      }
	return PI;

};


