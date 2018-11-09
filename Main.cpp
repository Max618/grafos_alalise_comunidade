#include<iostream>
#include<stdio.h>
#include"Grafo.h"
#include"Aresta.h"
#define TAMANHO 150

using namespace std;

int main(){
    Grafo *grafo = new Grafo(TAMANHO);

    int origem, destino;
    double peso;

    for(int i = 0; i < (TAMANHO*TAMANHO); i++){
        cin >> origem >> destino >> peso;
        //cout << origem << " " << destino << " " << peso << " " << endl;
        grafo->inserirAresta(origem-1,destino-1,peso);
    }

    grafo->imprimirMatriz();

    delete grafo;
    
    return 0;
}