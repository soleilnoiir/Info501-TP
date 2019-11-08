#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Cellule.h"
#include "Liste.h"
#include "Graphe.h"
#include "Ensemble.h"
#include "Tri.h"

int initialiser_graphe(Graphe *g, char const *nom_fichier)
{
  FILE* fichier = NULL;
  char ch_temp[20];
  int* temp;
  int i,j,k,l;

  if ( (fichier = fopen(nom_fichier, "r")) )
  {
    fscanf(fichier, "%s",ch_temp); // Lit tous les caracteres jusqu'a un espace
    fscanf(fichier, "%d", &g->n_sommets);

    /* Allouer et initialiser les liste d'ajacence et cellules */
    g->l_adj = (Liste *)malloc(g->n_sommets * sizeof(Liste));
    for (k = 0; k < g->n_sommets; k++)
    {
      initialiser_liste(&(g->l_adj[k]));
    }

    /* Allouer et initialiser la matrice d'ajacence */
    g->m_adj = (int **)malloc(g->n_sommets * sizeof(int *));
    g->m_stockage = (int *)malloc((g->n_sommets * g->n_sommets) * sizeof(int));
    for (k = 0; k < g->n_sommets; k++)
    {
      g->m_adj[k] = &(g->m_stockage[k * g->n_sommets]);
    }
  

    fscanf(fichier, "%s", ch_temp);       
    fscanf(fichier, "%d", &g->oriente); 
    fscanf(fichier, "%s", ch_temp);       
    fscanf(fichier, "%d", &g->value);
    fscanf(fichier, "%s", ch_temp); // DEBUT DEF ARETES

    if (!g->oriente)
    {
      if (!strcmp(ch_temp, "DEBUT_DEF_ARETES"))
      {
        while (strcmp(ch_temp, "FIN_DEF_ARETES"))
        {
          fscanf(fichier, "%s", ch_temp); // Lire premier sommet
          if (strcmp(ch_temp, "FIN_DEF_ARETES"))
          {
            i = atoi(ch_temp); // Recupere premiere sommet
            fscanf(fichier, "%s", ch_temp); // Lire deuxieme sommet
            j = atoi(ch_temp); // Recupere deuxieme sommet
            fscanf(fichier, "%s", ch_temp); // Lit le poids
            l = atoi(ch_temp);  // Recupere le poids

            //Créer et Ajouter cellule dans notre liste chainé
            Cellule *c1 = (Cellule *)malloc(sizeof(Cellule));
            initialiser_cellule(c1,j,l,NULL);
            inserer(&(g->l_adj[i]),c1);
            Cellule *c2 = (Cellule *)malloc(sizeof(Cellule));
            initialiser_cellule(c2, i,l,NULL);
            inserer(&(g->l_adj[j]), c2);

            //Matrice adjacence
            temp = g->m_adj[i]; // On recupere le pointeur vers la ligne voulue
            temp[j] = l; // On recupere la case voulu de cette ligne

            temp = g->m_adj[j]; // Meme cas mais inverse
            temp[i] = l;
          }
        }
      }
      
    } else {
      if (!strcmp(ch_temp, "DEBUT_DEF_ARETES"))
      {
        while (strcmp(ch_temp, "FIN_DEF_ARETES"))
        {
          fscanf(fichier, "%s", ch_temp); // Lire premier sommet
          if (strcmp(ch_temp, "FIN_DEF_ARETES"))
          {
            i = atoi(ch_temp);              // Recupere premiere sommet
            fscanf(fichier, "%s", ch_temp); // Lire deuxieme sommet
            j = atoi(ch_temp);              // Recupere deuxieme sommet
            fscanf(fichier, "%s", ch_temp); // Lit le poids
            l = atoi(ch_temp);              // Recupere le poids

            //Créer et Ajouter cellule dans notre liste chainé
            Cellule *c1 = (Cellule *)malloc(sizeof(Cellule));
            initialiser_cellule(c1, j,l,NULL);
            inserer(&(g->l_adj[i]), c1);

            //Matrice adjacence
            temp = g->m_adj[i]; // On recupere le pointeur vers la ligne voulue
            temp[j] = l;        // On recupere la case voulu de cette ligne

          }
        }
      }
    }
  
  }//Fin du if fichier open

  return 0;
}

int afficher_graphe(Graphe *g){
  int i,j;
  printf("Nombre de sommets : %d\n", g->n_sommets);

  if (g->oriente)
  {
    printf("Oriente\n");
  } else
  {
    printf("Non Oriente\n");
  }

  if (g->value)
  {
    printf("Value\n");
  } else
  {
    printf("Non Value\n");
  }

  printf("Listes d'adjacences:\n");

  for (i = 0; i < g->n_sommets; i++)
  {
    printf("%d --> ",i);
    afficher_liste(&(g->l_adj[i]));
  }

  printf("\nMatrice d'adjacences:\n\n");

  for (j = 0; j < (g->n_sommets * g->n_sommets); j++)
  {
    printf("%d\t", g->m_stockage[j]);

    if (!((j+1) % g->n_sommets) && j != 0)
    {
      printf("\n");
    }
  }
  

  return 0;
}

int detruire_graphe(Graphe *g){
  int i;
  if (g->n_sommets != 0)
  {
    for ( i = 0; i < g->n_sommets; i++)
    {
      detruire_liste(&(g->l_adj[i]));
    }
    free(g->m_stockage);
  }

  return 0;
}

int afficher_arete(Graphe *g){
  for (size_t i = 0; i < g->nb_arete; i++)
  {
    printf("Origine : %d\tExtremite : %d\tPoids : %d\n", g->tableau[i].origne, g->tableau[i].extremite, g->tableau[i].poids);
  }
  return 0;
}

int test_arete(Graphe *g ,int arete){
  int boolean = 0;
  for (size_t i = 0; i < g->nb_arete ; i++)
  {
    if (g->tableau[i].origne == arete)
    {
      boolean = 1;
    }
    
  }
  return boolean;
}

int recup_arete(Graphe *g)
{
  Cellule* c = (Cellule *) malloc( sizeof(Cellule));

  int temp = 0;
  int incr = 0;
  for (size_t i = 0; i < g->n_sommets * g->n_sommets; i++)
  {
    if (g->m_stockage[i] != 0)
    {
      temp++;
    }
  }

  if (!(g->oriente))
  {
    temp /= 2;
  }

  g->nb_arete = temp;
  g->taille_tri_tas = temp;

  g->tableau = (Arete*) malloc(temp*sizeof(Arete));
  
  for (size_t i = 0; i < g->n_sommets; i++)
  {
    c = g->l_adj[i].tete;
    // on doit tester a chaque fois qu'il est pas deja dans notre tableau d'arete 
    while (c->succ != NULL)
    {
      if (!test_arete(g, c->id_sommet))
      {
        g->tableau[incr].poids = c->poids_extrem;
        g->tableau[incr].origne = i;
        g->tableau[incr].extremite = c->id_sommet;
        incr++;
      }
      c = c->succ;
    }
    if (!test_arete(g, c->id_sommet))
    {
      g->tableau[incr].poids = c->poids_extrem;
      g->tableau[incr].origne = i;
      g->tableau[incr].extremite = c->id_sommet;
      incr++;
    }

  }

return 0;

}

Arete* generer_acpm_kruskal_tableau(Graphe* g){
  recup_arete(g);
  tri_par_tas(g);
  int cc[g->n_sommets];
  Arete* arbre_couvrant;
  arbre_couvrant = (Arete *)malloc(sizeof(Arete) * (g->n_sommets - 1));
  int iterator = 0;
  int icc;

  for (size_t i = 0; i < g->n_sommets; i++)
  {
    cc[i] = i;
  }

  for (size_t i = 0; i < g->nb_arete; i++)
  {
    if (cc[g->tableau[i].origne] != cc[g->tableau[i].extremite])
    {
      arbre_couvrant[iterator] = g->tableau[i];
      iterator++;
      icc = cc[g->tableau[i].extremite];
      for (size_t j = 0; j < g->n_sommets; j++)
      {
        if (cc[j] == icc)
        {
          cc[j] = cc[g->tableau[i].origne];
        } 
      }
    }
    
  }
  return arbre_couvrant;
}

Arete *generer_acpm_kruskal_ensembles(Graphe *g)
{
  recup_arete(g);
  tri_par_tas(g);
  Ensemble *ens;
  ens = (Ensemble *)malloc(sizeof(Ensemble));
  initialiser_ensemble(ens,g);
  Arete *arbre_couvrant;
  arbre_couvrant = (Arete *)malloc(sizeof(Arete) * (g->n_sommets - 1));
  int iterator = 0;

  for (size_t i = 0; i < g->n_sommets; i++)
  {
    creer_ensemble(ens,i);
  }
  
  for (size_t i = 0; i < g->nb_arete; i++)
  {
    if (trouver_ensemble(ens, g->tableau[i].origne ) != trouver_ensemble(ens, g->tableau[i].extremite ))
    {
      arbre_couvrant[iterator] = g->tableau[i];
      iterator++;
      union_(ens, g->tableau[i].origne, g->tableau[i].extremite);
    }
  }
  return arbre_couvrant;
}

int afficher_acpm(Graphe *g, Arete *a)
{
  int valeur = 0;
  
  for (size_t i = 0; i < (g->n_sommets - 1); i++)
  {
    printf("Arete %zu : \tOrigine : %d \tExtremite : %d\tPoids : %d\n",i,a[i].origne,a[i].extremite,a[i].poids);
    valeur += a[i].poids;
  }
  printf("Le poids total est : %d \n",valeur);
  
  return 0;
}