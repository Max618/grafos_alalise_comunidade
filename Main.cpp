#include<iostream>
#include<stdio.h>
#include"Grafo.h"
#include"Aresta.h"
#include<string>
#define TAMANHO 4

using namespace std;

void lerArquivo(Grafo *g,const char *nome_arquivo){
    try {
        int origem, destino;
        double peso;
        FILE *arquivo = fopen(nome_arquivo, "r");
        if(nome_arquivo == NULL)
            throw string("Problemas na LEITURA do arquivo");
        while(!feof(arquivo)) {
            fscanf(arquivo, "%d %d %lf", &origem, &destino, &peso);
            if(peso > 0)
                g->inserirAresta(origem-1,destino-1,peso);
        }
        if(!fclose(arquivo))
            throw string("Problemas no FECHAMENTO do arquivo");
    } catch (string s){
        cout << s << endl;
    }
}

int main(){
    Grafo *grafo = new Grafo(TAMANHO);

    int origem, destino, *arvore;
    double peso;

    /*for(int i = 0; i < (TAMANHO*TAMANHO); i++){
        cin >> origem >> destino >> peso;
        //cout << origem << " " << destino << " " << peso << " " << endl;
        grafo->inserirAresta(origem-1,destino-1,peso);
    }*/
    //lerArquivo(grafo, "dados.txt");

    grafo->inserirAresta(0,1,2);
    grafo->inserirAresta(1,0,2);
    grafo->inserirAresta(0,2,1);
    grafo->inserirAresta(2,0,1);
    grafo->inserirAresta(0,3,6);
    grafo->inserirAresta(3,0,6);
    grafo->inserirAresta(1,2,3);
    grafo->inserirAresta(2,1,3);
    grafo->inserirAresta(1,3,4);
    grafo->inserirAresta(3,1,4);
    grafo->inserirAresta(2,3,5);
    grafo->inserirAresta(3,2,5);

    grafo->imprimirMatriz();

    grafo->setPrim(0);
    arvore = grafo->getPrim();
    cout << "ARVORE: " << endl;
    for(int i = 0; i < 4; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < 4; i++){
        cout << arvore[i] << " ";
    }
    cout << endl;

    grafo->imprimirMatriz();


    delete grafo;
    
    return 0;
}