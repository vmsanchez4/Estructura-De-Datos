#pragma once
#include "Persona.h"
#include <string>

using namespace std;

struct Nodo {
    Persona* dato;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaBase {
protected:
    Nodo* cabeza;
    int tamanio;

public:
    ListaBase();
    virtual ~ListaBase();

    virtual void insertar(Persona* persona) = 0;
    virtual void eliminar(const string& cedula) = 0;
    virtual void modificar(const string& cedula, const string& nuevoNombre) = 0;
    virtual void mostrar() const = 0;
    virtual bool buscar(const string& cedula) const = 0;

    bool estaVacia() const;
    int getTamanio() const;
};