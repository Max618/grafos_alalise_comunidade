all: Grafo.o Aresta.o Vertice.o Main.o
	g++ Grafo.o Aresta.o Vertice.o Main.o -o Main.exe

Grafo.o: Grafo.h Grafo.cpp
	g++ -c Grafo.cpp

Aresta.o: Aresta.h Aresta.cpp
	g++ -c Aresta.cpp

Vertice.o: Vertice.h Vertice.cpp
	g++ -c Vertice.cpp

Main.o: Grafo.h Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm Main.exe
