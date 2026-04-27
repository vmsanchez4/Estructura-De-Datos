#pragma once
#include "Nodo.h"
#include <string>
using namespace std;

template <typename T>
class ListaBase {
protected:
    Nodo<T>* cabeza;
    int      tamanio;

public:
    ListaBase() : cabeza(nullptr), tamanio(0) {}
    virtual ~ListaBase() {}

    virtual void insertar(T* dato) = 0;
    virtual void eliminar(const string& clave) = 0;
    virtual void mostrar() const = 0;
    virtual bool buscar(const string& clave) const = 0;

    virtual bool estaVacia()  const {
        return cabeza == nullptr; }
        
    virtual int  getTamanio() const { 
        return tamanio; }
};
