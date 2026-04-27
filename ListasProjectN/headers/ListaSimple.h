#pragma once
#include "ListaBase.h"

// ============================================================
//  LISTA SIMPLE - Solo prototipos
// ============================================================
class ListaSimple : public ListaBase {
public:
    ListaSimple();
    ~ListaSimple() override;

    void insertar(Persona* persona)           override;
    void eliminar(const string& cedula)       override;
    void mostrar()                      const override;
    bool buscar(const string& cedula)   const override;

private:
    void liberarMemoria();
};
