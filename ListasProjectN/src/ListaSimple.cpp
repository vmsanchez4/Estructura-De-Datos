#include "../headers/ListaSimple.h"
#include <iostream>
using namespace std;

// ============================================================
//  IMPLEMENTACION - ListaSimple
// ============================================================

ListaSimple::ListaSimple() : ListaBase() {}

ListaSimple::~ListaSimple() {
    liberarMemoria();
}

// Insertar al final de la lista
void ListaSimple::insertar(Persona* persona) {
    Nodo* nuevo = new Nodo(persona);   // Puntero a nuevo nodo

    if (estaVacia()) {
        cabeza = nuevo;
    } else {
        Nodo* aux = cabeza;            // Puntero auxiliar para recorrer
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    tamanio++;
    cout << "\n  [OK] Persona insertada en Lista Simple." << endl;
}

// Eliminar por cedula
void ListaSimple::eliminar(const string& cedula) {
    if (estaVacia()) {
        cout << "\n  [!] Lista Simple vacia." << endl;
        return;
    }

    Nodo* actual   = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato->getCedula() == cedula) {
            if (anterior == nullptr) {
                // Eliminar cabeza
                cabeza = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            delete actual;
            tamanio--;
            cout << "\n  [OK] Persona con cedula " << cedula
                 << " eliminada de Lista Simple." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->sig;
    }
    cout << "\n  [!] Cedula " << cedula << " no encontrada en Lista Simple." << endl;
}

// Mostrar todos los elementos
void ListaSimple::mostrar() const {
    if (estaVacia()) {
        cout << "\n  [!] Lista Simple vacia." << endl;
        return;
    }
    cout << "\n  ============= LISTA SIMPLE [" << tamanio << " elemento(s)] =============" << endl;
    Nodo* aux = cabeza;
    int   pos = 1;
    while (aux != nullptr) {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Llamada polimorfica virtual
        aux = aux->sig;
    }
    cout << "  =======================================================" << endl;
}

// Buscar por cedula — retorna referencia booleana
bool ListaSimple::buscar(const string& cedula) const {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->dato->getCedula() == cedula) {
            cout << "\n  [ENCONTRADO] ";
            aux->dato->mostrar();
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

// Liberar toda la memoria de la lista
void ListaSimple::liberarMemoria() {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        Nodo* siguiente = aux->sig;
        delete aux;
        aux = siguiente;
    }
    cabeza   = nullptr;
    tamanio  = 0;
}
