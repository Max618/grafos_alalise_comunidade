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
        int peso;
        Aresta *prox;
    public:
         Aresta(int);
         Aresta();

         void setPeso(int);
         void setProx(Aresta*);

         int getPeso();
         Aresta* getProx();

         void imprime();
         
};
#endif