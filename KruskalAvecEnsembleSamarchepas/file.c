#include "file.h"

file_t* initialiserFile(int taille){
    file_t* file = (file_t*)malloc(sizeof(file_t));
    file->tete = 0;
    file->queue = 0;
    file->taille = taille;
    file->compteur = 0;
    file->tabSommets = (int*)malloc(taille*sizeof(int));
    return file;
}

void detruire_file (file_t* file){
    free(file->tabSommets);
    free(file);
    file->tabSommets = NULL;
    file = NULL;
}

int file_vide(file_t* file){
    int bool = 1;
    
    if(file->tete == file->queue){
        bool = 0;
    }
    return bool;
}

int file_pleine(file_t* file){
    int bool = 1;
    if(file->compteur == file->taille){
        bool = 0;
    }
    return bool;
}

void enfiler(file_t* file, sommet_t sommet){
    if(file_pleine(file) == 1){
        file->tabSommets[file->queue] = sommet.valeur;
        file->compteur++;
        if(file->queue == file->taille){
            file->queue = 0;
        }else{
            file->queue++;
        }
    }else{
        printf("La file est pleine, insertion impossible\n");
    }
}

sommet_t defiler(file_t* file){
    sommet_t sommet;

    if(file_vide(file) == 1){
        sommet.valeur = file->tabSommets[file->tete];
        file->tabSommets[file->tete] = 0;
        file->compteur--;
        if(file->tete == file->taille){
            file->tete = 0;
        }else{
            file->tete++;
        }
    }else{
        printf("La file est vide, impossible de défiler\n");
    }
    return sommet;
}

void afficher_file(file_t* file){
    int i;
    
    for(i = 0; i < file->taille; i++){
        if(i < file->taille-1){
            printf("%d-", file->tabSommets[i]);    
        }else{
            printf("%d", file->tabSommets[i]);
        }
    }
    printf("\n");
}