#include "pile.h"

int main()
{
	pile_t* p = creerPile(11);
	int i;
	for(i=0;i<10;i++)
	{
		empiler(p,i);

	}
	empiler(p,11);
	afficherPile(p);
	for(i=0;i<10;i++)
	{
		depiler(p);
	}
	depiler(p);
	return(0);
}