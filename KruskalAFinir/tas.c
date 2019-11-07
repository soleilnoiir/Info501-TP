#include "tas.h"

int parent(int indice){
    return (indice-1)/2;
}

int gauche(int indice){
    return indice *2+ 1;
}

int droite(int indice){
    return indice *2+ 2;
}

int permuter (tas_t* t,int indice,int min){
        arete_t tmp;
        tmp = t->aretes[indice];
        t->aretes[indice] = t->aretes[min];
        t->aretes[min] = tmp;
        return min;
}

void entasser_min(tas_t* t,int indice) {
    int left = gauche(indice);
    int right = droite(indice);
    int min = indice;
    
    if (left < t->longueur && t->aretes[left].poids < t->aretes[indice].poids){
        min = left;
    } else { 
        min = indice;
    }
    if (right < t->longueur && t->aretes[right].poids < t->aretes[min].poids){
        min = right;
    }
    if (min != indice){

        permuter(t,indice,min);

        entasser_min(t,min);
    }
    
}

tas_t* construire_tas_min(arete_t* aretes, int tailleTab){
    tas_t* tas = malloc(sizeof(tas_t));
    tas->capacite = tailleTab;
    tas->longueur = tailleTab;
    
    tas->aretes = malloc(sizeof(arete_t)*tailleTab);
    
    tas->aretes = aretes;

    for(int i = tailleTab/2; i >= 0; i--){
     entasser_min(tas,i);
    }

    return tas;
}

void detruireTas(tas_t* tas){
    free(tas->aretes);
    tas->aretes = NULL;
    free(tas);
    tas = NULL;
}

void triParTas(arete_t *aretes, int taille){
    tas_t* tas = construire_tas_min(aretes, taille);
    for(int i = tas->longueur - 1; i >= 1; i--){
        permuter(tas, i, 0);
        tas->longueur--;
        entasser_min(tas,0);      
    } 
    printf("voici le taleau des arretes apres le tri par tas :\n");
    for(int i = 0; i < tas->capacite; i++){
        printf("t[%d] = %d \n",i, tas->aretes[i].poids);
    }
    detruireTas(tas);
}