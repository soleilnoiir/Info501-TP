#include "Liste.h"
#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

int initialiser_liste(Liste *l){
    l->tete = NULL;
    l->queue = NULL;

    return 0;
}

void afficher_liste(Liste *l){
    Cellule *temp = l->tete;

    if (temp != NULL)
    {
        while (temp->succ != NULL)
        {
            printf("%d/%d ", temp->id_sommet,temp->poids_extrem);
            temp = temp->succ;
        }
        printf("%d/%d ", temp->id_sommet,temp->poids_extrem);
    } else {
        printf("Liste vide");
    }
    printf("\n");
}

int detruire_liste(Liste *l){
    
    while (l->tete->pred == NULL && l->tete->succ == NULL)
    {
        supprimer(l, &l->tete);
    }

    free(l->tete);
    l->tete = NULL;

    return 0;
}

int inserer(Liste *l, Cellule *x){
    if (l->tete == NULL)
    {
        l->tete = x;
        l->queue = x;
        x->pred = NULL;
        x->succ = NULL;
        x->chef = l;
    } else {
        x->pred = l->queue;
        x->succ = NULL;
        l->queue->succ = x;
        l->queue = x;
        x->chef = l;
    }

    return 0;
}


Cellule *rechercher(Liste *l, int id_sommet){
    Cellule *temp = l->tete;

    if(l->tete == NULL){
        return NULL;
    }

    while (temp->succ != NULL)
    {
        if(temp->id_sommet == id_sommet){
            return temp;
        }
        temp = temp->succ;
    }

    return NULL;
}

int supprimer(Liste *l, Cellule **x){
    
    if ((*x)->pred == NULL)
    {
        l->tete = (*x)->succ;
        (*x)->succ->pred = NULL;
        free(*x);
    }
    else if ((*x)->succ == NULL)
    {
        (*x)->pred->succ = NULL;
        free(*x);
    } else {
        (*x)->pred->succ = (*x)->succ;
        (*x)->succ->pred = (*x)->pred;
        free(*x);
    }
    return 0;
}

/*
int supprimer(Liste *l, Cellule **x){
    if ((*x)->pred != NULL)
    {
        (*x)->pred->succ = (*x)->succ;
    } else
    {
        l->tete = (*x)->succ;
    }

    if ((*x)->succ != NULL)
    {
        (*x)->succ->pred = (*x)->pred;
    }
    free(*x);

    return 0;
}*/
