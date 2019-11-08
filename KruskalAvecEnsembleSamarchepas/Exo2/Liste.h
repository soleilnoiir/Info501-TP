#ifndef LISTE_H
#define LISTE_H

#include "Cellule.h"

typedef struct Liste {
  Cellule* tete;
  Cellule* queue;
} Liste;

int initialiser_liste(Liste* l);
int inserer(Liste *l, Cellule *x);
int supprimer(Liste *l, Cellule **x); // Double pointeur pour etre sur de supprimer la cellule
Cellule* rechercher(Liste *l, int id_sommet);
int detruire_liste(Liste *l);
void afficher_liste(Liste *l);

#endif
