#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/descripteurAudio.h"

Histogramme init_histo(int m){
    Histogramme h=(Histogramme)malloc(sizeof(struct s_histo));
    h->histo_fenetre=(int *)malloc(sizeof(int)*m);
    h->taille=m;
    h->fenetre_suivante=NULL;
    return h;
}

DescrpiteurAudio init_descripteurAudio(char* id){
    DescrpiteurAudio DA=(DescrpiteurAudio)malloc(sizeof(struct s_descrpiteurAudio));
    DA->identifiant=id;
    DA->histo=NULL;  
    return DA;
}

DescrpiteurAudio IndexationFichierAudio( const char* nomfichier,int m,int taille_echantillon){
    FILE* fic ;
    double tailleFic;
    int nombreFenetre;
    double point;
    float taille_intervalle = (float)2/(float)m;
    //fonction pour trouver un ID valable
    char id[5]="A001";
    DescrpiteurAudio DA= init_descripteurAudio(id);
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
    return DA;


}
void Affiche_histogramme(Histogramme h){
    for(int i=0;i<h->taille;i++){
                printf("%d ",h->histo_fenetre[i]);            
            }
            printf("\n");  
}
void Affiche_DescripteurAudio(DescrpiteurAudio DA){
    printf("identifiant unique: %s\n",DA->identifiant);
    Histogramme histo_courant=DA->histo;
    while(histo_courant!=NULL){
        Affiche_histogramme(histo_courant);
        histo_courant=histo_courant->fenetre_suivante;
    }
}
