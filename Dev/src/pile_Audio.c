#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"

PILE_Audio init_PILE_Audio(){
	PILE_Audio p=(PILE_Audio)malloc(sizeof(struct s_cellule));
	p=NULL;
	return p;
}
void affiche_PILE_Audio(PILE_Audio p){
	Cellule* c = p;
	while(c!=NULL){
		Affiche_DescripteurAudio(c->Da);
		c=c->next;
	}
}

int PILE_Audio_estVide(PILE_Audio p){
	return(p==NULL);
}

PILE_Audio emPILE_Audio(PILE_Audio p, DescripteurAudio e){
	Cellule* cell=(Cellule*)malloc(sizeof(struct s_cellule));
	cell->Da=e;
	cell->next=p;
	p=cell;
	return p;
}

PILE_Audio dePILE_Audio(PILE_Audio p,FILE* f){
	Cellule*c=p;
	Sauvegarder_DescripteurAudio(p->Da,f);
	p=p->next;
	free(c);
	return p;
}

PILE_Audio dePILE_Audio_Sans_Sauvegarde(PILE_Audio p){
	Cellule*c=p;
	p=p->next;
	free(c);
	return p;
}


PILE_Audio Charger_Pile_DescripteurAudio(PILE_Audio PA){
    FILE* f;
    int nbrIntervalle=recupNbIntervalleDuConfig();
    char *lu =(char *) malloc(10*sizeof(char));
    int nbrfen;
    int id;
    f=fopen("../Database/Descripteur/dA.txt","r");
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Audio");
    }
    else{
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            nbrfen=atoi(lu);
            if(!feof(f)){
            	DescripteurAudio DA =LireDescripteurAudio( f,nbrIntervalle,nbrfen,id);
    				PA=emPILE_Audio(PA,DA); 
            }
            
         }
      }
	return PA;

};