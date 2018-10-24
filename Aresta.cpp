#include"Aresta.h"
#include<iostream>

using namespace std;

Aresta::Aresta(int p){
    this->peso = p;
    this->prox = NULL;
}

Aresta::Aresta(){
    this->peso = -1;
    this->prox = NULL;
}

void Aresta::setPeso(int p){
    this->peso = p;
}

void Aresta::setProx(Aresta* a){
    this->prox = a;
}

int Aresta::getPeso(){
    return this->peso;
}

Aresta* Aresta::getProx(){
    return this->prox;
}

void Aresta::imprime(){
    Aresta *aux = this;
    while(aux != NULL){
        cout << this->peso << "|" << endl;
        aux = aux->prox;
    }
}