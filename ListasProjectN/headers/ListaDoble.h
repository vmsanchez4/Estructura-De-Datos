#pragma once
#include "ListaBase.h"

// ============================================================
//  LISTA DOBLE - Solo prototipos
// ============================================================
class ListaDoble : public ListaBase {
private:
    Nodo* cola;   // Puntero al ultimo nodo

public:
    ListaDoble();
    ~ListaDoble() override;

    void insertar(Persona* persona)           override;
    void eliminar(const string& cedula)       override;
    void mostrar()                      const override;
    bool buscar(const string& cedula)   const override;

    // Metodo extra: recorrer de cola a cabeza
    void mostrarInverso() const;

private:
    void liberarMemoria();
};
