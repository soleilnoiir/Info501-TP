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

int permuter (tas_t* t,int indice,int max){
        arete_t tmp;
        tmp = t->aretes[indice];
        t->aretes[indice] = t->aretes[max];
        t->aretes[max] = tmp;
        return max;
}

void entasser_max(tas_t* t,int indice) {
    int left = gauche(indice);
    int right = droite(indice);
    int max = indice;

    if (left <= t->longueur-1 && t->aretes[left].poids > t->aretes[indice].poids)
    {max = left;
}
    else{ max = indice;
}
    if (right <= t->longueur-1 && t->aretes[right].poids > t->aretes[max].poids)
    {max = right;
    
    }
    if (max != indice){

        permuter(t,indice,max);

        entasser_max(t,max);
    }
    
}

tas_t* construire_tas_max(arete_t* arete, int tailleTab){
    tas_t* tas = malloc(sizeof(tas_t));
    tas->capacite = tailleTab;
    tas->longueur = tailleTab;
    
    tas->aretes = malloc(sizeof(arete_t)*tailleTab);
    
    tas->aretes = arete;

    for(int i = tailleTab/2; i >= 0; i--){
     entasser_max(tas,i);
    }

    return tas;
}

void detruireTas(tas_t* tas){
    free(tas->aretes);
    tas->aretes = NULL;
    free(tas);
    tas = NULL;
}

void triParTas( arete_t * aretes, int taille){
    arete_t tmp;
    tas_t* tas = construire_tas_max(aretes, taille);
    for(int i = tas->capacite - 1; i >= 0; i--){
        construire_tas_max(tas->aretes,tas->longueur);
        tmp = tas->aretes[i];
        tas->aretes[i] = tas->aretes[0];
        tas->aretes[0] = tmp;
        tas->longueur--;
        entasser_max(tas,tas->longueur);      
    } 
    printf("voici le taleau des arretes apres le tri par tas :\n");
    for(int i = 0; i < 7; i++){
        
        printf("t[%d] = %d \n",i, tas->aretes[i].poids);
    }
    
}