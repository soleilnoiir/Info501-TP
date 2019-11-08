#ifndef TAS_H
#define TAS_H

#include "Arete.h"
#include "Graphe.h"

int parent(int i);
int droite(int i);
int gauche(int i);
int echanger(Graphe* g, int a, int b);
int entasser_max(Graphe *gr, int indice);
int construire_tas_max(Graphe *g);

#endif

