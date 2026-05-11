/***********************************************************************
 * Module:  ListaSimple.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:23
 * Purpose: Implementation of the class ListaSimple
 ***********************************************************************/

#include "ListaSimple.h"

ListaSimple::ListaSimple(){
    cabeza = nullptr;
}

ListaSimple::~ListaSimple(){
   Nodo* aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
    }
}
void ListaSimple::insertarInicio(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    nuevo->sig = cabeza;
    cabeza = nuevo;
}
void ListaSimple::insertarFinal(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->sig)
        aux = aux->sig;
    aux->sig = nuevo;
}
bool ListaSimple::buscar(string c) {
    Nodo* aux = cabeza;
    while (aux) {
        if (aux->cedula == c)
            return true;
        aux = aux->sig;
    }
    return false;
}
void ListaSimple::eliminar(string c) {
    Nodo* aux = cabeza;
    Nodo* ant = nullptr;
    while (aux && aux->cedula != c) {
        ant = aux;
        aux = aux->sig;
    }
    if (!aux) return;
    if (!ant)
        cabeza = aux->sig;
    else
        ant->sig = aux->sig;
    delete aux;
}
void ListaSimple::mostrar() {
    Nodo* aux = cabeza;
    while (aux) {
        cout << aux->cedula << " - " << aux->nombre << endl;
        aux = aux->sig;
    }
}
