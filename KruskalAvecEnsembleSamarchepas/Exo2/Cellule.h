#ifndef CELLULE_H
#define CELLULE_H
typedef struct Liste Liste;
typedef struct Cellule Cellule;

struct Cellule {
  int id_sommet;
  int poids_extrem;
  Cellule* succ;
  Cellule* pred;
  Liste* chef;
};

int initialiser_cellule(Cellule* c , int id_sommet, int poids_extrem,Liste* l);
int afficher_cellule(Cellule *c);

#endif