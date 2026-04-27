#include "../headers/ListaCircular.h"
#include <iostream>
using namespace std;

// ============================================================
//  IMPLEMENTACION - ListaCircular
// ============================================================

ListaCircular::ListaCircular() : ListaBase(), cola(nullptr) {}

ListaCircular::~ListaCircular() {
    liberarMemoria();
}

// Insertar: el ultimo nodo siempre apunta de vuelta a cabeza
void ListaCircular::insertar(Persona* persona) {
    Nodo* nuevo = new Nodo(persona);

    if (estaVacia()) {
        cabeza     = nuevo;
        cola       = nuevo;
        nuevo->sig = cabeza;   // Apunta a si mismo (circular)
    } else {
        nuevo->sig = cabeza;   // El nuevo cierra el circulo
        cola->sig  = nuevo;    // La antigua cola apunta al nuevo
        cola       = nuevo;    // El nuevo es la nueva cola
    }
    tamanio++;
    cout << "\n  [OK] Persona insertada en Lista Circular." << endl;
}

// Eliminar por cedula manteniendo la circularidad
void ListaCircular::eliminar(const string& cedula) {
    if (estaVacia()) {
        cout << "\n  [!] Lista Circular vacia." << endl;
        return;
    }

    Nodo* actual   = cabeza;
    Nodo* anterior = cola;   // En circular el anterior a cabeza es cola

    for (int i = 0; i < tamanio; i++) {
        if (actual->dato->getCedula() == cedula) {

            if (tamanio == 1) {
                // Unico elemento
                cabeza = nullptr;
                cola   = nullptr;
            } else if (actual == cabeza) {
                cabeza    = actual->sig;
                cola->sig = cabeza;       // Cola re-cierra el circulo
            } else if (actual == cola) {
                cola      = anterior;
                cola->sig = cabeza;       // Nueva cola cierra el circulo
            } else {
                anterior->sig = actual->sig;
            }

            delete actual;
            tamanio--;
            cout << "\n  [OK] Persona con cedula " << cedula
                 << " eliminada de Lista Circular." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->sig;
    }
    cout << "\n  [!] Cedula " << cedula << " no encontrada en Lista Circular." << endl;
}

// Mostrar (una vuelta completa)
void ListaCircular::mostrar() const {
    if (estaVacia()) {
        cout << "\n  [!] Lista Circular vacia." << endl;
        return;
    }
    cout << "\n  ============= LISTA CIRCULAR [" << tamanio << " elemento(s)] =============" << endl;
    Nodo* aux = cabeza;
    int   pos = 1;
    do {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Polimorfismo virtual
        aux = aux->sig;
    } while (aux != cabeza);   // Condicion de parada: volver al inicio
    cout << "  (... regresa a [1] - es circular)" << endl;
    cout << "  =========================================================" << endl;
}

// Buscar por cedula
bool ListaCircular::buscar(const string& cedula) const {
    if (estaVacia()) return false;

    Nodo* aux = cabeza;
    do {
        if (aux->dato->getCedula() == cedula) {
            cout << "\n  [ENCONTRADO] ";
            aux->dato->mostrar();
            return true;
        }
        aux = aux->sig;
    } while (aux != cabeza);

    return false;
}

// Recorrer N vueltas para demostrar circularidad
void ListaCircular::recorrerVueltas(int vueltas) const {
    if (estaVacia()) {
        cout << "\n  [!] Lista Circular vacia." << endl;
        return;
    }
    cout << "\n  ===== RECORRIENDO " << vueltas << " VUELTA(S) =====" << endl;
    Nodo* aux   = cabeza;
    int   total = tamanio * vueltas;
    for (int i = 1; i <= total; i++) {
        cout << "  [Paso " << i << "] ";
        aux->dato->mostrar();
        aux = aux->sig;
    }
    cout << "  =====================================" << endl;
}

void ListaCircular::liberarMemoria() {
    if (estaVacia()) return;

    // Romper el circulo para poder iterar linealmente
    cola->sig = nullptr;

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
