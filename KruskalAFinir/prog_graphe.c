#include "graphe.h"
#include "tas.h"

int main(int argc, char* argv[]){
	if(argc == 2){
		graphe_t graph = creerGraphe(argv[1]);

		afficherGraphe(&graph);

		sommet_t depart = graph.tSommets[0];

		parcoursLargeur(graph, &depart);

		printf("\n");

		for(int i = 0; i < graph.nSommets; i++){
			sommet_t arrive = graph.tSommets[i];
			afficherChemin(graph, depart, arrive);
			printf("\n");
		}

		printf("\n");
		parcoursprofondeurRecursif(graph);
		afficherParcoursProfondeur(graph);

		triTabArete(graph.tAretes, graph.nbAretes);
		afficherArete(graph.tAretes, graph.nbAretes);
		
		Kruskal(graph);
		//triParTas(graph.tAretes, graph.nbAretes);

		detruireGraphe(&graph);

	}else{
		printf("Nombre d'argument insuffisant");
		exit(EXIT_FAILURE);
	}
}
