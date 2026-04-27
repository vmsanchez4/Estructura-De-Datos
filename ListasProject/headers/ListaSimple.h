#pragma once
#include "ListaBase.h"

// ============================================================
//  LISTA SIMPLE TEMPLATE - Hereda de ListaBase<T>
//  La logica de los metodos va en ListaSimple.tpp
//  que se incluye al final de este archivo
// ============================================================
template <typename T>
class ListaSimple : public ListaBase<T> {
public:
    ListaSimple();
    ~ListaSimple() override;

    void insertar(T* dato)                  override;
    void eliminar(const string& clave)      override;
    void mostrar()                    const override;
    bool buscar(const string& clave)  const override;

private:
    void liberarMemoria();
};

// ---- Incluir implementacion (requerido por templates) ----
#include "../src/ListaSimple.tpp"
