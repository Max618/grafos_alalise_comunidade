#include"Grafo.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>
#include"Fila.cpp"

using namespace std;

Grafo::Grafo(int v){
    if(v > 0){
        this->numeroVertices = v;
        this->list = new Vertice[v];
        this->arvorePrim = new prim[v];
        this->resetArvorePrim();
        this->arvoreKruskal = new DisjoinSet <Vertice>;
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
	delete  this->arvoreKruskal;
}

int Grafo::linhaVazia(int l){
    return (this->list[l].getInicio() == NULL);
}

void Grafo::inserirAresta(int s, int c, double p){
    if(s != c){
        Aresta *nova = new Aresta(p,c);
        this->list[s].inserirOrdenado(nova,s);
    }
}

Vertice* Grafo::getList(){
    return this->list;
}

void Grafo::imprimirGrafo(){
    cout << "[Origem] -> [Destino|Peso]" << endl;
    for(int i = 0; i < this->numeroVertices; i++){
        cout << "[" << i+1 << "]";
        this->list[i].getInicio()->imprime();
        cout << endl << endl;
    }
}

int Grafo::existeBranco(){
    for(int i = 0; i < this->numeroVertices; i++) {
        if(this->list[i].getCor() == 'b')
            return 1;
    }
    return 0;
}

void Grafo::setVerticesBrancos(){
    for(int i = 0; i < this->numeroVertices; i++) {
        this->list[i].setCor('b');
    }
}

void Grafo::resetArvorePrim(){
	for(int i = 0; i < this->numeroVertices; i++){
		this->arvorePrim[i].pai = -1;
		this->arvorePrim[i].peso = 10;
	}
}

void Grafo::setPrim(int vertice_inicial){
	this->setVerticesBrancos();
	this->resetArvorePrim();
	
	Fila <aresta> Q(2*this->numeroVertices);
	aresta arestas, menorPeso;
	int verticeAtual = vertice_inicial;
	Aresta *aux;
	
	this->arvorePrim[vertice_inicial].peso = 0;
	
	while(this->existeBranco())
	{
		//INSERE FILHOS NA LISTA
		for(int i=0; i<this->list[verticeAtual].getNumeroArestas(); i++){
			aux = this->list[verticeAtual].getAresta(i);
			
			arestas.origem = verticeAtual;
			arestas.destino = aux->getChegada();
			arestas.peso = aux->getPeso();
			
			if(this->list[arestas.destino].getCor() != 'p'){
				Q.inserir(arestas);
			}
		}
		Q.ordenar();

		//REMOVE FILHOS AINDA NAO VISITADOS
		do{
			menorPeso = Q.remover();
		}while((this->list[menorPeso.destino].getCor() == 'p' || menorPeso.destino == verticeAtual));
		
		this->arvorePrim[menorPeso.destino].pai = menorPeso.origem;
		this->arvorePrim[menorPeso.destino].peso = menorPeso.peso;
		this->list[verticeAtual].setCor('p');
		this->list[menorPeso.destino].setCor('c');
				
		verticeAtual = menorPeso.destino;
		
	}
}

prim* Grafo::getPrim(){
    return this->arvorePrim;
}

int Grafo::arvoreKruskalCompleta(){
	return (this->arvoreKruskal->getQuatidadeGrupos() == 1);
}

void Grafo::setKruskal(){
	cout << "INICIO KRUSKAL" << endl;
	for(int i =0; i<this->numeroVertices; i++)
	{
		this->arvoreKruskal->makeSet(this->list[i]);
	}
	//this->arvoreKruskal->imprime(this->arvoreKruskal->findSet(this->list[0]));
	cout << "INICIO WHILE" << endl;
	while(!this->arvoreKruskalCompleta()){
		cout << "KRUSKAL" << endl;
		Aresta *menor = this->list[0].getAresta(0);
		int indiceMenor = 0;
		cout << "KRUSKAL2" << endl;
		for(int i = 0; i < this->numeroVertices; i++){
			for(int j=0; j<this->list[i].getNumeroArestas(); j++)
			{
				//cout << "MENOR: " << indiceMenor+1 << " -> " << menor->getChegada()+1 << endl;
				//cout << "I - " << i+1 << " J - " << j+1 << endl;
				if(this->list[i].getAresta(j)->getPeso() < menor->getPeso()){
					menor = this->list[i].getAresta(j);
					indiceMenor = i;
					//cout << "DENTRO IF - " << indiceMenor+1 << " -> " << menor->getChegada()+1 << endl;
				}
			}
		}

		cout << indiceMenor+1 << " -> " << menor->getChegada()+1 << endl;
		conjunto<Vertice> *s1 = this->arvoreKruskal->findSet((this->list[menor->getChegada()]));
		conjunto<Vertice> *s2 = this->arvoreKruskal->findSet((this->list[indiceMenor]));
		cout << "KRUSKAL5" << endl;
		if(s1 != s2){
			cout << "KRUSKAL6" << endl;
			this->arvoreKruskal->joinSets(s1,s2);
		}
	}
}

DisjoinSet<Vertice>* Grafo::getKruskal(){
	return this->arvoreKruskal;
}

void Grafo::agrupamento(int k){

	int maior;

	for(int i=1; i<k; i++)
	{	
		maior = 0;
		for(int j=0; j < this->numeroVertices; j++)
		{
			if(this->arvorePrim[maior].peso < this->arvorePrim[j].peso)
			{
				maior = j;
			}
		}

		this->arvorePrim[maior].pai = -1;
		this->arvorePrim[maior].peso = 0;
	}

}
