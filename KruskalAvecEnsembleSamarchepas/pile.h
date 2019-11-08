#ifndef __PILE_H__
#define __PILE_H__

typedef struct pile_type
{
	int* t;
	int taille;
	int capacite;
}pile_t;

pile_t* creerPile(int n);

void detruirepile(pile_t*);

int capacitePile(pile_t*);

int pileVide(pile_t*);

int pilePleine(pile_t*);

void empiler(pile_t* ,int );

int depiler(pile_t*);

int sommet(pile_t*);

void afficherPile(pile_t*);

#endif