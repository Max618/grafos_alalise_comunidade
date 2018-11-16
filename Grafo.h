#ifndef GRAFO_H
#define GRAFO_H
#include"Vertice.h"
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
        int *arvorePrim;
        int existeBranco();
        int linhaVazia(int);
        void setVerticesBrancos();
    public:
        Grafo(int);
        ~Grafo();

        void imprimirMatriz();
        void inserirAresta(int, int, double);
        //int procurarVertice()

        Vertice* getList();

        void setPrim(int);
        int* getPrim();
};
#endif