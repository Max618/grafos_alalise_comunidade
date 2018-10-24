#include"Vertice.h"
#include"Aresta.h"
#include<iostream>

Vertice::Vertice(){
    this->cor = 'b';
    this->fim = NULL;
    this->inicio = NULL;
}

void Vertice::setCor(char c){
    this->cor = c;
}

void Vertice::setFim(Aresta* a){
    this->fim = a;
}

void Vertice::setInicio(Aresta* a){
    this->inicio = a;
}

char Vertice::getCor(){
    return this->cor;
}

Aresta* Vertice::getFim(){
    return this->fim;
}

Aresta* Vertice::getInicio(){
    return this->inicio;
}