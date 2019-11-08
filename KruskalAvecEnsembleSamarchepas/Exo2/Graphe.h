#ifndef GRAPHE_H
#define GRAPHE_H

#include "Liste.h"
#include "Arete.h"

typedef struct Graphe{
  int n_sommets;
  int oriente;
  int value;
  Liste* l_adj;
  int** m_adj; // 1 seul de tableau de pointeur vers nos valeur du tableau m_stockage
  int* m_stockage; // Tableau de n_sommet * n_sommet , donc 1 seul tableau avec toutes les values
  Arete* tableau; // Tableau de nos arete
  int nb_arete;
  int taille_tri_tas;
} Graphe;

int initialiser_graphe(Graphe *g, char const *nom_fichier);
int afficher_graphe(Graphe* g);
int detruire_graphe(Graphe* g);
int recup_arete(Graphe *g);
int afficher_arete(Graphe *g);
int test_arete(Graphe *g, int arete);
Arete *generer_acpm_kruskal_tableau(Graphe *g);
Arete *generer_acpm_kruskal_ensembles(Graphe *g);
int afficher_acpm(Graphe *g, Arete *a);
#endif