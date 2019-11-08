#include "cellule.h"
#include "liste.h"
//Méthode initialisant une cellule à partir d'un entier
cellule_t* initialiserCellule(int valeur , int poids , liste* l){
        cellule_t *cell = malloc(sizeof(*cell));
    if(cell == NULL){
        exit(EXIT_FAILURE);
    }
    cell->pred = NULL;
    cell->succ = NULL;
    cell->valeur = valeur;
    cell->poids = poids;
    cell->pere = l;
    return cell;
}

//Méthode détruisant une cellule
void detruireCellule(cellule_t* cell){
    if(cell == NULL){
        exit(EXIT_FAILURE);
    }

    free(cell);
}
