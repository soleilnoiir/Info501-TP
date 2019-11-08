#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include <limits.h>

pile_t* creerPile(int n)
{
	pile_t* p = (pile_t*)malloc(sizeof(pile_t));
	int* t = (int*)malloc(sizeof(int)*n);
	p->t = t;
	p->taille = 0;
	p->capacite = n - 1; 
	return(p);
}

void detruirepile(pile_t* p)
{
	free(p->t);
	free(p);
}

int capacitePile(pile_t *p)
{
	return(p->capacite);
}

int pileVide(pile_t *p)
{
	return(p->taille == 0);
}

int pilePleine(pile_t *p)
{
	return(p->taille == p->capacite - 1);
}

void empiler(pile_t *p, int i)
{
	if(!pilePleine(p))
	{
		p->taille++;
		p->t[p->taille] = i;
	}
	else
	{
		printf("pile pleine ! \n");
	}
}

int depiler(pile_t *p)
{
	int res;
	if(!pileVide(p))
	{
		res = p->taille;
		p->taille--;
	}
	else
	{
		printf("pile vide ! \n");
		res = INT_MIN;
	}
	return(res);
}

int sommet(pile_t *p)
{
	return(p->t[p->taille]);
}

void afficherPile(pile_t *p1)
{
	pile_t* p2 = creerPile(p1->capacite);
	while(!pileVide(p1))
	{
		printf("%d", sommet(p1));
		empiler(p2,depiler(p1));
	}
	while(!pileVide(p2))
	{
		empiler(p1,depiler(p2));
	}
	printf("\n");
}