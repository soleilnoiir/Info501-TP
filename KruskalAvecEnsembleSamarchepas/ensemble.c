#include "ensemble.h"
#include <stdlib.h>
#include <stdio.h>

int initialiser_ensemble(ensemble_t* ens,graphe_t* g){
    ens->liste_sommet = (liste_t**) malloc(sizeof(liste_t*)* g->nSommets);
    ens->point_vers_cellule = (cellule_t **)malloc(sizeof(cellule_t *) * g->nSommets);
    ens->taille_liste = g->nSommets;

    return 0;
}

int creer_ensemble(ensemble_t* ens,int x){

    //On initialise la liste chaine a l'indice de x
    ens->liste_sommet[x] = (liste_t*) malloc(sizeof(liste_t));
    initialiser_liste(ens->liste_sommet[x]);

    ens->point_vers_cellule[x] = (cellule_t *)malloc(sizeof(cellule_t));
    cellule_t* cell = (cellule_t*) malloc(sizeof(cellule_t));
    initialiser_cellule( x, 0, ens->liste_sommet[x]);

    ens->point_vers_cellule[x] = cell;

    inserer(ens->liste_sommet[x], cell);

    return 0;
}

int trouver_ensemble(ensemble_t *ens, int id_sommet)
{
    cellule_t *temp = (cellule_t *)malloc(sizeof(cellule_t));
    temp = ens->point_vers_cellule[id_sommet];

    liste_t *liste_temporaire = temp->pere;
    temp = liste_temporaire->tete;

    return temp->valeur;
}

int union_(ensemble_t *ens, int x, int y)
{
    cellule_t *cellule_temp = (cellule_t *)malloc(sizeof(cellule_t));

    cellule_t *temp1 = (cellule_t *)malloc(sizeof(cellule_t));
    cellule_t *temp2 = (cellule_t *)malloc(sizeof(cellule_t));
    liste_t *templ1 = (liste_t *)malloc(sizeof(liste_t));
    liste_t *templ2 = (liste_t *)malloc(sizeof(liste_t));

    temp1 = ens->point_vers_cellule[x];
    temp2 = ens->point_vers_cellule[y];

    if (temp1->pere->tete->valeur != temp2->pere->tete->valeur)
    {
        templ1 = temp1->pere;
        templ2 = temp2->pere;

        templ1->queue->succ = templ2->tete;
        templ1->queue = templ2->queue;

        cellule_temp = templ2->tete;
        while (cellule_temp->succ != NULL)
        {
            cellule_temp->pere = temp1->pere; 
            cellule_temp = cellule_temp->succ;
        }
        cellule_temp->pere = templ1;
    }
    
    return 0;
}

int afficher_ensemble(ensemble_t *ens)
{
    for (size_t i = 0; i < ens->taille_liste; i++)
    {
        liste_t *listeprov = (liste_t*) malloc(sizeof(liste_t));
        listeprov = ens->liste_sommet[i];
        printf("Chef de la liste %zu = %d \n", i, listeprov->tete->valeur);
        cellule_t *cellprov = (cellule_t *)malloc(sizeof(cellule_t));
        cellprov = listeprov->tete;

        while (cellprov->succ != NULL)
        {
            printf("\tSommet %d \n", cellprov->valeur);
            if (cellprov->succ != NULL)
            {
                cellprov = cellprov->succ;
            }
        }
    }
    
    return 0;
}