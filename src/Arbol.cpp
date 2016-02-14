#include "Arbol.h"
#include <iostream>
using namespace std;

Arbol::Arbol(Nodo* raiz)
{
    _raiz = raiz;
}

void Arbol::recorrer(Nodo* nodo)
{
    if(!nodo->_primerHijo){
        cout << nodo-> getNombre() <<" no tiene hijos" << endl;
        while(!nodo -> _siguiente)
        {
            if(nodo == _raiz)
                return;
            nodo = nodo->_padre;
        }
        nodo=nodo->_siguiente;
        recorrer(nodo);
    }else{
        cout << nodo -> getNombre()<< " es padre de: ";
        nodo = nodo -> _primerHijo;
        if(!nodo -> _siguiente){
            cout << nodo -> getNombre() << endl;
        }else{
            while(nodo){
                if(!nodo->_siguiente){
                    cout << nodo -> getNombre() << endl;
                    break;
                }
                else{
                    cout << nodo -> getNombre()<<", ";
                }
                nodo = nodo -> _siguiente;
            }
        }
        nodo = nodo -> _padre;
        recorrer(nodo -> _primerHijo);
    }
}

void Arbol::recorrer()
{
    recorrer(_raiz);
}
