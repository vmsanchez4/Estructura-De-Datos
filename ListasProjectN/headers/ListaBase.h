#pragma once
#include "Nodo.h"

// ============================================================
//  CLASE ABSTRACTA LISTA BASE - Solo prototipos
// ============================================================
class ListaBase {
protected:
    Nodo* cabeza;
    int   tamanio;

public:
    ListaBase();
    virtual ~ListaBase();

    // Metodos virtuales puros => interfaz obligatoria
    virtual void insertar(Persona* persona)            = 0;
    virtual void eliminar(const string& cedula)        = 0;
    virtual void mostrar()                       const = 0;
    virtual bool buscar(const string& cedula)    const = 0;

    // Metodos concretos comunes
    virtual bool   estaVacia() const;
    virtual int    getTamanio() const;
};
