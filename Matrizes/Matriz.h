#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstdlib>
#include "IMatriz.h"

template <class T>
class Matriz : public IMatriz<T> {
private:
    int dim;
    T*** matriz;

    void sumarRecursivoHelper(const Matriz<T>& otra, Matriz<T>& resultado, int p, int f, int c) const;
    void restarRecursivoHelper(const Matriz<T>& otra, Matriz<T>& resultado, int p, int f, int c) const;

public:
    Matriz(int d);
    Matriz(const Matriz<T>& otra);
    ~Matriz() override;

    void setElemento(int p, int f, int c, T valor) override;
    T getElemento(int p, int f, int c) const override;
    int getDim() const override;
    void imprimir() const override; 

    Matriz<T> operator+(const Matriz<T>& otra) const;
    Matriz<T> operator-(const Matriz<T>& otra) const;
    Matriz<T> operator*(const Matriz<T>& otra) const;
};

#include "Matriz.cpp"

#endif