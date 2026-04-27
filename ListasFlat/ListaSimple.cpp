// Este archivo es INCLUIDO por ListaSimple.h
// NO se agrega directamente al comando de compilacion
// porque es implementacion de template

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
ListaSimple<T>::ListaSimple() : ListaBase<T>() {}

template <typename T>
ListaSimple<T>::~ListaSimple() { liberarMemoria(); }

template <typename T>
void ListaSimple<T>::insertar(T* dato) {
    Nodo<T>* nuevo = Nodo<T>::crear(dato);   // malloc interno
    if (this->estaVacia()) {
        this->cabeza = nuevo;
    } else {
        Nodo<T>* aux = this->cabeza;
        while (aux->sig) aux = aux->sig;
        aux->sig = nuevo;
    }
    this->tamanio++;
    cout << "  [OK] Insertado en Lista Simple. Total: " << this->tamanio << endl;
}

template <typename T>
void ListaSimple<T>::eliminar(const string& clave) {
    if (this->estaVacia()) { cout << "  [!] Lista Simple vacia." << endl; return; }
    Nodo<T>* actual   = this->cabeza;
    Nodo<T>* anterior = nullptr;
    while (actual) {
        if (actual->dato->getCedula() == clave) {
            if (!anterior) this->cabeza  = actual->sig;
            else           anterior->sig = actual->sig;
            Nodo<T>::destruir(actual);   // free interno
            this->tamanio--;
            cout << "  [OK] Cedula " << clave << " eliminada de Lista Simple." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->sig;
    }
    cout << "  [!] Cedula " << clave << " no encontrada." << endl;
}

template <typename T>
void ListaSimple<T>::mostrar() const {
    if (this->estaVacia()) { cout << "  [!] Lista Simple vacia." << endl; return; }
    cout << "\n  ===== LISTA SIMPLE [" << this->tamanio << " elemento(s)] =====" << endl;
    Nodo<T>* aux = this->cabeza;
    int pos = 1;
    while (aux) {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Polimorfismo virtual
        aux = aux->sig;
    }
    cout << "  =================================================" << endl;
}

template <typename T>
bool ListaSimple<T>::buscar(const string& clave) const {
    Nodo<T>* aux = this->cabeza;
    while (aux) {
        if (aux->dato->getCedula() == clave) {
            cout << "  [ENCONTRADO] "; aux->dato->mostrar(); return true;
        }
        aux = aux->sig;
    }
    return false;
}

template <typename T>
void ListaSimple<T>::liberarMemoria() {
    Nodo<T>* aux = this->cabeza;
    while (aux) { Nodo<T>* sig = aux->sig; Nodo<T>::destruir(aux); aux = sig; }
    this->cabeza  = nullptr;
    this->tamanio = 0;
}
