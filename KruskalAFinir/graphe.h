#ifndef _GRAPHE_H_
#define _GRAPHE_H_

#include "liste.h"
#include "cellule.h"
//#include "tas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


typedef struct {
    int sommetOrigine;
    int sommetExtremite;
    int poids;
} arete_t;

typedef struct sommet_type {
    int valeur;
    int couleur;
    int distance;
    int datededebut;
    int datedefin;
    int couvert; //0 = non couvert 1 = couvert
    struct sommet_type* pere;
} sommet_t;

typedef struct {
    int nSommets;
    int oriente;
    int value;
    liste_t** ladj;
    int** madj;
    sommet_t* tSommets;
    arete_t* tAretes;
    int nbAretes;
} graphe_t;

sommet_t creerSommet(int,int);
arete_t creerArete(int,int,int);

liste_t** creerListesAdjacences(char*);
void afficherListeAdjacences (graphe_t);

int** creerMatriceAdjacences(char*);
void afficherMatriceAdjacences(int**, int);

graphe_t creerGraphe(char*);
void detruireGraphe (graphe_t*);
void afficherGraphe(graphe_t*);

void parcoursLargeur(graphe_t, sommet_t*);
void afficherChemin(graphe_t, sommet_t, sommet_t);
void parcoursprofondeurRecursif(graphe_t);
void visiterpp(graphe_t, sommet_t*);
void afficherParcoursProfondeur(graphe_t);

arete_t* creerTableauAretes(char* , int );
arete_t creerArete (int, int, int);
arete_t* triTabArete(arete_t*, int);
void afficherArete(arete_t*, int);

arete_t* Kruskal(graphe_t );
void afficherareteKruskal(graphe_t g);

void generer_acpm_prim_tableau(graphe_t);
#endif
