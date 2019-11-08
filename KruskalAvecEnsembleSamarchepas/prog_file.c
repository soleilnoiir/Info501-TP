#include "file.h"

int main(){
    file_t* file = initialiserFile(3);
    
    afficher_file(file);

    sommet_t som1 = creerSommet(1,0);
    sommet_t som2 = creerSommet(2,0);
    sommet_t som3 = creerSommet(3,0);

    defiler(file);

    enfiler(file,som1);
    enfiler(file,som2);
    enfiler(file,som3);

    afficher_file(file);

    defiler(file);
    defiler(file);

    afficher_file(file);
}