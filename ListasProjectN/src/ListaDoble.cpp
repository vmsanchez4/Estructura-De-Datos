#include "../headers/ListaDoble.h"
#include <iostream>
using namespace std;

// ============================================================
//  IMPLEMENTACION - ListaDoble
// ============================================================

ListaDoble::ListaDoble() : ListaBase(), cola(nullptr) {}

ListaDoble::~ListaDoble() {
    liberarMemoria();
}

// Insertar al final manteniendo punteros ant y sig
void ListaDoble::insertar(Persona* persona) {
    Nodo* nuevo = new Nodo(persona);

    if (estaVacia()) {
        cabeza = nuevo;
        cola   = nuevo;
    } else {
        nuevo->ant = cola;   // El nuevo apunta hacia atras a la antigua cola
        cola->sig  = nuevo;  // La antigua cola apunta al nuevo
        cola       = nuevo;  // La cola ahora es el nuevo
    }
    tamanio++;
    cout << "\n  [OK] Persona insertada en Lista Doble." << endl;
}

// Eliminar por cedula con reconexion de punteros dobles
void ListaDoble::eliminar(const string& cedula) {
    if (estaVacia()) {
        cout << "\n  [!] Lista Doble vacia." << endl;
        return;
    }

    Nodo* actual = cabeza;

    while (actual != nullptr) {
        if (actual->dato->getCedula() == cedula) {

            // Reconectar el nodo anterior
            if (actual->ant != nullptr) {
                actual->ant->sig = actual->sig;
            } else {
                cabeza = actual->sig;  // Era la cabeza
            }

            // Reconectar el nodo siguiente
            if (actual->sig != nullptr) {
                actual->sig->ant = actual->ant;
            } else {
                cola = actual->ant;    // Era la cola
            }

            delete actual;
            tamanio--;
            cout << "\n  [OK] Persona con cedula " << cedula
                 << " eliminada de Lista Doble." << endl;
            return;
        }
        actual = actual->sig;
    }
    cout << "\n  [!] Cedula " << cedula << " no encontrada en Lista Doble." << endl;
}

// Mostrar de cabeza a cola
void ListaDoble::mostrar() const {
    if (estaVacia()) {
        cout << "\n  [!] Lista Doble vacia." << endl;
        return;
    }
    cout << "\n  ============= LISTA DOBLE [" << tamanio << " elemento(s)] =============" << endl;
    cout << "  Recorrido: CABEZA --> COLA" << endl;
    Nodo* aux = cabeza;
    int   pos = 1;
    while (aux != nullptr) {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Polimorfismo virtual
        aux = aux->sig;
    }
    cout << "  =======================================================" << endl;
}

// Mostrar de cola a cabeza (bidireccional)
void ListaDoble::mostrarInverso() const {
    if (estaVacia()) {
        cout << "\n  [!] Lista Doble vacia." << endl;
        return;
    }
    cout << "\n  ============= LISTA DOBLE INVERSA =============" << endl;
    cout << "  Recorrido: COLA --> CABEZA" << endl;
    Nodo* aux = cola;
    int   pos = tamanio;
    while (aux != nullptr) {
        cout << "  [" << pos-- << "] ";
        aux->dato->mostrar();
        aux = aux->ant;
    }
    cout << "  ===============================================" << endl;
}

// Buscar por cedula
bool ListaDoble::buscar(const string& cedula) const {
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

void ListaDoble::liberarMemoria() {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        Nodo* siguiente = aux->sig;
        delete aux;
        aux = siguiente;
    }
    cabeza  = nullptr;
    cola    = nullptr;
    tamanio = 0;
}
