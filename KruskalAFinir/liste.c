#include "liste.h"

//Méthode initialisant une liste avec sa première cellule
liste_t* initialiserListe(){
    liste_t* liste = (liste_t*)malloc(sizeof(*liste));
    return liste;
}

//Méthode détruisant une liste
void detruireListe(liste_t* liste){
    cellule_t* temp;
    
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    while(liste->tete != NULL){
        temp = liste->tete;
        liste->tete = liste->tete->succ;
        detruireCellule(temp);
    }

    free(liste);
}

//Méthode insérant une celle dans une liste
void inserer(liste_t* liste, cellule_t* cell){
    if(rechercher(liste, cell->valeur) == NULL){
        cell->succ = liste->tete;
        liste->tete = cell;
    }
}

//Méthode affichant le contenu de la liste
void afficherListe(liste_t* liste){
    cellule_t* temp = liste->tete;

    while(temp != NULL){
        printf("%d", temp->valeur);
        if(temp->succ != NULL){
            printf("->");
        }
        temp = temp->succ;
    }
    printf("\n");
}

//Méthode permettant de rechercher une cellule dans la liste via une valeur
cellule_t* rechercher(liste_t* liste, int valeur){
    cellule_t* temp = NULL;

    if(liste->tete != NULL){

        temp = liste->tete;

        while(temp != NULL && temp->valeur != valeur){
            temp = temp->succ;
        }
    }
    return temp;
}

//Méthode permettant de supprimer une cellule d'une liste
void supprimer(liste_t* liste, cellule_t* cell){
    if(liste->tete != NULL){
        if(rechercher(liste, cell->valeur) != NULL){
            if(cell->pred != NULL){
                cell->pred->succ = cell->succ;
            }else{
                liste->tete = cell->succ;
            }

            if(cell->succ != NULL){
                cell->succ->pred = cell->pred;
            }
            detruireCellule(cell);
        }
    }else{
        exit(EXIT_FAILURE);
    }
}
