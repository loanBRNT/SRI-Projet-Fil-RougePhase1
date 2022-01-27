#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/admin.h"
#include "../include/img.h"
#include "../include/descripteurAudio.h"


/* 
 ----------------------- Signature -------------------------
|                                                           |
|       Auteur : GAUDILLAT Eliott                           |
|       Date de creation : 10/12/21                         |
|       Date de derniere MAJ : 26/01/22                     |
|                                                           |
 ----------------------------------------------------------- 
 */

// -----------------  FONCTIONS initialisation strcuture -----------------------

/* la fonction init_histo initialise un histogramme  de taille m 
 return l'histogramme initialisé */
Histogramme init_histo(int m){
    Histogramme h=(Histogramme)malloc(sizeof(struct s_histo));
    h->histo_fenetre=(int *)malloc(sizeof(int)*m);
    h->taille=m;
    h->fenetre_suivante=NULL;
    return h;
}

/* la fonction init_descripteur audio initialise un descripteur en mémoire
return le descripteur audio initialisé
*/
DescripteurAudio init_descripteurAudio(){
    DescripteurAudio DA=(DescripteurAudio)malloc(sizeof(struct s_DescripteurAudio));
    DA->identifiant=1;
    DA->taille=0;
    DA->histo=NULL;  
    return DA;
}

// -----------------  FONCTIONS Affichage -----------------------

//Affiche_histogramme(Histogramme h) affiche sur le terminal le contenu de l'histogramme h

void Affiche_histogramme(Histogramme h){
    for(int i=0;i<h->taille;i++){
                printf("%d ",h->histo_fenetre[i]);            
            }
            printf("\n");  
}
//Affiche_DescripteurAudio(DescripteurAudio DA) affiche sur le terminal l'indentifant , la taille et l'ensemble des histogrammes du descripteur DA

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

//Sauvegarde_histogramme(Histogramme h,FILE* f) sauvegarde le contenu de l'histogramme h dans le fichier f
void Sauvegarde_histogramme(Histogramme h,FILE* f){
    for(int i=0;i<h->taille;i++){
                fprintf(f,"%d ",h->histo_fenetre[i]);            
            }
            fprintf(f,"\n");  
}

// Sauvegarder_DescripteurAudio(DescripteurAudio DA, FILE* f) sauvegarde l'identifiant , la taille est l'emsemble des histogrammes du descripteur DA dans le fichier f;
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

/* IndexationFichierAudio( const char* nomfichier,int m,int taille_echantillon)  cree le descripteur audio à partir du fichier audio nomfichier , en fonction de :
m : le nombre d'intervalle pour initialiser les histogrammes
taille_echantillon : le nombre de point analysee dans chaque fenetre d'analyse

return le DescripteurAudio cree

*/
DescripteurAudio IndexationFichierAudio( const char* nomfichier,int m,int taille_echantillon){
    FILE* fic ;
    double tailleFic;
    int nombreFenetre;
    double point;
    //valeur comprise entre -1 et 1  on veut un pas uniforme pour nos intervalle donc 2/nombre d'intervalle 
    float taille_intervalle = (float)2/(float)m;
    // initialisation du Descripteur et de l'histogramme courant
    DescripteurAudio DA= init_descripteurAudio();
    Histogramme histo_courant=init_histo(m);
    DA->histo=histo_courant;
    // ouverture du fichier nomfichier en rb car fichier Binaire
    fic = fopen( nomfichier,"rb") ;
    //gestion erreur ouverture
    if ( fic==NULL )
    {
        printf("Ouverture du fichier impossible ! \n");
        exit(0);
    }
    //calcul de la taille du fichier
    fseek(fic,0,SEEK_END);
    tailleFic=ftell(fic); // d recupere la taille du fichier binaire en octet
    fseek(fic,0,SEEK_SET);
    // calcul du nombre de fenetre d'analyse en tenant compte de la taille du fichier et taille_echantillon qui correspond au nombre de point qu'on souhaite avoir par fenetre d'analyse
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
        // tant que le nombre de fenetre traité ne correponds pas au nombre de fenetre total on rajoute  un histogramme pour la fenetre suivante.
       if(j<nombreFenetre-1){
        Histogramme nextHisto=init_histo(m);
        histo_courant->fenetre_suivante=nextHisto;
        histo_courant=nextHisto;
       } 
    }
    // Fermeture du fichier : //
    fclose( fic ) ;
    // generation de l'id unique de notre descripteur
    DA->identifiant=generationIdUnique(3);  
    return DA;


}


// -----------------  FONCTIONS Chargement -----------------------

/* LireDescripteurAudio( FILE* f,int nbrIntervalle,int nbrFen,int id)
la fonction va mettre en mémoire le descripteur correpondant au fichier associé a id
en lisant dans le fichier f

return DA le descripteur mis en mémoire chargé depuis le fichier f
*/

DescripteurAudio LireDescripteurAudio( FILE* f,int nbrIntervalle,int nbrFen,int id){
    char *lu =(char *) malloc(10*sizeof(char));
    int valeur;
    //initialisation du descripteur de l'histogramme courant
    DescripteurAudio DA=init_descripteurAudio();
    Histogramme histo_courant=init_histo(nbrIntervalle);
    DA->histo=histo_courant;
    // association au attributs de DA  l'Id et le nbrFen lu avant l'appel de la fonction et passé en parametre
    DA->identifiant=id;
    DA->taille=nbrFen;
    // lecture dans le fichier f (ouvert avant appel de LireDescripteurAudio)
         for(int j=0;j<nbrFen;j++){
            for(int i=0;i<nbrIntervalle;i++){
                fscanf(f,"%s",lu);
                //conversion de la chaine de caracteres en int
                 valeur=atoi(lu);
                 //association de la valeur lu a sa place dans l'histogramme
                histo_courant->histo_fenetre[i]=valeur;
              }
              // si le nombre d'histogramme chargé en mémoire est plus petit que le nombre d'histogramme normalement contenu dans le descripteur alors on rajoute un histogramme
              if(j<(DA->taille)-1){
                Histogramme nextHisto=init_histo(nbrIntervalle);
                 histo_courant->fenetre_suivante=nextHisto;
                histo_courant=nextHisto;
            }
        }
    return DA;
}

