#ifndef GRAFO_H
#define GRAFO_H
#include"Vertice.h"
#include<stdio.h>

typedef struct sPrim{
	int pai;
	double peso;
}prim;

typedef struct aresta{
	int origem, destino;
	double peso;
	const bool operator<(const aresta &obj)const {
		return (peso < obj.peso);
	}
}aresta;



class Grafo {
/*----------------- File: Grafo.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 19/10/2018|
+-----------------------------------------------------+ */
    private:
        int numeroVertices;
        Vertice *list;
        prim *arvorePrim;
        int existeBranco();
        int linhaVazia(int);
        void setVerticesBrancos();
        void resetArvorePrim();
    public:
        Grafo(int);
        ~Grafo();

        void imprimirMatriz();
        void inserirAresta(int, int, double);
        //int procurarVertice()

        Vertice* getList();

        void setPrim(int);
        prim* getPrim();
};
#endif