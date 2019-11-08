#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include "liste.h"
#include "graphe.h"
#include "cellule.h"
#include "ensemble.h"

typedef struct ensemble_t
{
    liste_t** liste_sommet;
    cellule_t** point_vers_cellule;
    int taille_liste;
}ensemble_t;

int initialiser_ensemble(ensemble_t*,graphe_t*);
int creer_ensemble(ensemble_t* ,int ;
int trouver_ensemble(ensemble_t*, int );
int union_(ensemble_t*, int , int );
int afficher_ensemble(ensemble_t*);

#endif