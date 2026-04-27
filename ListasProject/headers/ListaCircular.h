#pragma once
#include "ListaBase.h"

// ============================================================
//  LISTA CIRCULAR TEMPLATE - Hereda de ListaBase<T>
// ============================================================
template <typename T>
class ListaCircular : public ListaBase<T> {
private:
    Nodo<T>* cola;

public:
    ListaCircular();
    ~ListaCircular() override;

    void insertar(T* dato)                  override;
    void eliminar(const string& clave)      override;
    void mostrar()                    const override;
    bool buscar(const string& clave)  const override;

    // Metodo extra: demostrar circularidad
    void recorrerVueltas(int vueltas) const;

private:
    void liberarMemoria();
};

#include "../src/ListaCircular.tpp"
