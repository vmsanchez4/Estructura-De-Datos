#pragma once
#include <iostream>
using namespace std;

template <typename T>
ListaDoble<T>::ListaDoble() : ListaBase<T>(), cola(nullptr) {}

template <typename T>
ListaDoble<T>::~ListaDoble() { liberarMemoria(); }

template <typename T>
void ListaDoble<T>::insertar(T* dato) {
    Nodo<T>* nuevo = Nodo<T>::crear(dato);
    if (this->estaVacia()) {
        this->cabeza = nuevo;
        cola         = nuevo;
    } else {
        nuevo->ant = cola;
        cola->sig  = nuevo;
        cola       = nuevo;
    }
    this->tamanio++;
    cout << "  [OK] Insertado en Lista Doble. Total: " << this->tamanio << endl;
}

template <typename T>
void ListaDoble<T>::eliminar(const string& clave) {
    if (this->estaVacia()) { cout << "  [!] Lista Doble vacia." << endl; return; }
    Nodo<T>* actual = this->cabeza;
    while (actual) {
        if (actual->dato->getCedula() == clave) {
            if (actual->ant) actual->ant->sig = actual->sig;
            else             this->cabeza     = actual->sig;
            if (actual->sig) actual->sig->ant = actual->ant;
            else             cola             = actual->ant;
            Nodo<T>::destruir(actual);
            this->tamanio--;
            cout << "  [OK] Cedula " << clave << " eliminada de Lista Doble." << endl;
            return;
        }
        actual = actual->sig;
    }
    cout << "  [!] Cedula " << clave << " no encontrada." << endl;
}

template <typename T>
void ListaDoble<T>::mostrar() const {
    if (this->estaVacia()) { cout << "  [!] Lista Doble vacia." << endl; return; }
    cout << "\n  ===== LISTA DOBLE [" << this->tamanio << " elemento(s)] | CABEZA->COLA =====" << endl;
    Nodo<T>* aux = this->cabeza; int pos = 1;
    while (aux) { cout << "  [" << pos++ << "] "; aux->dato->mostrar(); aux = aux->sig; }
    cout << "  =================================================" << endl;
}

template <typename T>
void ListaDoble<T>::mostrarInverso() const {
    if (this->estaVacia()) { cout << "  [!] Lista Doble vacia." << endl; return; }
    cout << "\n  ===== LISTA DOBLE INVERSA | COLA->CABEZA =====" << endl;
    Nodo<T>* aux = cola; int pos = this->tamanio;
    while (aux) { cout << "  [" << pos-- << "] "; aux->dato->mostrar(); aux = aux->ant; }
    cout << "  =================================================" << endl;
}

template <typename T>
bool ListaDoble<T>::buscar(const string& clave) const {
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
void ListaDoble<T>::liberarMemoria() {
    Nodo<T>* aux = this->cabeza;
    while (aux) { Nodo<T>* sig = aux->sig; Nodo<T>::destruir(aux); aux = sig; }
    this->cabeza  = nullptr;
    cola          = nullptr;
    this->tamanio = 0;
}
