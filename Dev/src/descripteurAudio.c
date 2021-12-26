#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/img.h"
#include "../include/descripteurAudio.h"

/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 10/12/21                         |
|       Date de derniere MAJ : 17/12/22                     |
|                                                           |
 ----------------------------------------------------------- 
 */

// -----------------  FONCTIONS initialisation strcuture -----------------------
Histogramme init_histo(int m){
    Histogramme h=(Histogramme)malloc(sizeof(struct s_histo));
    h->histo_fenetre=(int *)malloc(sizeof(int)*m);
    h->taille=m;
    h->fenetre_suivante=NULL;
    return h;
}

DescripteurAudio init_descripteurAudio(){
    DescripteurAudio DA=(DescripteurAudio)malloc(sizeof(struct s_DescripteurAudio));
    //DA->identifiant=generationIdUnique(3);
    DA->identifiant=1;
    DA->taille=0;
    DA->histo=NULL;  
    return DA;
}

// -----------------  FONCTIONS Affichage -----------------------
void Affiche_histogramme(Histogramme h){
    for(int i=0;i<h->taille;i++){
                printf("%d ",h->histo_fenetre[i]);            
            }
            printf("\n");  
}

void Affiche_DescripteurAudio(DescripteurAudio DA){
    printf("identifiant unique: %d\n",DA->identifiant);
    printf("nombre fenetre d analyses: %d\n",DA->taille);
    Histogramme histo_courant=DA->histo;
    while(histo_courant!=NULL){
        Affiche_histogramme(histo_courant);
        histo_courant=histo_courant->fenetre_suivante;
    }
}


// -----------------  FONCTIONS Sauvegarde -----------------------
void Sauvegarde_histogramme(Histogramme h,FILE* f){
    for(int i=0;i<h->taille;i++){
                fprintf(f,"%d ",h->histo_fenetre[i]);            
            }
            fprintf(f,"\n");  
}

void Sauvegarder_DescripteurAudio(DescripteurAudio DA, FILE* f){
    fprintf(f,"%d\n",DA->identifiant);
    fprintf(f,"%d\n",DA->taille);
    Histogramme histo_courant=DA->histo;
    while(histo_courant!=NULL){
        Sauvegarde_histogramme(histo_courant,f);
        histo_courant=histo_courant->fenetre_suivante;
    }
    fprintf(f,"\n");
}


// -----------------  FONCTION Indexation -----------------------
DescripteurAudio IndexationFichierAudio( const char* nomfichier,int m,int taille_echantillon){
    FILE* fic ;
    double tailleFic;
    int nombreFenetre;
    double point;
    float taille_intervalle = (float)2/(float)m;
    DescripteurAudio DA= init_descripteurAudio();
    Histogramme histo_courant=init_histo(m);
    DA->histo=histo_courant;
    fic = fopen( nomfichier,"rb") ;
    if ( fic==NULL )
    {
        printf("Ouverture du fichier impossible ! \n");
        exit(0);
    }
    fseek(fic,0,SEEK_END);
    tailleFic=ftell(fic); // d recupere la taille du fichier binaire en octet
    fseek(fic,0,SEEK_SET);
    nombreFenetre=tailleFic/(8*taille_echantillon);
    DA->taille=nombreFenetre;
    for(int j=0;j<nombreFenetre;j++){
        for(int i=0;i<taille_echantillon;i++){ 
            fread(&point,sizeof(double), 1, fic);
            for(int w=0;w<m;w++){
                if((point>(-1+taille_intervalle*w)) && (point<(-1+taille_intervalle*(w+1)))){
                   histo_courant->histo_fenetre[w]++;   
                }
            }
        }
       if(j<nombreFenetre-1){
        Histogramme nextHisto=init_histo(m);
        histo_courant->fenetre_suivante=nextHisto;
        histo_courant=nextHisto;
       } 
    }
    // Fermeture du fichier : //
    fclose( fic ) ;
    //DA->identifiant=generationIdUnique(3);  devrais etre dans l'initialisation mais bug de generation id
    return DA;


}

