/***********************************************************************
 * Module:  ListaDoble.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:35
 * Purpose: Implementation of the class ListaDoble
 ***********************************************************************/

#include "ListaDoble.h"
#include <iostream>
#include <string>
using namespace std;


ListaDoble::ListaDoble(){
    cabeza = nullptr;
}


ListaDoble::~ListaDoble()
{
    Nodo* aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
}
void ListaDoble::insertarInicio(std::string c, std::string n) {
    Nodo* nuevo = new Nodo(c, n);

    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    nuevo->siguiente = cabeza;
    cabeza->anterior = nuevo;
    cabeza = nuevo;
}
void ListaDoble::insertarFinal(std::string c, std::string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->siguiente)
        aux = aux->siguiente;
    aux->siguiente = nuevo;
    nuevo->anterior = aux;
}
bool ListaDoble::buscar(std::string c) {
    Nodo* aux = cabeza;

    while (aux) {
        if (aux->cedula == c)
            return true;
        aux = aux->siguiente;
    }

    return false;
}
void ListaDoble::eliminar(std::string c) {
    Nodo* aux = cabeza;

    while (aux && aux->cedula != c)
        aux = aux->siguiente;

    if (!aux)
        return;


    if (aux->anterior)
        aux->anterior->siguiente = aux->siguiente;
    else
        cabeza = aux->siguiente;

    if (aux->siguiente)
        aux->siguiente->anterior = aux->anterior;

    delete aux;
}
void ListaDoble::mostrar() {
    Nodo* aux = cabeza;

    while (aux) {
        cout << aux->cedula << " - " << aux->nombre << endl;
        aux = aux->siguiente;
    }
}
void ListaDoble::insertarEntre(string c, string n, string cPos) {
    Nodo* nuevo = new Nodo(c, n);
    Nodo* aux = cabeza;
    while (aux && aux->cedula != cPos)
        aux = aux->siguiente;
    if (!aux)
        return;
    nuevo->siguiente = aux->siguiente;
    nuevo->anterior = aux;
    if (aux->siguiente)
        aux->siguiente->anterior = nuevo;
    aux->siguiente = nuevo;
}
