#ifndef VERTICE_H
#define VERTICE_H
#include"Aresta.h"
class Vertice {
/*----------------- File: Vertice.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 19/10/2018|
+-----------------------------------------------------+ */
    private:
        char cor;
        Aresta *inicio, *fim;
    public:
        Vertice();

        void setInicio(Aresta*);
        void setFim(Aresta*);
        void setCor(char);

        char getCor();
        Aresta* getInicio();
        Aresta* getFim();
         
};
#endif