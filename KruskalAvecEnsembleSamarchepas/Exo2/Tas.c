#include "Tas.h"
#include <stdlib.h>

int parent(int i){
    return ((i-1)/2);
}

int gauche(int i){
    return (2*i)+1;
}

int droite(int i)
{
    return (2 * i)+2;
}

int echanger(Graphe *g, int a, int b)
{
    int temp_extr = g->tableau[a].extremite;
    int temp_or = g->tableau[a].origne;
    int temp_pds = g->tableau[a].poids;

    g->tableau[a].extremite = g->tableau[b].extremite;
    g->tableau[a].origne = g->tableau[b].origne;
    g->tableau[a].poids = g->tableau[b].poids;

    g->tableau[b].extremite = temp_extr;
    g->tableau[b].origne = temp_or;
    g->tableau[b].poids = temp_pds;

    return 0;
}

int entasser_max(Graphe *gr, int indice){
    int d,g,max=0;
    d = droite(indice);
    g = gauche(indice);

    if ((g <= (gr->taille_tri_tas - 1)) && (gr->tableau[indice].poids < gr->tableau[g].poids))
    {
        max = g;
    } else
    {
        max = indice;
    }

    if ((d <= (gr->taille_tri_tas - 1)) && (gr->tableau[d].poids > gr->tableau[max].poids))
    {
        max = d;
    }
    
    if (max != indice )
    {
        echanger(gr,indice,max);
        entasser_max(gr,max);
    }
    
    return 0;
}

int construire_tas_max(Graphe *g){
    int i = 0;
    for ( i = (int) ((g->nb_arete/2)-1); i >= 0 ; i--)
    {
        entasser_max(g,i);
    }
    return 0;
}
