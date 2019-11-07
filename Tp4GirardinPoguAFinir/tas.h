#ifndef __TAS_H__
#define __TAS_H__

#include "graphe.h"

typedef struct{
    int longueur;
    int capacite;
    arete_t* aretes;
} tas_t;

int parent(int);
int gauche(int);
int droite(int);
void entasser_max(tas_t* ,int);
tas_t* construire_tas_max(arete_t*, int);
void detruireTas(tas_t*);
void triParTas(arete_t*, int);

#endif