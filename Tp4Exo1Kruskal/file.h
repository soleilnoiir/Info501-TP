#ifndef __FILE_H__
#define __FILE_H__

#include "graphe.h"

typedef struct {
    int tete;
    int queue;
    int* tabSommets;
    int taille;
    int compteur;
} file_t;

file_t* initialiserFile(int);
void detruire_file(file_t*);
int file_vide(file_t*);
int file_pleine(file_t*);
void enfiler(file_t*, sommet_t);
sommet_t defiler(file_t*);
void afficher_file(file_t*);

#endif