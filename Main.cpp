#include<iostream>
#include<stdio.h>
#include"Grafo.h"
#include"Aresta.h"
#include<string>
#include<time.h>
#include<stdlib.h>
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
        // if(!fclose(arquivo))
        //     throw string("Problemas no FECHAMENTO do arquivo");
    } catch (string s){
        cout << s << endl;
    }
}

int main(){
    Grafo *grafo = new Grafo(TAMANHO);

    prim *arvore;

    lerArquivo(grafo, "dados.txt");
    
    grafo->setPrim(0);
	arvore = grafo->getPrim();
	cout << "=====ARVORE " << 1 << "=====" << endl;
	for(int i =0; i<TAMANHO; i++){
		cout << i+1 << " " << arvore[i].pai+1 << " " << arvore[i].peso << endl;
	}

    /*grafo->inserirAresta(0,1,2);
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
    grafo->inserirAresta(3,2,5);*/
    
 //    grafo->inserirAresta(0,1,1.1);
 //    grafo->inserirAresta(1,0,1.1);
 //    grafo->inserirAresta(0,2,2.1);
 //    grafo->inserirAresta(2,0,2.1);
 //    grafo->inserirAresta(0,3,1.9);
 //    grafo->inserirAresta(3,0,1.9);
 //    grafo->inserirAresta(0,4,0.9);
 //    grafo->inserirAresta(4,0,0.9);
 //    grafo->inserirAresta(1,2,2.4);
 //    grafo->inserirAresta(2,1,2.4);
 //    grafo->inserirAresta(1,3,3.7);
 //    grafo->inserirAresta(3,1,3.7);
 //    grafo->inserirAresta(1,5,0.5);
 //    grafo->inserirAresta(5,1,0.5);
 //    grafo->inserirAresta(2,4,1.8);
 //    grafo->inserirAresta(4,2,1.8);
 //    grafo->inserirAresta(5,2,1.3);
 //    grafo->inserirAresta(2,5,1.3);
 //    grafo->inserirAresta(3,4,4.0);
 //    grafo->inserirAresta(4,3,4.0);
 //    grafo->inserirAresta(3,5,3.4);
 //    grafo->inserirAresta(5,3,3.4);
 //    grafo->inserirAresta(5,4,0.2);
 //    grafo->inserirAresta(4,5,0.2);
// 
 //    grafo->imprimirMatriz();

	// for(int j = 0; j < TAMANHO; j++){
	// 	grafo->setPrim(j);
	// 	arvore = grafo->getPrim();
	// 	cout << "=====ARVORE " << j+1 << "=====" << endl;
	// 	for(int i =0; i<TAMANHO; i++){
	// 		cout << i+1 << " " << arvore[i].pai+1 << " " << arvore[i].peso << endl;
	// 	}
	// }
	
	
	// 
	// grafo->setPrim(1);
	// arvore = grafo->getPrim();
	// 
	// cout << "=====ARVORE 1=====" << endl;
	// for(int i =0; i<4; i++){
	// 	cout << i << " " << arvore[i].pai << " " << arvore[i].peso << endl;
	// }
	// 
	// grafo->setPrim(2);
	// arvore = grafo->getPrim();
	// 
	// cout << "=====ARVORE 2=====" << endl;
	// for(int i =0; i<4; i++){
	// 	cout << i << " " << arvore[i].pai << " " << arvore[i].peso << endl;
	// }
	// 
	// grafo->setPrim(3);
	// arvore = grafo->getPrim();
	// 
	// cout << "=====ARVORE 3=====" << endl;
	// for(int i =0; i<4; i++){
	// 	cout << i << " " << arvore[i].pai << " " << arvore[i].peso << endl;
	// }
	
    delete grafo;
    
    return 0;
}