#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/descripteurAudio.h"
#include "../include/pile_Audio.h"

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 19/12/21                         |
|       Date de derniere MAJ : 26/01/22                     |
|                                                           |
 ----------------------------------------------------------- 
*/

/*init_PILE_Audio() initialise une pile_audio en mémoire
return la pile initialisée
*/
PILE_Audio init_PILE_Audio(){
	PILE_Audio p=(PILE_Audio)malloc(sizeof(struct s_cellule));
	p=NULL;
	return p;
}
 /* affiche_PILE_Audio(PILE_Audio p) affiche sur le terminal le contenu de la pile p
 */

void affiche_PILE_Audio(PILE_Audio p){
	Cellule* c = p;
	while(c!=NULL){
		Affiche_DescripteurAudio(c->Da);
		c=c->next;
	}
}

/* PILE_Audio_estVide(PILE_Audio p) verifie si la pile p vaut NULL 
return 1 si  pile vide 0 sinon */
int PILE_Audio_estVide(PILE_Audio p){
	return(p==NULL);
}
/*emPILE_Audio(PILE_Audio p, DescripteurAudio e) empile le descripteur e sur la pile e */
PILE_Audio emPILE_Audio(PILE_Audio p, DescripteurAudio e){
	Cellule* cell=(Cellule*)malloc(sizeof(struct s_cellule));
	cell->Da=e;
	cell->next=p;
	p=cell;
	return p;
}
/*dePILE_Audio(PILE_Audio p,FILE* f) depile l'element au sommet de la pile p et le sauvegarde dans le fichier f*/
PILE_Audio dePILE_Audio(PILE_Audio p,FILE* f){
	Cellule*c=p;
	//appel de la fonction sauvegarder_DescirpteurAudio afin de sauver le descripteur retirer
	Sauvegarder_DescripteurAudio(p->Da,f);
	p=p->next;
	//liberation memoire
	free(c);
	return p;
}
/* dePILE_Audio_Sans_Sauvegarde(PILE_Audio p) depile l'element au sommet de la pile */
PILE_Audio dePILE_Audio_Sans_Sauvegarde(PILE_Audio p){
	Cellule*c=p;
	p=p->next;
	// liberation memoire
	free(c);
	return p;
}

/*Charger_Pile_DescripteurAudio(PILE_Audio PA) charge la pile en mémoire a partir du fichier de sauvegarde des descripteurs audio
return la pile chargée*/
PILE_Audio Charger_Pile_DescripteurAudio(PILE_Audio PA){
    FILE* f;
    int nbrIntervalle=recupNbIntervalleDuConfig();
    char *lu =(char *) malloc(10*sizeof(char));
    int nbrfen;
    int id;
    //gestion de l'ouverture du fichier
    f=fopen("./Database/Descripteur/dA.txt","r");
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Audio");
    }
    else{
    	//tant qu'on est pas a la fin du fichier on vient lire 2 valeurs l'id puis le nombre de fenetre d'un descripteur
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            nbrfen=atoi(lu);
            if(!feof(f)){
            	// on appelle la fonction lireDescritpeurAudio pour charger les histogramme du fichier avec id et nbrfen .
            	DescripteurAudio DA =LireDescripteurAudio( f,nbrIntervalle,nbrfen,id);
            	// on empile le DA dans la pile
    				PA=emPILE_Audio(PA,DA); 
            }
            
         }
      }
	return PA;

};