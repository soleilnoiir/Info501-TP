#include <stdio.h>
#include <stdlib.h>
#include "Arete.h"
#include "Liste.h"
#include "Cellule.h" 
#include "Graphe.h"
#include "Tri.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    Graphe *test = (Graphe *)malloc(sizeof(Graphe));

    if (argv[1] == NULL)
    {
        printf("Veuillez passer en parametre un fichier txt\n");
    }
    else
    {
        initialiser_graphe(test, argv[1]);
        //afficher_graphe(test);
        printf("\nPar tableau : \n");
        afficher_acpm(test,generer_acpm_kruskal_tableau(test));
        printf("\nPar ensemble : \n");
        afficher_acpm(test, generer_acpm_kruskal_ensembles(test));

        detruire_graphe(test);
    }

    free(test);

    test = NULL;

    return 0;
}
