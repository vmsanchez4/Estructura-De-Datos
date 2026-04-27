#pragma once
#include "Nodo.h"
#include <string>
#include <iostream>
using namespace std;

// ============================================================
//  LISTA BASE TEMPLATE ABSTRACTA con MALLOC
//  Template + virtual puro = interfaz generica obligatoria
// ============================================================
template <typename T>
class ListaBase {
protected:
    Nodo<T>* cabeza;
    int      tamanio;

public:
    // ---- Constructor ----
    ListaBase() : cabeza(nullptr), tamanio(0) {}

    // ---- Destructor virtual (polimorfico) ----
    virtual ~ListaBase() {}

    // ---- Metodos virtuales puros => subclases DEBEN implementarlos ----
    virtual void insertar(T* dato)                    = 0;
    virtual void eliminar(const string& clave)        = 0;
    virtual void mostrar()                      const = 0;
    virtual bool buscar(const string& clave)    const = 0;

    // ---- Metodos concretos comunes ----
    virtual bool estaVacia()   const { return cabeza == nullptr; }
    virtual int  getTamanio()  const { return tamanio; }
};
