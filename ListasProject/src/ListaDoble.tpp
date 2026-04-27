// ============================================================
//  IMPLEMENTACION TEMPLATE - ListaDoble<T>
//  Archivo .tpp incluido desde ListaDoble.h
//  Toda memoria dinamica usa malloc / free
// ============================================================
#include <iostream>
using namespace std;

// ---- Constructor ----
template <typename T>
ListaDoble<T>::ListaDoble() : ListaBase<T>(), cola(nullptr) {}

// ---- Destructor ----
template <typename T>
ListaDoble<T>::~ListaDoble() {
    liberarMemoria();
}

// ---- Insertar al final con malloc ----
template <typename T>
void ListaDoble<T>::insertar(T* dato) {
    Nodo<T>* nuevo = Nodo<T>::crear(dato);   // malloc interno

    if (this->estaVacia()) {
        this->cabeza = nuevo;
        cola         = nuevo;
    } else {
        nuevo->ant = cola;    // Nuevo apunta hacia atras a la cola actual
        cola->sig  = nuevo;   // Cola actual apunta al nuevo
        cola       = nuevo;   // Actualizar cola
    }
    this->tamanio++;
    cout << "  [OK] Insertado en Lista Doble. Total: "
         << this->tamanio << endl;
}

// ---- Eliminar por clave con free ----
template <typename T>
void ListaDoble<T>::eliminar(const string& clave) {
    if (this->estaVacia()) {
        cout << "  [!] Lista Doble vacia." << endl;
        return;
    }
    Nodo<T>* actual = this->cabeza;

    while (actual != nullptr) {
        if (actual->dato->getCedula() == clave) {
            // Reconectar punteros dobles
            if (actual->ant != nullptr)
                actual->ant->sig = actual->sig;
            else
                this->cabeza = actual->sig;

            if (actual->sig != nullptr)
                actual->sig->ant = actual->ant;
            else
                cola = actual->ant;

            Nodo<T>::destruir(actual);   // free interno
            this->tamanio--;
            cout << "  [OK] Cedula " << clave
                 << " eliminada de Lista Doble." << endl;
            return;
        }
        actual = actual->sig;
    }
    cout << "  [!] Cedula " << clave << " no encontrada." << endl;
}

// ---- Mostrar de cabeza a cola ----
template <typename T>
void ListaDoble<T>::mostrar() const {
    if (this->estaVacia()) {
        cout << "  [!] Lista Doble vacia." << endl;
        return;
    }
    cout << "\n  ===== LISTA DOBLE [" << this->tamanio
         << " elemento(s)] | CABEZA --> COLA =====" << endl;
    Nodo<T>* aux = this->cabeza;
    int pos = 1;
    while (aux != nullptr) {
        cout << "  [" << pos++ << "] ";
        aux->dato->mostrar();   // Polimorfismo virtual
        aux = aux->sig;
    }
    cout << "  =================================================" << endl;
}

// ---- Mostrar de cola a cabeza (bidireccional) ----
template <typename T>
void ListaDoble<T>::mostrarInverso() const {
    if (this->estaVacia()) {
        cout << "  [!] Lista Doble vacia." << endl;
        return;
    }
    cout << "\n  ===== LISTA DOBLE INVERSA | COLA --> CABEZA =====" << endl;
    Nodo<T>* aux = cola;
    int pos = this->tamanio;
    while (aux != nullptr) {
        cout << "  [" << pos-- << "] ";
        aux->dato->mostrar();
        aux = aux->ant;
    }
    cout << "  =================================================" << endl;
}

// ---- Buscar ----
template <typename T>
bool ListaDoble<T>::buscar(const string& clave) const {
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
void ListaDoble<T>::liberarMemoria() {
    Nodo<T>* aux = this->cabeza;
    while (aux != nullptr) {
        Nodo<T>* sig = aux->sig;
        Nodo<T>::destruir(aux);
        aux = sig;
    }
    this->cabeza  = nullptr;
    cola          = nullptr;
    this->tamanio = 0;
}
