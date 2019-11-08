#include "Cellule.h"
#include "Liste.h"

#include <stdio.h>
#include <stdlib.h>

int initialiser_cellule(Cellule *c, int id_sommet, int poids_extrem, Liste *l){
c->id_sommet = id_sommet;
c->poids_extrem = poids_extrem;
c->pred = NULL;
c->succ = NULL;
c->chef = l;

return 0;
}

int afficher_cellule(Cellule *c){
    printf("valeur : %d", c->id_sommet );
    
    return 0;
}