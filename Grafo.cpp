#include"Grafo.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>

using namespace std;

Grafo::Grafo(int v){
    if(v > 0){
        this->numeroVertices = v;
        this->list = new Vertice[v];
    }
    else {
        this->numeroVertices = 0;
        this->list = NULL;
    }
}

int Grafo::linhaVazia(int l){
    return (this->list[l].getFim() == NULL && this->list[l].getInicio() == NULL);
}

int Grafo::inserirAresta(int s, int c, int p){
    Aresta *nova = new Aresta(p);
    if(this->linhaVazia(s)) {
        this->list[s].setFim(nova);
        this->list[s].setInicio(nova);
        return 1;
    }
    this->list[s].getFim()->setProx(nova);
    this->list[s].setFim(nova);
    return 1;  
}

void Grafo::imprimirMatriz(){

    for(int k = 0; k < this->numeroVertices; k++)
        cout << "\t" << k << "\t";
    cout << endl;

    for(int i = 0; i < this->numeroVertices; i++){
        for(int k = 0; k < 16*this->numeroVertices; k++)
            cout << "-";
        cout << endl;
        cout << "|";
        this->list[i].getInicio()->imprime();
        cout << " " << i << endl;
    }
    for(int k = 0; k < 16*this->numeroVertices; k++)
        cout << "-";
    cout << endl;
}

/*Grafo::Grafo(){
    this->vertices = 0;
    //this->matrizAdj = NULL;
}

Grafo::Grafo(int v){
    if(v > 0){
        this->vertices = v;
        this->matrizAdj = new int*[v];
        for(int i = 0; i < v; i++){
            this->matrizAdj[i] = new int[v];
        }
    }
    else {
        this->vertices = 0;
    }
}

Grafo::~Grafo(){
    for(int i = 0; i < this->vertices; i++){
        delete [] this->matrizAdj[i];
    }
    delete [] this->matrizAdj;
}

void Grafo::setVertices(int v){
    if(v > 0) this->vertices = v;
    else this->vertices = 0;
}

int Grafo::getVertices(){
    return this->vertices;
}

void Grafo::imprimirMatriz(){

    for(int k = 0; k < this->vertices; k++)
        cout << "\t" << k << "\t";
    cout << endl;

    for(int i = 0; i < this->vertices; i++){
        for(int k = 0; k < 16*this->vertices; k++)
            cout << "-";
        cout << endl;
        cout << "|";
        for(int j = 0; j < this->vertices; j++){
            cout << "\t" << this->matrizAdj[i][j] << "\t|";
        }
        cout << " " << i << endl;
    }
    for(int k = 0; k < 16*this->vertices; k++)
        cout << "-";
    cout << endl;
}

int Grafo::inserirVertice(int l, int c, int p){
    try{
        if(this->matrizAdj[l][c] != 0)
            throw string("Posicao ja existente");
        this->matrizAdj[l][c] = p;
    }catch(string s){
        cout << s << endl;
        return 0;
    } 
    return 1;    
}*/