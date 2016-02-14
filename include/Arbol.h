#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

class Arbol
{
    public:
        Arbol(Nodo* raiz);
        void recorrer(Nodo* nodo);
        void recorrer();
    private:
        Nodo* _raiz;
    friend class Menu;
};

#endif // ARBOL_H
