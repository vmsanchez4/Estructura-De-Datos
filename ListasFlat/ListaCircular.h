#pragma once
#include "ListaBase.h"

template <typename T>
class ListaCircular : public ListaBase<T> {
private:
    Nodo<T>* cola;
public:
    ListaCircular();
    ~ListaCircular() override;

    void insertar(T* dato) override;
    void eliminar(const string& clave) override;
    void mostrar() const override;
    bool buscar(const string& clave) const override;

    void recorrerVueltas(int vueltas) const;

private:
    void liberarMemoria();
};

#include "ListaCircular.cpp"
