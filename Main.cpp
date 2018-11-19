#include<iostream>
#include<stdio.h>
#include"Grafo.h"
#include"Aresta.h"
#include<string>
#include<time.h>
#include<stdlib.h>
#include"DisjoinSet.cpp"
#define TAMANHO 150

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
        fclose(arquivo);
         if(!fclose(arquivo))
            throw string("Problemas no FECHAMENTO do arquivo");
    } catch (string s){
        cout << s << endl;
    }
}

int main(){
    Grafo *grafo = new Grafo(TAMANHO);

    prim *arvore;
    //DisjoinSet<Vertice> *arvore2;

    int k, vertice_inicial;

     lerArquivo(grafo, "dados.txt");

    grafo->imprimirGrafo();

    //É MEU AMIGO.. NÃO FUNCIONOU NÃO..
    // grafo->setKruskal();
    // arvore2 = grafo->getKruskal();

	cout << "DIGITE O VÉRTICE INICIAL PARA A ÁRVORE DE PRIM: ";
    cin >> vertice_inicial;

    grafo->setPrim(vertice_inicial-1);
    arvore = grafo->getPrim();
    cout << "=====ARVORE DE PRIM NO VÉRTICE " << vertice_inicial << "=====" << endl;
    cout << "[DESTINO - PAI - PESO]" << endl;
    for(int i =0; i<TAMANHO; i++){
        if(arvore[i].pai == -1 && arvore[i].peso == 0){
            cout << i+1 << " - VÉRTICE INICIAL DA ARVORE"  << endl;
        }else{
            cout << setprecision(15) << i+1 << " " << arvore[i].pai+1 << " " << arvore[i].peso << endl;
        }
    }
	
	
    cout << "DIGITE O NUMERO DE GRUPOS DESEJADO: " ;
    cin >> k;

    grafo->agrupamento(k);

    cout << "===== AGRUPAMENTOS " << "=====" << endl;
    cout << "[DESTINO - PAI - PESO]" << endl;
    for(int i =0; i<TAMANHO; i++){
        if(arvore[i].pai == -1 && arvore[i].peso == 0){
            cout << i+1 << " - VÉRTICE INICIAL DO GRUPO"  << endl;
        }else{
            cout << i+1 << " " << arvore[i].pai+1 << " " << arvore[i].peso << endl;
        }
        
    }
	
    delete grafo;
    
    return 0;
}