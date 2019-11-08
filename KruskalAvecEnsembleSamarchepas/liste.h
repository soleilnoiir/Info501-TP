#ifndef __LISTE_H__
#define __LISTE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cellule.h"


typedef struct {
    cellule_t *tete;
    cellule_t *queue;
} liste_t;

liste_t* initialiserListe();
void detruireListe(liste_t*);
void inserer(liste_t*, cellule_t*);
void afficherListe(liste_t*);
cellule_t* rechercher(liste_t*, int);
void supprimer(liste_t*, cellule_t*);

#endif
