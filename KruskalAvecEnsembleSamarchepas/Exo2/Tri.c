#include "Tri.h"
#include "Graphe.h"
#include <stdio.h>
#include <stdlib.h>


int tri_insertion(Graphe* g)
{
    int clef ,i, save_extr,save_or;

    for (size_t j = 1; j < g->nb_arete; j++)
    {
        clef = g->tableau[j].poids;
        save_extr = g->tableau[j].extremite;
        save_or = g->tableau[j].origne;
        //printf("Clef : %d ,  Extr : %d , Or : %d\n",clef,save_extr,save_or);

        i = j-1;

        while ((i >= 0) && (g->tableau[i].poids > clef))
        {
            g->tableau[i + 1].poids = g->tableau[i].poids;
            g->tableau[i + 1].extremite = g->tableau[i].extremite;
            g->tableau[i + 1].origne = g->tableau[i].origne;

            i = i-1;
        }
        g->tableau[i + 1].poids = clef;
        g->tableau[i + 1].extremite = save_extr;
        g->tableau[i + 1].origne = save_or;
    }
    return 0;
}

int tri_par_tas(Graphe *g){

    construire_tas_max(g);
    int i = 0;
    
    for ( i = ((g->nb_arete) - 1); i > 1; i--)
    {
        echanger(g,i,0);
        g->taille_tri_tas--;
        entasser_max(g, 0);
    }
    
    return 0;
}