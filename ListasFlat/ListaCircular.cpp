#pragma once
#include <iostream>
using namespace std;

template <typename T>
ListaCircular<T>::ListaCircular() : ListaBase<T>(), cola(nullptr) {}

template <typename T>
ListaCircular<T>::~ListaCircular() { liberarMemoria(); }

template <typename T>
void ListaCircular<T>::insertar(T* dato) {
    Nodo<T>* nuevo = Nodo<T>::crear(dato);
    if (this->estaVacia()) {
        this->cabeza = nuevo;
        cola         = nuevo;
        nuevo->sig   = this->cabeza;
    } else {
        nuevo->sig = this->cabeza;
        cola->sig  = nuevo;
        cola       = nuevo;
    }
    this->tamanio++;
    cout << "  [OK] Insertado en Lista Circular. Total: " << this->tamanio << endl;
}

template <typename T>
void ListaCircular<T>::eliminar(const string& clave) {
    if (this->estaVacia()) { cout << "  [!] Lista Circular vacia." << endl; return; }
    Nodo<T>* actual   = this->cabeza;
    Nodo<T>* anterior = cola;
    for (int i = 0; i < this->tamanio; i++) {
        if (actual->dato->getCedula() == clave) {
            if (this->tamanio == 1) {
                this->cabeza = nullptr; cola = nullptr;
            } else if (actual == this->cabeza) {
                this->cabeza = actual->sig; cola->sig = this->cabeza;
            } else if (actual == cola) {
                cola = anterior; cola->sig = this->cabeza;
            } else {
                anterior->sig = actual->sig;
            }
            Nodo<T>::destruir(actual);
            this->tamanio--;
            cout << "  [OK] Cedula " << clave << " eliminada de Lista Circular." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->sig;
    }
    cout << "  [!] Cedula " << clave << " no encontrada." << endl;
}

template <typename T>
void ListaCircular<T>::mostrar() const {
    if (this->estaVacia()) { cout << "  [!] Lista Circular vacia." << endl; return; }
    cout << "\n  ===== LISTA CIRCULAR [" << this->tamanio << " elemento(s)] =====" << endl;
    Nodo<T>* aux = this->cabeza; int pos = 1;
    do {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();
        aux = aux->sig;
    } while (aux != this->cabeza);
    cout << "  (... regresa a [1] - es CIRCULAR)" << endl;
    cout << "  =================================================" << endl;
}

template <typename T>
bool ListaCircular<T>::buscar(const string& clave) const {
    if (this->estaVacia()) return false;
    Nodo<T>* aux = this->cabeza;
    do {
        if (aux->dato->getCedula() == clave) {
            cout << "  [ENCONTRADO] "; aux->dato->mostrar(); return true;
        }
        aux = aux->sig;
    } while (aux != this->cabeza);
    return false;
}

template <typename T>
void ListaCircular<T>::recorrerVueltas(int vueltas) const {
    if (this->estaVacia()) { cout << "  [!] Lista Circular vacia." << endl; return; }
    cout << "\n  ===== RECORRIENDO " << vueltas << " VUELTA(S) =====" << endl;
    Nodo<T>* aux = this->cabeza;
    int total = this->tamanio * vueltas;
    for (int i = 1; i <= total; i++) {
        cout << "  [Paso " << i << "] "; aux->dato->mostrar(); aux = aux->sig;
    }
    cout << "  =====================================" << endl;
}

template <typename T>
void ListaCircular<T>::liberarMemoria() {
    if (this->estaVacia()) return;
    cola->sig = nullptr;
    Nodo<T>* aux = this->cabeza;
    while (aux) { Nodo<T>* sig = aux->sig; Nodo<T>::destruir(aux); aux = sig; }
    this->cabeza  = nullptr;
    cola          = nullptr;
    this->tamanio = 0;
}
