#include <stdio.h>
#include <stdlib.h>
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
