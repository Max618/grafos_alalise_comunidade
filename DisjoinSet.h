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

typedef struct sConjunto;

template <class T>
typedef struct sCell{
    T info;
    struct sCell *prox;
    struct sConjunto *ptrConjunto;
}celula;

typedef struct sConjunto{
    celula *head, *tail;
}conjunto;

template <class T>
class DisjoinSet{

    private:
        unordered_map<T, celula *> hash; 
    public:
        void makeSet(T);
        conjunto* findSet(T);
        void joinSets(conjunto*, conjunto*);

        void imprime();
         
};

template<class T>
void DisjoinSet<T>::makeSet(T elemento){

    conjunto *novo = new conjunto;
    novo->head = new celula<T>;
    novo->tail = novo->head;
    hash[elemento] = novo->head;

    novo->head->info = elemento;
    novo->head->prox = NULL;
    novo->head->ptrConjunto = novo;

}

template<class T>
conjunto* DisjoinSet<T>::findSet(T elemento){

    celula *ptr = hash[elemento];
    return (ptr->ptrConjunto);
}

template<class T>
void DisjoinSet<T>::joinSets(conjunto *c1, conjunto *c2){

    celula *aux = c2->head;
    while(aux != NULL)
    {
        aux->ptrConjunto = c1;
        aux = aux->prox;
    }

    (c1->tail)->prox = c2->head;
    c1->tail = c2->tail;

    delete c2;
}

template<class T>
void DisjoinSet<T>::imprime(conjunto *c){

    celula *aux = c->head;
    while(aux != NULL)
    {
        cout << aux->info << endl;
        aux = aux->prox;
    }
}

#endif