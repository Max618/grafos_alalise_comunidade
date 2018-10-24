#include<iostream>
#include"Grafo.h"

using namespace std;

int main(){
    Grafo *grafo = new Grafo(3);

    grafo->inserirAresta(0,1,5);
    grafo->inserirAresta(0,2,3);

    grafo->inserirAresta(1,2,7);
    grafo->inserirAresta(1,0,5);

    grafo->inserirAresta(2,0,3);
    grafo->inserirAresta(2,1,7);

    grafo->imprimirMatriz();
    return 0;
}