#include "Listas.h"
#include <iostream>

using namespace std;

// --- FUNCION AUXILIAR GLOBAL ---
Nodo* crearNodoBasico(Persona* persona) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = persona;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;
    return nuevo;
}

// ==========================================
// --- LOGICA LISTA SIMPLE ---
// ==========================================
void ListaSimple::insertar(Persona* persona) {
    Nodo* nuevo = crearNodoBasico(persona);
    if (estaVacia()) {
        cabeza = nuevo;
    } else {
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr) aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
    tamanio++;
}

void ListaSimple::eliminar(const string& cedula) {
    if (estaVacia()) return;
    Nodo* aux = cabeza;
    Nodo* ant = nullptr;

    while (aux != nullptr && aux->dato->getCedula() != cedula) {
        ant = aux;
        aux = aux->siguiente;
    }

    if (aux == nullptr) return; 

    if (ant == nullptr) cabeza = aux->siguiente; 
    else ant->siguiente = aux->siguiente;

    delete aux->dato;
    delete aux;
    tamanio--;
}

void ListaSimple::mostrar() const {
    Nodo* aux = cabeza;
    cout << "\n[Lista Simple] - Tamanio: " << getTamanio() << endl;
    while (aux != nullptr) {
        cout << "CI: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl;
        aux = aux->siguiente;
    }
}

bool ListaSimple::buscar(const string& cedula) const {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->dato->getCedula() == cedula) return true;
        aux = aux->siguiente;
    }
    return false;
}

ListaSimple::~ListaSimple() {
    while (!estaVacia()) eliminar(cabeza->dato->getCedula());
}


// ==========================================
// --- LOGICA LISTA DOBLE ---
// ==========================================
void ListaDoble::insertar(Persona* persona) {
    Nodo* nuevo = crearNodoBasico(persona);
    if (estaVacia()) {
        cabeza = nuevo;
    } else {
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr) aux = aux->siguiente;
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    tamanio++;
}

void ListaDoble::eliminar(const string& cedula) {
    if (estaVacia()) return;
    Nodo* aux = cabeza;

    while (aux != nullptr && aux->dato->getCedula() != cedula) {
        aux = aux->siguiente;
    }

    if (aux == nullptr) return;

    if (aux->anterior == nullptr) { 
        cabeza = aux->siguiente;
        if (cabeza != nullptr) cabeza->anterior = nullptr;
    } else {
        aux->anterior->siguiente = aux->siguiente;
        if (aux->siguiente != nullptr) {
            aux->siguiente->anterior = aux->anterior;
        }
    }

    delete aux->dato;
    delete aux;
    tamanio--;
}

void ListaDoble::mostrar() const {
    Nodo* aux = cabeza;
    cout << "\n[Lista Doble] - Tamanio: " << getTamanio() << endl;
    while (aux != nullptr) {
        cout << "CI: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl;
        aux = aux->siguiente;
    }
}

bool ListaDoble::buscar(const string& cedula) const {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->dato->getCedula() == cedula) return true;
        aux = aux->siguiente;
    }
    return false;
}

ListaDoble::~ListaDoble() {
    while (!estaVacia()) eliminar(cabeza->dato->getCedula());
}


// ==========================================
// --- LOGICA LISTA CIRCULAR ---
// ==========================================
void ListaCircular::insertar(Persona* persona) {
    Nodo* nuevo = crearNodoBasico(persona);
    if (estaVacia()) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
    } else {
        Nodo* aux = cabeza;
        while (aux->siguiente != cabeza) aux = aux->siguiente;
        aux->siguiente = nuevo;
        nuevo->siguiente = cabeza;
    }
    tamanio++;
}

void ListaCircular::eliminar(const string& cedula) {
    if (estaVacia()) return;
    
    Nodo* aux = cabeza;
    Nodo* ant = nullptr;

    while (aux->siguiente != cabeza && aux->dato->getCedula() != cedula) {
        ant = aux;
        aux = aux->siguiente;
    }

    if (aux->dato->getCedula() != cedula) return;

    if (aux == cabeza && aux->siguiente == cabeza) {
        cabeza = nullptr;
    } 
    else if (aux == cabeza) {
        Nodo* ultimo = cabeza;
        while (ultimo->siguiente != cabeza) ultimo = ultimo->siguiente;
        cabeza = cabeza->siguiente;
        ultimo->siguiente = cabeza;
    } 
    else {
        ant->siguiente = aux->siguiente;
    }

    delete aux->dato;
    delete aux;
    tamanio--;
}

void ListaCircular::mostrar() const {
    if (estaVacia()) {
        cout << "\n[Lista Circular] Vacia." << endl;
        return;
    }
    Nodo* aux = cabeza;
    cout << "\n[Lista Circular] - Tamanio: " << getTamanio() << endl;
    do {
        cout << "CI: " << aux->dato->getCedula() << " | Nombre: " << aux->dato->getNombre() << endl;
        aux = aux->siguiente;
    } while (aux != cabeza);
}

bool ListaCircular::buscar(const string& cedula) const {
    if (estaVacia()) return false;
    Nodo* aux = cabeza;
    do {
        if (aux->dato->getCedula() == cedula) return true;
        aux = aux->siguiente;
    } while (aux != cabeza);
    return false;
}

ListaCircular::~ListaCircular() {
    while (!estaVacia()) eliminar(cabeza->dato->getCedula());
}