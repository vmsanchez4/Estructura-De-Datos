/***********************************************************************
 * Module:  ListaSimple.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:23
 * Purpose: Implementation of the class ListaSimple
 ***********************************************************************/

#include "ListaSimple.h"
#include "Nodo.h"
#include <iostream>
ListaSimple::ListaSimple(){
    cabeza = nullptr;
}
Nodo* ListaSimple::getCabeza(){
    return cabeza;
}
ListaSimple::~ListaSimple(){
   Nodo* aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
}
void ListaSimple::insertarInicio(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}
void ListaSimple::insertarFinal(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->siguiente)
        aux = aux->siguiente;
    aux->siguiente = nuevo;
}
bool ListaSimple::buscar(string c) {
    Nodo* aux = cabeza;
    while (aux) {
        if (aux->cedula == c)
            return true;
        aux = aux->siguiente;
    }
    return false;
}
void ListaSimple::eliminar(string c) {
    Nodo* aux = cabeza;
    Nodo* ant = nullptr;
    while (aux && aux->cedula != c) {
        ant = aux;
        aux = aux->siguiente;
    }
    if (!aux)
        return;
    if (!ant)
        cabeza = aux->siguiente;
    else
        ant->siguiente = aux->siguiente;
    delete aux;
}
void ListaSimple::mostrar() {
    Nodo* aux = cabeza;
    while (aux) {
        cout << aux->cedula << " - " << aux->nombre << endl;
        aux = aux->siguiente;
    }
}
bool ListaSimple::buscarNombre(string nombre) {
    Nodo* aux = cabeza;
    while (aux) {
        if (aux->nombre == nombre)
            return true;
        aux = aux->siguiente;
    }
    return false;
}
