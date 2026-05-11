/***********************************************************************
 * Module:  ListaCircularDoble.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:56:06
 * Purpose: Implementation of the class ListaCircularDoble
 ***********************************************************************/

#include "ListaCircularDoble.h"
#include <iostream>

ListaCircularDoble::ListaCircularDoble(){
    cabeza = nullptr;
}


ListaCircularDoble::~ListaCircularDoble(){
    if (!cabeza) return;
    Nodo* actual = cabeza->siguiente;
    while (actual != cabeza) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    delete cabeza;
}
void ListaCircularDoble::insertarInicio(std::string c, std::string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
        return;
    }
    Nodo* ultimo = cabeza->anterior;
    nuevo->siguiente = cabeza;
    nuevo->anterior = ultimo;
    cabeza->anterior = nuevo;
    ultimo->siguiente = nuevo;
    cabeza = nuevo;
}
void ListaCircularDoble::insertarFinal(std::string c, std::string n) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
        return;
    }
    Nodo* ultimo = cabeza->anterior;
    nuevo->siguiente = cabeza;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    cabeza->anterior = nuevo;
}
bool ListaCircularDoble::buscar(std::string c) {
    if (!cabeza) return false;
    Nodo* aux = cabeza;
    do {
        if (aux->cedula == c)
            return true;
        aux = aux->siguiente;
    } while (aux != cabeza);
    return false;
}
void ListaCircularDoble::eliminar(std::string c) {
    if (!cabeza) return;

    Nodo* aux = cabeza;

    do {
        if (aux->cedula == c) {
            if (aux->siguiente == aux) {
                delete aux;
                cabeza = nullptr;
                return;
            }
            Nodo* anterior = aux->anterior;
            Nodo* siguiente = aux->siguiente;

            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;

            if (aux == cabeza)
                cabeza = siguiente;

            delete aux;
            return;
        }
        aux = aux->siguiente;

    } while (aux != cabeza);
}
void ListaCircularDoble::mostrar() {
    if (!cabeza) return;

    Nodo* aux = cabeza;
    do {
        cout << aux->cedula << " - " << aux->nombre << endl;
        aux = aux->siguiente;
    } while (aux != cabeza);
}
void ListaCircularDoble::insertarEntre(string c, string n, string cPos) {
    Nodo* nuevo = new Nodo(c, n);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
        return;
    }
    Nodo* aux = cabeza;
    do {
        if (aux->cedula == cPos) {
            nuevo->siguiente = aux->siguiente;
            nuevo->anterior = aux;
            aux->siguiente->anterior = nuevo;
            aux->siguiente = nuevo;
            return;
        }
        aux = aux->siguiente;
    } while (aux != cabeza);
}
