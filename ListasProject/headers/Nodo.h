#pragma once
#include <cstdlib>   // malloc, free
#include <new>       // placement new
#include <stdexcept>

// ============================================================
//  NODO TEMPLATE con MALLOC
//  Los templates DEBEN tener la implementacion en el .h
//  porque el compilador necesita verla al instanciar.
// ============================================================
template <typename T>
class Nodo {
public:
    T*      dato;   // Puntero al dato (tipo generico)
    Nodo<T>* sig;   // Puntero al siguiente nodo
    Nodo<T>* ant;   // Puntero al anterior (lista doble)

    // ---- Constructor por defecto ----
    Nodo() : dato(nullptr), sig(nullptr), ant(nullptr) {}

    // ---- Constructor con dato ----
    explicit Nodo(T* pDato) : dato(pDato), sig(nullptr), ant(nullptr) {}

    // ---- Destructor: libera el dato con free ----
    ~Nodo() {
        if (dato != nullptr) {
            dato->~T();        // Destructor explicito (placement new requiere esto)
            free(dato);        // Liberar memoria con free
            dato = nullptr;
        }
    }

    // ---- Fabrica estatica: crea un Nodo con malloc ----
    // Retorna puntero al nuevo Nodo<T> alojado con malloc
    static Nodo<T>* crear(T* pDato) {
        // 1. Reservar memoria cruda para el Nodo con malloc
        void* mem = malloc(sizeof(Nodo<T>));
        if (mem == nullptr) {
            throw std::bad_alloc();
        }
        // 2. Construir el objeto en esa memoria (placement new)
        Nodo<T>* nodo = new (mem) Nodo<T>(pDato);
        return nodo;
    }

    // ---- Destruir un Nodo creado con malloc ----
    static void destruir(Nodo<T>* nodo) {
        if (nodo != nullptr) {
            nodo->~Nodo<T>();   // Destructor explicito
            free(nodo);          // Liberar con free
        }
    }
};
