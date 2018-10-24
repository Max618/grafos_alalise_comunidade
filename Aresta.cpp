#include"Aresta.h"
#include<iostream>

using namespace std;

Aresta::Aresta(float p, int c){
    this->chegada = c;
    this->peso = p;
    this->prox = NULL;
}

Aresta::Aresta(){
    this->peso = -1;
    this->prox = NULL;
}

void Aresta::setPeso(float p){
    this->peso = p;
}

void Aresta::setProx(Aresta* a){
    this->prox = a;
}

float Aresta::getPeso(){
    return this->peso;
}

int Aresta::getChegada(){
    return this->chegada;
}

Aresta* Aresta::getProx(){
    return this->prox;
}

void Aresta::imprime(){
    Aresta *aux = this;
    while(aux != NULL){
        cout << "-> ";
        cout << "[" << "" << aux->chegada << "|" << "" << aux->peso << "]";
        aux = aux->prox;
    }
    cout << "-> NULL";
}