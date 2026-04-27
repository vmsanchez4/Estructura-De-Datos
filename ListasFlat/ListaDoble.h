#pragma once
#include "ListaBase.h"

template <typename T>
class ListaDoble : public ListaBase<T> {
private:
    Nodo<T>* cola;
public:
    ListaDoble();
    ~ListaDoble() override;

    void insertar(T* dato) override;
    void eliminar(const string& clave) override;
    void mostrar() const override;
    bool buscar(const string& clave) const override;

    void mostrarInverso() const;

private:
    void liberarMemoria();
};

#include "ListaDoble.cpp"
