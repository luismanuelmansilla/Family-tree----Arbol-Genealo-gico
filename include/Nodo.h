#ifndef NODO_H
#define NODO_H
#include <string>
using namespace std;

class Nodo
{
    public:
        Nodo(string nombre);
        string getNombre();
        void agregarHijo(Nodo* hijo);
    private:
        string _nombre;
        Nodo* _padre;
        Nodo* _primerHijo;
        Nodo* _ultimoHijo;
        Nodo* _siguiente;

    friend class Arbol;
    friend class Menu;
};

#endif // NODO_H
