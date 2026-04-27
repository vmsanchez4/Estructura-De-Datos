// ============================================================
//  IMPLEMENTACION TEMPLATE - ListaSimple<T>
//  Archivo .tpp incluido desde ListaSimple.h
//  Toda memoria dinamica usa malloc / free
// ============================================================
#include <iostream>
#include <iomanip>
using namespace std;

// ---- Constructor ----
template <typename T>
ListaSimple<T>::ListaSimple() : ListaBase<T>() {}

// ---- Destructor ----
template <typename T>
ListaSimple<T>::~ListaSimple() {
    liberarMemoria();
}

// ---- Insertar al final con malloc ----
template <typename T>
void ListaSimple<T>::insertar(T* dato) {
    // Crear Nodo con malloc mediante fabrica estatica
    Nodo<T>* nuevo = Nodo<T>::crear(dato);

    if (this->estaVacia()) {
        this->cabeza = nuevo;
    } else {
        Nodo<T>* aux = this->cabeza;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    this->tamanio++;
    cout << "  [OK] Insertado en Lista Simple. Total: "
         << this->tamanio << endl;
}

// ---- Eliminar por clave con free ----
template <typename T>
void ListaSimple<T>::eliminar(const string& clave) {
    if (this->estaVacia()) {
        cout << "  [!] Lista Simple vacia." << endl;
        return;
    }
    Nodo<T>* actual   = this->cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato->getCedula() == clave) {
            if (anterior == nullptr)
                this->cabeza = actual->sig;
            else
                anterior->sig = actual->sig;

            // Destruir el Nodo liberando con free
            Nodo<T>::destruir(actual);
            this->tamanio--;
            cout << "  [OK] Cedula " << clave
                 << " eliminada de Lista Simple." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->sig;
    }
    cout << "  [!] Cedula " << clave << " no encontrada." << endl;
}

// ---- Mostrar ----
template <typename T>
void ListaSimple<T>::mostrar() const {
    if (this->estaVacia()) {
        cout << "  [!] Lista Simple vacia." << endl;
        return;
    }
    cout << "\n  ===== LISTA SIMPLE [" << this->tamanio << " elemento(s)] =====" << endl;
    Nodo<T>* aux = this->cabeza;
    int pos = 1;
    while (aux != nullptr) {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Polimorfismo virtual
        aux = aux->sig;
    }
    cout << "  =================================================" << endl;
}

// ---- Buscar ----
template <typename T>
bool ListaSimple<T>::buscar(const string& clave) const {
    Nodo<T>* aux = this->cabeza;
    while (aux != nullptr) {
        if (aux->dato->getCedula() == clave) {
            cout << "  [ENCONTRADO] ";
            aux->dato->mostrar();
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

// ---- Liberar toda la memoria con free ----
template <typename T>
void ListaSimple<T>::liberarMemoria() {
    Nodo<T>* aux = this->cabeza;
    while (aux != nullptr) {
        Nodo<T>* sig = aux->sig;
        Nodo<T>::destruir(aux);   // free interno
        aux = sig;
    }
    this->cabeza  = nullptr;
    this->tamanio = 0;
}
