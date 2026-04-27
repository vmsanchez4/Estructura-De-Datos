#include "Listas.h"
#include <iostream>

using namespace std;

// --- Lista Simple ---
void ListaSimple::insertar(Persona* p) {
    Nodo* nuevo = new Nodo{p, nullptr, nullptr};
    if (estaVacia()) cabeza = nuevo;
    else {
        Nodo* aux = cabeza;
        while (aux->siguiente) aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
    tamanio++;
}

void ListaSimple::eliminar(const string& c) {
    Nodo *aux = cabeza, *ant = nullptr;
    while (aux && aux->dato->getCedula() != c) { ant = aux; aux = aux->siguiente; }
    if (!aux) return;
    if (!ant) cabeza = aux->siguiente;
    else ant->siguiente = aux->siguiente;
    delete aux->dato; delete aux; tamanio--;
}

void ListaSimple::modificar(const string& c, const string& n) {
    Nodo* aux = cabeza;
    while (aux) {
        if (aux->dato->getCedula() == c) { aux->dato->setNombre(n); return; }
        aux = aux->siguiente;
    }
}

void ListaSimple::mostrar() const {
    Nodo* aux = cabeza;
    while (aux) {
        cout << "ID: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl;
        aux = aux->siguiente;
    }
}

bool ListaSimple::buscar(const string& c) const {
    Nodo* aux = cabeza;
    while (aux) { if (aux->dato->getCedula() == c) return true; aux = aux->siguiente; }
    return false;
}

ListaSimple::~ListaSimple() { while (cabeza) eliminar(cabeza->dato->getCedula()); }

// --- Lista Doble ---
void ListaDoble::insertar(Persona* p) {
    Nodo* nuevo = new Nodo{p, nullptr, nullptr};
    if (estaVacia()) cabeza = nuevo;
    else {
        Nodo* aux = cabeza;
        while (aux->siguiente) aux = aux->siguiente;
        aux->siguiente = nuevo; nuevo->anterior = aux;
    }
    tamanio++;
}

void ListaDoble::eliminar(const string& c) {
    Nodo* aux = cabeza;
    while (aux && aux->dato->getCedula() != c) aux = aux->siguiente;
    if (!aux) return;
    if (aux->anterior) aux->anterior->siguiente = aux->siguiente;
    else cabeza = aux->siguiente;
    if (aux->siguiente) aux->siguiente->anterior = aux->anterior;
    delete aux->dato; delete aux; tamanio--;
}

void ListaDoble::modificar(const string& c, const string& n) {
    Nodo* aux = cabeza;
    while (aux) { if (aux->dato->getCedula() == c) { aux->dato->setNombre(n); return; } aux = aux->siguiente; }
}

void ListaDoble::mostrar() const {
    Nodo* aux = cabeza;
    while (aux) { cout << "ID: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl; aux = aux->siguiente; }
}

bool ListaDoble::buscar(const string& c) const {
    Nodo* aux = cabeza;
    while (aux) { if (aux->dato->getCedula() == c) return true; aux = aux->siguiente; }
    return false;
}

ListaDoble::~ListaDoble() { while (cabeza) eliminar(cabeza->dato->getCedula()); }

// --- Lista Circular ---
void ListaCircular::insertar(Persona* p) {
    Nodo* nuevo = new Nodo{p, nullptr, nullptr};
    if (estaVacia()) { cabeza = nuevo; nuevo->siguiente = cabeza; }
    else {
        Nodo* aux = cabeza;
        while (aux->siguiente != cabeza) aux = aux->siguiente;
        aux->siguiente = nuevo; nuevo->siguiente = cabeza;
    }
    tamanio++;
}

void ListaCircular::eliminar(const string& c) {
    if (estaVacia()) return;
    Nodo *aux = cabeza, *ant = nullptr;
    while (aux->siguiente != cabeza && aux->dato->getCedula() != c) { ant = aux; aux = aux->siguiente; }
    if (aux->dato->getCedula() != c) return;
    if (aux == cabeza && aux->siguiente == cabeza) cabeza = nullptr;
    else if (aux == cabeza) {
        Nodo* ult = cabeza;
        while (ult->siguiente != cabeza) ult = ult->siguiente;
        cabeza = cabeza->siguiente; ult->siguiente = cabeza;
    } else ant->siguiente = aux->siguiente;
    delete aux->dato; delete aux; tamanio--;
}

void ListaCircular::modificar(const string& c, const string& n) {
    if (estaVacia()) return;
    Nodo* aux = cabeza;
    do { if (aux->dato->getCedula() == c) { aux->dato->setNombre(n); return; } aux = aux->siguiente; } while (aux != cabeza);
}

void ListaCircular::mostrar() const {
    if (estaVacia()) return;
    Nodo* aux = cabeza;
    do { cout << "ID: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl; aux = aux->siguiente; } while (aux != cabeza);
}

bool ListaCircular::buscar(const string& c) const {
    if (estaVacia()) return false;
    Nodo* aux = cabeza;
    do { if (aux->dato->getCedula() == c) return true; aux = aux->siguiente; } while (aux != cabeza);
    return false;
}

ListaCircular::~ListaCircular() { while (cabeza) eliminar(cabeza->dato->getCedula()); }