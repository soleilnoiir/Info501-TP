#include "liste.h"

int main(){
    int valeur1, valeur2, valeur3;

    printf("Tapez 3 valeurs entières à la suite\n");

    scanf("%d",&valeur1);
    scanf("%d",&valeur2);
    scanf("%d",&valeur3);

    cellule_t *cell1 = initialiserCellule(valeur1, 0);
    cellule_t *cell2 = initialiserCellule(valeur2, 5);
    cellule_t *cell3 = initialiserCellule(valeur3, 8);

    //detruireCellule(cell3);

    /*printf("%d", cell1->valeur);
    printf("%d", cell2->valeur);
    printf("%d", cell3->valeur);
    printf("\n");*/

    liste_t *liste = initialiserListe();

    inserer(liste, cell1);
    inserer(liste, cell2);
    inserer(liste, cell3);
    afficherListe(liste);

    supprimer(liste, cell3);
    
    afficherListe(liste);
}
