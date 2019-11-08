#ifndef __CELLULE_H__
#define __CELLULE_H__

typedef struct liste_t liste;

typedef struct cellule_type {
    int valeur;
    struct cellule_type *succ;
    struct cellule_type *pred;
    int poids;
    liste* pere; 
} cellule_t;

cellule_t* initialiserCellule(int, int,liste* l);
void detruireCellule(cellule_t*);

#endif
