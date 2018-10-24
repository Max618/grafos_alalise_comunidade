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
    public:
        Grafo(int);
        ~Grafo();

        void imprimirMatriz();
        int inserirAresta(int, int, float);
        int linhaVazia(int);
        //int procurarVertice()
};
#endif