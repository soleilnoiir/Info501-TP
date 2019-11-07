#include "graphe.h"
#include "file.h"
#include "pile.h"

//Méthode créant un sommet
sommet_t creerSommet(int valeur, int couleur){
    sommet_t s;
    s.valeur = valeur;
    s.distance = 99999;
    s.couleur = couleur;
    s.datededebut = 99999;
    s.datedefin = 99999;
    s.pere = NULL;
    s.couvert = 0;
    return s;
}

//Méthode créant une arête
arete_t creerArete(int origine, int arrive, int poids)
{
    arete_t a;
    a.sommetOrigine = origine;
    a.sommetExtremite = arrive;
    a.poids = poids;
    return a;
}

arete_t* triTabArete(arete_t *tab , int taille){
    arete_t a;
    int i = 0;
    int j = 0;
    for (j = 1; j < taille; j++){
        for (i = 0; i < taille-1; i++){
            if (tab[i].poids > tab[i+1].poids ){ // Si le poid de l'arrete est plus grande que celle d'apres on echange
                a = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = a;
            }
        }
    }
    return tab;
}

//Méthode créant la liste d'adjacence d'un graphe
liste_t** creerListesAdjacences(char* fileName){
    int i, nSommets;
    char str[20];
    int str2 = 0;
    char poids[20];

    FILE* file = fopen(fileName, "r+");
    
    liste_t** liste;

    do{
        fscanf(file, "%s", str);
        if( strcmp("n_sommets", str) == 0 ){
            fscanf(file, "%d", &nSommets);
            liste = (liste_t**)malloc( nSommets*sizeof(liste_t*) );
            for(i =0; i < nSommets; i++){
                liste[i] = initialiserListe();
            }
        }
    }while( strcmp(str, "DEBUT_DEF_ARETES") );

    while( strcmp("FIN_DEF_ARETES", str ) != 0 ){
        fscanf(file, "%s", str);
        if(strcmp("FIN_DEF_ARETES", str) != 0){
            fscanf(file, "%d" "%s", &str2, poids);
            inserer(liste[atoi(str)], initialiserCellule(str2, atoi(poids)));
            inserer(liste[str2], initialiserCellule(atoi(str), atoi(poids)));
        }
    }
    fclose(file);
    return liste;
}

//Méthode affichant la liste d'adjacence d'un graphe
void afficherListesAdjacences(liste_t** l, int taille){
    int i = 0;

    printf("Liste d'adjacences: \n");

    for( i = 0; i < taille; i++){
        printf("%d :", i);
        afficherListe(l[i]);
    }
    printf("\n");
}

//Méthode créant la matrice d'adjacence d'un graphe
int** creerMatriceAdjacences(char* fileName){
    int i, nSommets;
    char str[20];
    int str2 = 0;
    char poids[20];

    FILE* file = fopen(fileName, "r+");
    
    int** matrice;

    do{
        fscanf(file, "%s", str);
        if( strcmp("n_sommets", str) == 0 ){
            fscanf(file, "%d", &nSommets);
            matrice = (int**)malloc( nSommets*sizeof(int*) );
            for(i =0; i<nSommets; i++){
                matrice[i] = (int*)calloc( nSommets, sizeof(int) );
            }
        }
    }while( strcmp(str, "DEBUT_DEF_ARETES") );

    while( strcmp("FIN_DEF_ARETES", str ) != 0 ){
        fscanf(file, "%s", str);
        if(strcmp("FIN_DEF_ARETES", str) != 0){
            fscanf(file, "%d" "%s", &str2, poids);
            matrice[atoi(str)][str2] = atoi(poids);
            matrice[str2][atoi(str)] = atoi(poids);
        }
    }
    fclose(file);
    return matrice;
}

//Méthode affichant la matrice d'adjacence d'un graphe
void afficherMatriceAdjacences(int** matrice, int taille){
    int i = 0;
    int j = 0;

    printf("Matrice d'adjacences: \n");

    for( i = 0; i < taille; i++){
        for( j = 0; j < taille; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Méthode créant un graphe
graphe_t creerGraphe(char* fileName){
    graphe_t graph;
    int i;
    int compteur = 0;

    char str[20];
    char s1[20];
    char s2[20];
    char s3[20];

    FILE* file = fopen(fileName, "r+");
    
    do{
        fscanf(file, "%s", str);
        if(strcmp("n_sommets", str) == 0 ){
            fscanf(file, "%d", &(graph.nSommets));
        }
        if(strcmp("oriente", str) == 0 ){
            fscanf(file, "%d", &(graph.oriente));
        }
        if(strcmp("value", str) == 0 ){
            fscanf(file, "%d", &(graph.value));
        }
    }while( strcmp(str, "DEBUT_DEF_ARETES") );

    if(graph.value == 1){
        while(fscanf(file, "%s %s %s", s1, s2, s3) == 3)
        {
            compteur++;
        }

        graph.nbAretes = compteur;
        graph.tAretes = creerTableauAretes(fileName, compteur);
    }

    graph.ladj = creerListesAdjacences(fileName);
    graph.madj = creerMatriceAdjacences(fileName);
    
    graph.tSommets = (sommet_t*)malloc(graph.nSommets*sizeof(sommet_t));
    
    for(i = 0; i < graph.nSommets; i++){
        graph.tSommets[i] = creerSommet(i, 0);
    }

    return graph;
}

//Méthode détruisant un graphe
void detruireGraphe(graphe_t* graph){
    int i;

    for(i = 0; i < graph->nSommets; i++){ free(graph->madj[i]); }
    for(i = 0; i < graph->nSommets; i++){ detruireListe(graph->ladj[i]); }

    free(graph->tSommets);

    graph->madj = NULL;
    graph->ladj = NULL;
    graph->tSommets = NULL;

    if(graph->value == 1){
        if (graph->tAretes != 0) {free(graph->tAretes);}
    }
    
    graph = NULL;
}

//Méthode affichant toutes les informations d'un graphe
void afficherGraphe(graphe_t* graph){
    int i;
    
    printf("Nombre de sommets: %d\n", graph->nSommets);

    if(graph->oriente == 0){
        printf("Non oriente\n");
    } else {
        printf("Oriente\n");
    }

    if(graph->value == 0){
        printf("Non value\n");
    } else {
        printf("Value\n");
    }    

    afficherListesAdjacences(graph->ladj, graph->nSommets);
    afficherMatriceAdjacences(graph->madj, graph->nSommets);
    
    for(i = 0; i < graph->nSommets; i++){
        printf("%d ", graph->tSommets[i].valeur);
    }
    printf("\n");
}

arete_t* creerTableauAretes(char* c, int cpt)
{
    FILE* f = fopen(c,"r");
    char s[20] = "";
    int  k;

    char s1[20];
    char s2[20];
    char s3[20];
    while(strcmp(s,"DEBUT_DEF_ARETES") != 0)
    {
        fscanf(f, "%s", s);
    }
    arete_t* p = (arete_t*)malloc(cpt*sizeof(arete_t));
    for(k = 0; k < cpt; k++)
    {
        fscanf(f,"%s %s %s", s1, s2, s3);
        p[k] = creerArete(atoi(s1), atoi(s2), atoi(s3));
    }
    fclose(f);
    return(p);
}

void afficherArete(arete_t* a, int taille){
    printf("\n");
    printf("Tableau des aretes : ");

    for(int i = 0; i < taille; i++) {
        printf("\n");
        printf("(%d, %d) : %d  ", a[i].sommetOrigine, a[i].sommetExtremite, a[i].poids);
    }
    printf("\n");
}

void parcoursLargeur(graphe_t graph, sommet_t* origine)
{
    // INITIALISATION
    int i;
    cellule_t* cell;
    sommet_t* defile;
    for(i = 0; i < graph.nSommets; i++)
    {
        graph.tSommets[i].couleur = 0;
        graph.tSommets[i].distance = 99999;
        graph.tSommets[i].pere = NULL;
    }
    origine->couleur = 1;
    origine->distance = 0;
    origine->pere = NULL;
    
    file_t* file = initialiserFile(graph.nSommets);
    
    enfiler(file, *origine);
    
    //DEBUT TRAITEMENT

    while(file_vide(file))
    {
        defile = &graph.tSommets[defiler(file).valeur];
        cell = graph.ladj[defile->valeur]->tete;

        while(cell != NULL)
        {
            sommet_t* tmp = &graph.tSommets[cell->valeur];
            if(tmp->couleur == 0)
            {
                tmp->couleur = 1;
                tmp->distance = defile->distance + 1;
                tmp->pere = defile;
                enfiler(file,*tmp);
            }
            defile->couleur = 2;
            cell = cell->succ;
        }
    }
}

void afficherChemin(graphe_t graph, sommet_t origine, sommet_t arrive)
{
    if(arrive.valeur == origine.valeur)
    {
        printf("Sommets : %d ", origine.valeur);
    }
    else if(arrive.pere == NULL)
    {
        printf("Il n'existe aucun chemin de l'origine a l'arrivée \n");
    }
    else
    {
        afficherChemin(graph, origine, *(arrive.pere));
        printf("%d ", arrive.valeur);
    }
}

void parcoursprofondeurRecursif(graphe_t graph)
{
    int i;
    for(i = 0 ; i < graph.nSommets ; i++)
    {
        graph.tSommets[i].couleur = 0;
        graph.tSommets[i].pere = NULL;
        graph.tSommets[i].datededebut = 0;
    }
    for(i = 0 ; i < graph.nSommets ; i++)
    {
        if(graph.tSommets[i].couleur == 0)
        {
            visiterpp(graph,&graph.tSommets[i]);
        }
    }
}

void visiterpp(graphe_t graph, sommet_t* origine)
{
    static int date = 0;
    date = date + 1;
    origine->datededebut = date;
    origine->couleur = 1;
    cellule_t* cell;
    cell = graph.ladj[origine->valeur]->tete;
    while(cell != NULL)
    {
        sommet_t* som = &graph.tSommets[cell->valeur];
        if(som->couleur == 0) {
            som->pere = origine;
            visiterpp(graph, som);
        }
        cell = cell->succ;
    }
    origine->couleur = 2;
    date = date + 1;
    origine->datedefin = date;

}

void afficherParcoursProfondeur(graphe_t graph)
{
    int i;
    for(i = 0 ; i < graph.nSommets ; i++)
    {
        printf("Sommet : %d, date debut : %d, date fin : %d", i, graph.tSommets[i].datededebut,graph.tSommets[i].datedefin);
        if(graph.tSommets[i].pere == NULL)
        {
            printf(" pere : -1 \n");
        }
        else
        {
            printf(" pere : %d \n", graph.tSommets[i].pere->valeur);
        }
    }
}

arete_t* Kruskal(graphe_t g) {
    int i;
    int IndCC = 0;
    int taille = (g.nSommets-1);
    int compteurarbre = 0;
    int compteurarete = 0;
    arete_t a;
    
    arete_t* tabAcpm = (arete_t*)malloc(taille*sizeof(arete_t));
     
    g.tAretes = triTabArete(g.tAretes, g.nbAretes);
    
    int* tableauconnexe = malloc(g.nSommets * sizeof(int));
    //initialisation du tableau connexe
    for (int i = 0; i < g.nSommets ; ++i)
    {
        tableauconnexe[i] = i;
    }
    while (compteurarbre < g.nSommets -1) {
        a = g.tAretes[compteurarete];
        compteurarete++;
        if (tableauconnexe[a.sommetOrigine] != tableauconnexe[a.sommetExtremite]) {
            tabAcpm[compteurarbre] = a;
            compteurarbre++;
            IndCC = tableauconnexe[a.sommetExtremite];
            for (i = 0; i < g.nSommets; i++) {
                if (tableauconnexe[i] == IndCC) {
                    tableauconnexe[i] = tableauconnexe[a.sommetOrigine];
                }
            }
        }
    }
   
    afficherArete(tabAcpm,g.nSommets-1); 
    return tabAcpm;
}

/*generer_acpm_prim_tableau(graphe_t graph, int valeurDepart){
    int i;
    int j;

    for(i = 0; i < graph.nSommets; i++){
        graph.tSommets[i].distance = 99999;
        graph.tSommets[i].pere = NULL;
        graph.tSommets[i].couvert = 0;
    }
    graph.tSommets[valeurDepart].distance = 0;
    
    for(j = 0; j < graph.nSommets - 1; j++){
        for()
    } 
}*/





