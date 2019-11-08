#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include "Liste.h"
#include "Graphe.h"
#include "Cellule.h"
#include "Ensemble.h"

typedef struct Ensemble
{
    Liste** liste_sommet;
    Cellule** point_vers_cellule;
    int taille_liste;
}Ensemble;

int initialiser_ensemble(Ensemble* ens,Graphe* g);
int creer_ensemble(Ensemble* ens,int x);
int trouver_ensemble(Ensemble *ens, int id_sommet);
int union_(Ensemble *ens, int x, int y);
int afficher_ensemble(Ensemble *ens);

#endif