#ifndef __CELLULE_H__
#define __CELLULE_H__

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct cellule_type {
    int valeur;
    struct cellule_type *succ;
    struct cellule_type *pred;
    int poids;
} cellule_t;

cellule_t* initialiserCellule(int, int);
void detruireCellule(cellule_t*);

#endif
