/***********************************************************************
 * Module:  ListaCircular.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:48
 * Purpose: Implementation of the class ListaCircular
 ***********************************************************************/

#include "ListaCircular.h"
#include <iostream>
ListaCircular::ListaCircular(){
    cabeza = nullptr;
}

ListaCircular::~ListaCircular(){
    if (!cabeza)
        return;
    Nodo* actual = cabeza->siguiente;
    while (actual != cabeza) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    delete cabeza;
}
void ListaCircular::insertarInicio(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->siguiente != cabeza)
        aux = aux->siguiente;
    nuevo->siguiente = cabeza;
    aux->siguiente = nuevo;
    cabeza = nuevo;
}
void ListaCircular::insertarFinal(string c, string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
        return;
    }
    Nodo* aux = cabeza;
    while (aux->siguiente != cabeza)
        aux = aux->siguiente;
    aux->siguiente = nuevo;
    nuevo->siguiente = cabeza;
}
bool ListaCircular::buscar(string c) {
    if (!cabeza) return false;
    Nodo* aux = cabeza;
    do {
        if (aux->cedula == c)
            return true;
        aux = aux->siguiente;
    } while (aux != cabeza);
    return false;
}
void ListaCircular::eliminar(string c) {
    if (!cabeza) return;
    Nodo* aux = cabeza;
    Nodo* ant = nullptr;
    do {
        if (aux->cedula == c) {
            if (aux == cabeza && aux->siguiente == cabeza) {
                delete aux;
                cabeza = nullptr;
                return;
            }
            if (aux == cabeza) {
                Nodo* ult = cabeza;
                while (ult->siguiente != cabeza)
                    ult = ult->siguiente;
                cabeza = cabeza->siguiente;
                ult->siguiente = cabeza;
            } else {
                ant->siguiente = aux->siguiente;
            }
            delete aux;
            return;
        }
        ant = aux;
        aux = aux->siguiente;
    } while (aux != cabeza);
}
void ListaCircular::mostrar() {
    if (!cabeza) return;
    Nodo* aux = cabeza;
    do {
        cout << aux->cedula << " - " << aux->nombre << endl;
        aux = aux->siguiente;
    } while (aux != cabeza);
}
