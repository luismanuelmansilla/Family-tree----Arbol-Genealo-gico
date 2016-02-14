#include "Menu.h"
#include "Arbol.h"
#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include <winuser.h>
using namespace std;

Arbol* arbol;

Menu::Menu()
{
    //ctor
}

void Menu::menuPrincipal()
{
    char opcionMenu;
    do {
        cout << "\n\n\n\t\tBienvenido al \240rbol Geneal\242gico\n";
        cout << "\t\t Creado por: Luis Manuel Mansilla\n\n";
        cout << "1. Crear \240rbol geneal\242gico.\n";
        cout << "2. Desplegar \240rbol geneal\242gico.\n";
        cout << "3. Salir.\n";
        cout << "\nElija una opci\242n => ";
        opcionMenu=_getch();
        cin.clear();
        fflush(stdin);
        cout << "\n";

        switch (opcionMenu) {
            case '1': menuInsertar();
            break;
            case '2': menuListar();
            break;
            case '3':
                system("cls");
                cout << "\nSaliendo del sistema.." << endl;
                cout << "\n\n\n\t\tGracias por usar el programa, hasta la pr\242xima!\n";
                MensajeCerrar();
                break;
            default: MensajeError();
        }
        system("PAUSE>null");
        system("cls");
    }while(opcionMenu != '3');
}

void Menu::menuInsertar()
{
    system("cls");
    cin.clear();
    fflush(stdin);
    string nombre;
    int cantHijos;
    bool tienenHijos=true;
    Nodo* padre;
    cout << "\n\n\n\t\tCrear \240rbol geneal\242gico\n\n" << endl;
    do{
        cout << "Ingrese el nombre de la persona: ";
        getline(cin, nombre);
    }while (nombre.empty());

    Nodo* raiz = new Nodo(nombre);
    arbol = new Arbol(raiz);

    padre = raiz;
    do
    {
        cout<<"Digite la cantidad de hijos de "<< padre -> getNombre()<<": ";
        do
        {
            cin >> cantHijos;
        }
        while(cantHijos<0);
        cin.clear();
        fflush(stdin);

        agregar(padre,cantHijos,0);
        if(cantHijos>0)
            padre = padre->_primerHijo;
        else if(cantHijos==0){
            while(!padre->_siguiente){
                if(padre == arbol -> _raiz){
                    cout<<"\n---------------FIN<<---------------"<<endl;
                    return;
                }
                padre=padre->_padre;
            }
            padre = padre -> _siguiente;
        }

    }
    while(tienenHijos);
}

void Menu::agregar(Nodo* padre,int numeroHijos,int iterador)
{
    if(iterador==numeroHijos)
        return;
    string nombre;
    do{
        cout <<"Digite el nombre del hijo #" << iterador+1 << " de " << padre -> _nombre<<": ";
        getline(cin,nombre);
    }while (nombre.empty());

    Nodo* hijo = new Nodo(nombre);
    hijo -> _padre = padre;
    padre -> agregarHijo(hijo);
    agregar(padre,numeroHijos,iterador+1);
}

void Menu::menuListar()
{
    system("cls");
    cout << "\n\n\n\t\tDesplegar \240rbol geneal\242gico\n\n" << endl;

    if(!arbol->_raiz){
        cout <<"El arbol esta vacio..." << endl;
    }else{
    cout < "\n";
    arbol -> recorrer();
    cout<<"\n---------------FIN<<---------------"<<endl;
    }
}

void Menu::MensajeError()
{
    int msgboxID = MessageBox(
        NULL,
        "Opción invalida! Seleccione nuevamente.",
        "Error!!",
        MB_ICONERROR | MB_OK | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDOK:
        system("cls");
        menuPrincipal();
        break;
    }
}

void Menu::MensajeCerrar()
{
    int msgboxID = MessageBox(
        NULL,
        "Deseas cerrar el programa?",
        "Confirmación",
        MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDYES:
        exit(1);
        break;
    case IDNO:
        system("cls");
        menuPrincipal();
        break;
    }
}
