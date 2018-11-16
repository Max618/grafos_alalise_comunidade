#include"Grafo.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>
#include<queue>

using namespace std;

Grafo::Grafo(int v){
    if(v > 0){
        this->numeroVertices = v;
        this->list = new Vertice[v];
        this->arvorePrim = new int[v];
        for(int i = 0; i < v; i++)
            this->arvorePrim[i] = 0;
    }
    else {
        this->numeroVertices = 0;
        this->list = NULL;
        this->arvorePrim = NULL;
    }
}

Grafo::~Grafo(){
    //cout << "Destrutor Grafo...\n";
    delete [] this->list;
    delete [] this->arvorePrim;
}

int Grafo::linhaVazia(int l){
    return (this->list[l].getInicio() == NULL);
}

void Grafo::inserirAresta(int s, int c, double p){
    if(s != c){
        Aresta *nova = new Aresta(p,c);
        this->list[s].inserirOrdenado(nova);
    }
}

Vertice* Grafo::getList(){
    return this->list;
}

void Grafo::imprimirMatriz(){
    cout << "[Origem|Cor] -> [Destino|Peso]" << endl;
    for(int i = 0; i < this->numeroVertices; i++){
        cout << "[" << i+1 << "|" << this->list[i].getCor() << "]";
        this->list[i].getInicio()->imprime();
        cout << endl << endl;
    }
}

int Grafo::existeBranco(){
    for(int i = 0; i < this->numeroVertices; i++) {
        if(this->list[i].getCor() == 'b' || this->list[i].getCor() == 'c')
            return 1;
    }
    return 0;
}

void Grafo::setVerticesBrancos(){
    for(int i = 0; i < this->numeroVertices; i++) {
        this->list[i].setCor('b');
    }
}

void Grafo::setPrim(int vertice_inicial){
    int *vetor_pai, *vetor_peso, contador, vertice_atual = vertice_inicial;
    int vertice_destino, peso_atual;
    for(int i = 0; i < this->numeroVertices; i++){
        vetor_pai[i] = -1;
        vetor_peso[i] = -1;
    }
    vetor_peso[vertice_inicial] = 0;
    this->list[vertice_inicial].setCor('p');
    while(this->existeBranco()){
        contador = -1;
        do{
            contador++;
            vertice_destino = this->list[vertice_atual].getAresta(contador)->getChegada();
            peso_atual = this->list[vertice_atual].getAresta(contador)->getPeso();
        }while(this->list[vertice_atual].getCor() != 'b');
        vetor_pai[vertice_destino] = vertice_atual;
        vetor_peso[vertice_destino] = peso_atual;
        vertice_atual = vertice_destino;
    }
    this->arvorePrim = vetor_pai;
}

int* Grafo::getPrim(){
    return arvorePrim;
}