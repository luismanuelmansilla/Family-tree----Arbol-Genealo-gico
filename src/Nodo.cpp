#include "Nodo.h"

Nodo::Nodo(string nombre)
{
    _nombre = nombre;
    _padre = NULL;
    _primerHijo = NULL;
    _ultimoHijo = NULL;
    _siguiente = NULL;
}

string Nodo::getNombre()
{
    return _nombre;
}

void Nodo::agregarHijo(Nodo* hijo)
{
     if(!_primerHijo)
    {
        _primerHijo = hijo;
        _ultimoHijo = hijo;
    }else
    {
        _ultimoHijo -> _siguiente = hijo;
        _ultimoHijo = hijo;
    }
}
