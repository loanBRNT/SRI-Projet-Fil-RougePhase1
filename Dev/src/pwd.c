#include <stdlib.h>
#include <stdio.h>
#include "pwd.h"

int lire(char* chaine, int longueur ,FILE* fichier){
    char *positionEntree = NULL;
 
    // On lit le texte du fichier
    if (fgets(chaine, longueur, fichier) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        else
            fflush(stdin);
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        fflush(stdin);
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire et pour les nom d'utilisateur
 
    if (lire(nombreTexte, 100,stdin))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

int verifierPwdAdmin(){
    char pwdPropose[20];
    char pwd[30];
    char pwdProposeCrypte[30];
    char loginPropose[20]; //l'identifiant rentrer par l'utilisateur
    char login[20]; //l'identifiant dans le texte
    FILE* id =NULL;
    //demande a l'utilisateur de rentrer son identifiant
    printf("####################################################\n");
    printf("#       veuillez saisir votre identifiant  :       #\n");
    printf("####################################################\n");
    printf("\n");
    lire(loginPropose,20,stdin);// lis le clavier de 20 caractere et mettre dans loginpropose
    fflush(stdin); //il clean le sdin pour que à la prochaine saisie il ne prend pas en compte les float >20
    printf("\n");
    id=fopen("sauv/admin.txt","r"); // id est un pointeur sur fichier
    // verification du l'ouverture du fichier admin.txt qui contient le mot de passe de l administrateur
    if(id == NULL) //si il ne pointe pas sur un fichier alors impossible
    {
        fclose(id);// ne pas oublié de fermé le pointeur sur fichier
        printf("############################################\n");
        printf("# Impossible d'ouvrir le fichier admin.txt #\n");
        printf("############################################\n");
        printf("\n");
        return 1;
    }
    // on recupere l'identifiant dans le fichier controleur.txt correspondant au controleur qui se connecte
    lire(login,20,id);
    /*on compare l identifiant avec l identifiant saisie par l'utilisateur
    si ils ne sont pas identique on affiche un message d'erreur et return une valeur d'erreur
    sinon on continue la verification avec ce coup si le mot de passe 0*/
    if((strcmp(login,loginPropose)) != 0)//strcmp renvoie 0 si la comparaison est bonne
    {
        fclose(id);
        printf("###########################################\n");
        printf("#           identifiant invalide          #\n");
        printf("###########################################\n");
        printf("\n");
        return 1;
    }
    else{
        //demande a l'utilisateur de rentrer son mot de passe
        printf("####################################################\n");
        printf("#       veuillez saisir votre mot de passe :       #\n");
        printf("####################################################\n");
        printf("\n");
        lire(pwdPropose,20,stdin);
        fflush(stdin);
        //crypterVigenere(pwdPropose,pwdProposeCrypte);
        //crypterVigenere(pwdPropose,pwdProposeCrypte);
        printf("\n");
        // on recupere le mot de passe dans le fichier controleur.txt correspondant au controleur qui se connecte
        lire(pwd,30,id);
        /*on compare le mot de passe avec le mot de passe saisie par l'utilisateur
        si ils ne sont pas identique on affiche un message d'erreur et return une valeur d'erreur
        sinon on affiche un message pour informer de la connexion et on return 0*/
        if((strcmp(pwdPropose,pwd)) != 0)//strcmp renvoie 0 si la comparaison est bonne
        {
            fclose(id);
            printf("###########################################\n");
            printf("#       le mot de passe est errone        #\n");
            printf("###########################################\n");
            printf("\n");
            return 1;
        }
        else
        {
            fclose(id);
            printf("#############################################\n");
            printf("# vous etes connecte au menu administrateur #\n");
            printf("#############################################\n");
            printf("\n");
            return 0;
        }
    }
}