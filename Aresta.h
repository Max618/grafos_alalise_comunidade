#ifndef ARESTA_H
#define ARESTA_H
class Aresta {
/*----------------- File: Aresta.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 19/10/2018|
+-----------------------------------------------------+ */
    private:
        int peso, chegada;
        Aresta *prox;
    public:
         Aresta(float, int);
         Aresta();

         void setPeso(float);
         void setProx(Aresta*);

         float getPeso();
         int getChegada();
         Aresta* getProx();

         void imprime();
         
};
#endif