#include "tas.h"
#include "graphe.h"

int main(){
    arete_t arete = creerArete(0, 1, 1);
    arete_t arete2 = creerArete(0, 2, 5);
    arete_t arete3 = creerArete(1, 3, 9);
    arete_t arete4 = creerArete(2, 4, 6);
    arete_t arete5 = creerArete(3, 4, 7);
    arete_t arete6 = creerArete(3, 0, 3);
    arete_t arete7 = creerArete(4, 2, 2);

    arete_t* aretes = malloc(sizeof(arete_t) * 7);

    aretes[0] = arete;
    aretes[1] = arete2;
    aretes[2] = arete3;
    aretes[3] = arete4;
    aretes[4] = arete5;
    aretes[5] = arete6;
    aretes[6] = arete7;
    int taille = 7;

    triParTas(aretes,taille);  // Donc il faut donner en parametre le tableau d'aretes ainsi que la taille du tableau.
    
    return 0;
}