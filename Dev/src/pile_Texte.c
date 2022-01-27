#include <stdio.h>
#include <stdlib.h>
#include "../include/admin.h"
#include "../include/indexation_txt.h"
#include "../include/pile_Texte.h"

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 24/12/21                         |
|       Date de derniere MAJ : 26/01/22                     |
|                                                           |
 ----------------------------------------------------------- 
*/
/*init_PILE_Texte() initialise une pile_texte en mémoire
return la pile initialisée
*/
PILE_Texte init_PILE_Texte(){
	PILE_Texte p=(PILE_Texte)malloc(sizeof(struct s_celluleT));
	p=NULL;
	return p;
}
/* affiche_PILE_Texte(PILE_Texte p) affiche sur le terminal le contenu de la pile p
void affiche_PILE_Texte(PILE_Texte p){
	CelluleI* c = p;
	while(c!=NULL){
		Affiche_DescripteurTexte(c->Di); // NON IMPLEMENTE //
		c=c->next;
	}
}
*/

/* PILE_Texte_estVide(PILE_Texte p) verifie si la pile p vaut NULL 
return 1 si  pile vide 0 sinon */
int PILE_Texte_estVide(PILE_Texte p){
	return(p==NULL);
}

/*emPILE_Texte(PILE_Texte p, Descripteur e) empile le descripteur e sur la pile e */
PILE_Texte emPILE_Texte(PILE_Texte p, DescripteurTxt e){
	CelluleT* cell=(CelluleT*)malloc(sizeof(struct s_celluleT));
	cell->Dt=e;
	cell->next=p;
	p=cell;
	return p;
}

/*dePILE_Texte(PILE_Texte p,FILE* f) depile l'element au sommet de la pile p et le sauvegarde dans le fichier f*/
PILE_Texte dePILE_Texte(PILE_Texte p,FILE* f){
	CelluleT*c=p;
	printDescripteurTxt(p->Dt,f);
	p=p->next;
	free(c);
	return p;
}
/*dePILE_Texte(PILE_Texte p,FILE* f) depile l'element au sommet de la pile p*/
PILE_Texte dePILE_Texte_Sans_Sauvegarde(PILE_Texte p){
	CelluleT*c=p;
	p=p->next;
	free(c);
	return p;
};

/*Charger_Pile_DescripteurTexte(PILE_Texte PT) charge la pile en mémoire a partir du fichier de sauvegarde des descripteurs texte
return la pile chargée*/
PILE_Texte Charger_Pile_DescripteurTexte(PILE_Texte PT){
	FILE* f;
    char *lu =(char *) malloc(30*sizeof(char));
    int nbtermes;
    int nbtokens;
    int id;
     //gestion de l'ouverture du fichier
    f=fopen("./Database/Descripteur/dT.txt","r"); //modif
    if(f==NULL){
         printf("Impossible d'ouvrir le fichier contenant les descripteurs Image"); //modif
    }
    else{
    	//tant qu'on est pas a la fin du fichier on vient lire 3 valeurs l'id puis le nombre de termes et le nombre de tokens present dans le texte
        while(!feof(f)){
            fscanf(f,"%s",lu);
            id=atoi(lu);
            fscanf(f,"%s",lu);
            nbtermes=atoi(lu);
            fscanf(f,"%s",lu);
            nbtokens=atoi(lu);
            if(!feof(f)){
            	DescripteurTxt DT =LireDescripteurTexte( f,id,nbtermes,nbtokens);
            	// on empile le DT dans la pile
    				PT=emPILE_Texte(PT,DT); 
            }
         }
      }
	return PT;

};



