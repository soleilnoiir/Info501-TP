#include "cellule.h"

//Méthode initialisant une cellule à partir d'un entier
cellule_t* initialiserCellule(int valeur , int poids){
        cellule_t *cell = malloc(sizeof(*cell));
    if(cell == NULL){
        exit(EXIT_FAILURE);
    }
    cell->pred = NULL;
    cell->succ = NULL;
    cell->valeur = valeur;
    cell->poids = poids;
    return cell;
}

//Méthode détruisant une cellule
void detruireCellule(cellule_t* cell){
    if(cell == NULL){
        exit(EXIT_FAILURE);
    }

    free(cell);
}
