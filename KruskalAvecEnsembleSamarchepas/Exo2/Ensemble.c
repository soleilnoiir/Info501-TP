#include "Ensemble.h"
#include <stdlib.h>
#include <stdio.h>

int initialiser_ensemble(Ensemble* ens,Graphe* g){
    ens->liste_sommet = (Liste**) malloc(sizeof(Liste*)* g->n_sommets);
    ens->point_vers_cellule = (Cellule **)malloc(sizeof(Cellule *) * g->n_sommets);
    ens->taille_liste = g->n_sommets;

    return 0;
}

int creer_ensemble(Ensemble* ens,int x){

    //On initialise la liste chaine a l'indice de x
    ens->liste_sommet[x] = (Liste*) malloc(sizeof(Liste));
    initialiser_liste(ens->liste_sommet[x]);

    ens->point_vers_cellule[x] = (Cellule *)malloc(sizeof(Cellule));
    Cellule* cell = (Cellule*) malloc(sizeof(Cellule));
    initialiser_cellule(cell, x, 0, ens->liste_sommet[x]);

    ens->point_vers_cellule[x] = cell;

    inserer(ens->liste_sommet[x], cell);

    return 0;
}

int trouver_ensemble(Ensemble *ens, int id_sommet)
{
    Cellule *temp = (Cellule *)malloc(sizeof(Cellule));
    temp = ens->point_vers_cellule[id_sommet];

    Liste *liste_temporaire = temp->chef;
    temp = liste_temporaire->tete;

    return temp->id_sommet;
}

int union_(Ensemble *ens, int x, int y)
{
    Cellule *cellule_temp = (Cellule *)malloc(sizeof(Cellule));

    Cellule *temp1 = (Cellule *)malloc(sizeof(Cellule));
    Cellule *temp2 = (Cellule *)malloc(sizeof(Cellule));
    Liste *templ1 = (Liste *)malloc(sizeof(Liste));
    Liste *templ2 = (Liste *)malloc(sizeof(Liste));

    temp1 = ens->point_vers_cellule[x];
    temp2 = ens->point_vers_cellule[y];

    if (temp1->chef->tete->id_sommet != temp2->chef->tete->id_sommet)
    {
        templ1 = temp1->chef;
        templ2 = temp2->chef;

        templ1->queue->succ = templ2->tete;
        templ1->queue = templ2->queue;

        cellule_temp = templ2->tete;
        while (cellule_temp->succ != NULL)
        {
            cellule_temp->chef = temp1->chef; //les chefs de y viennent pointer vers ceux de x
            cellule_temp = cellule_temp->succ;
        }
        cellule_temp->chef = templ1;
    }
    
    return 0;
}

int afficher_ensemble(Ensemble *ens)
{
    for (size_t i = 0; i < ens->taille_liste; i++)
    {
        Liste *listeprov = (Liste*) malloc(sizeof(Liste));
        listeprov = ens->liste_sommet[i];
        printf("Chef de la liste %zu = %d \n", i, listeprov->tete->id_sommet);
        Cellule *cellprov = (Cellule *)malloc(sizeof(Cellule));
        cellprov = listeprov->tete;

        while (cellprov->succ != NULL)
        {
            printf("\tSommet %d \n", cellprov->id_sommet);
            if (cellprov->succ != NULL)
            {
                cellprov = cellprov->succ;
            }
        }
    }
    
    return 0;
}