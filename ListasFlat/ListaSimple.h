#pragma once
#include "ListaBase.h"

template <typename T>
class ListaSimple : public ListaBase<T> {
public:
    ListaSimple();
    ~ListaSimple() override;

    void insertar(T* dato) override;
    void eliminar(const string& clave) override;
    void mostrar() const override;
    bool buscar(const string& clave) const override;

private:
    void liberarMemoria();
};

// Template: implementacion en el mismo .h via archivo separado incluido
#include "ListaSimple.cpp"
