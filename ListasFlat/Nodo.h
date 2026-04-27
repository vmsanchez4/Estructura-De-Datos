#pragma once
#include <cstdlib>
#include <new>
#include <stdexcept>

template <typename T>
class Nodo {
public:
    T* dato;
    Nodo<T>* sig;
    Nodo<T>* ant;

    Nodo() : dato(nullptr), sig(nullptr), ant(nullptr) {}
    explicit Nodo(T* p) : dato(p), sig(nullptr), ant(nullptr) {}

    ~Nodo() {
        if (dato) {
            dato->~T();
            free(dato);
            dato = nullptr;
        }
    }

    // Fabrica: reserva el Nodo con malloc + placement new
    static Nodo<T>* crear(T* p) {
        void* mem = malloc(sizeof(Nodo<T>));
        if (!mem) throw std::bad_alloc();
        return new (mem) Nodo<T>(p);
    }

    // Destruir: destructor explicito + free
    static void destruir(Nodo<T>* n) {
        if (n) { n->~Nodo<T>(); free(n); }
    }
};
