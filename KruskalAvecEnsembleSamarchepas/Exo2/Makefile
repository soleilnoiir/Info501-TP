CC = gcc -Wall -O3
OBJETS = exo.o Cellule.o Liste.o Graphe.o Tri.o Tas.o Ensemble.o

exo : $(OBJETS)
	$(CC) -o exo $(OBJETS)
exo.o : exo.c Cellule.h Liste.h Graphe.h Arete.h
	$(CC) -c exo.c
graphe.o : Graphe.c Graphe.h Cellule.h Liste.h Tri.h Tas.h
	$(CC) -c Graphe.c
ensemble.o : Ensemble.c Ensemble.h Liste.h
	$(CC) -c Ensemble.c
liste.o : Liste.c Liste.h Cellule.h 
	$(CC) -c Liste.c
cellule.o : Cellule.c Cellule.h 
	$(CC) -c Cellule.c
tri.o : Tri.c Tri.h Tas.h
	$(CC) -c Tri.c
tas.o : Tas.c Tas.h
	$(CC) -c Tas.c
clean:
	rm exo $(OBJETS)