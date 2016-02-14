#ifndef MENU_H
#define MENU_H
#include"Arbol.h"

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void menuInsertar();
        void menuListar();
        void MensajeError();
        void MensajeCerrar();
        void agregar(Nodo* padre,int cantHijos,int iterador);
    friend class Arbol;
};

#endif // MENU_H
