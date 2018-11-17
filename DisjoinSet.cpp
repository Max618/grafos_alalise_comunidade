#ifndef DISJOIN_H
#define DISJOIN_H

/*----------------- File: Disjoin.h ------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Victor Alcantara" em 17/11/2018|
+-----------------------------------------------------+ */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct conjunto;

template <class T>
struct celula{
    T info;
    celula *prox;
    conjunto<T> *ptrConjunto;
};

template <class T>
struct conjunto{
    celula<T> *head, *tail;
};

template <class T>
class DisjoinSet{

    private:
        unordered_map<int, celula<T>*> hash; 
        int quantidadeGrupos;
    public:
        DisjoinSet();
        void makeSet(T);
        conjunto<T>* findSet(T);
        void joinSets(conjunto<T>*, conjunto<T>*);

        void imprime(conjunto<T> *);
        int getQuatidadeGrupos();
         
};

template<class T>
DisjoinSet<T>::DisjoinSet(){
    this->quantidadeGrupos = 0;
}

template<class T>
void DisjoinSet<T>::makeSet(T elemento){

    conjunto<T> *novo = new conjunto<T>;
    novo->head = new celula<T>;
    novo->tail = novo->head;
    hash[elemento.getIndice()] = novo->head;

    novo->head->info = elemento;
    novo->head->prox = NULL;
    novo->head->ptrConjunto = novo;

    this->quantidadeGrupos++;

}

template<class T>
conjunto<T>* DisjoinSet<T>::findSet(T elemento){

    
    celula<T> *ptr = hash[elemento.getIndice()];


    return (ptr->ptrConjunto);
}

template<class T>
void DisjoinSet<T>::joinSets(conjunto<T> *c1, conjunto<T> *c2){

    celula<T> *aux = c2->head;
    while(aux != NULL)
    {
        aux->ptrConjunto = c1;
        aux = aux->prox;
    }

    (c1->tail)->prox = c2->head;
    c1->tail = c2->tail;

    delete c2;
    this->quantidadeGrupos--;
}

template<class T>
void DisjoinSet<T>::imprime(conjunto<T> *c){

    celula<T> *aux = c->head;
    do
    {
        aux->info.getInicio()->imprime();
        //aux = aux->prox;
        cout << "AQUI" << endl;
    }while(aux->prox != NULL);
    
}

template<class T>
int DisjoinSet<T>::getQuatidadeGrupos(){
    return this->quantidadeGrupos;
}

#endif