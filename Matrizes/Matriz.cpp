#ifndef MATRIZ_CPP
#define MATRIZ_CPP

#include "Matriz.h"
#include <iostream> 

using namespace std;

template <class T>
void Matriz<T>::sumarRecursivoHelper(const Matriz<T>& otra, Matriz<T>& resultado, int p, int f, int c) const {
    if (p >= dim) return;
    *(*(*(resultado.matriz + p) + f) + c) = *(*(*(this->matriz + p) + f) + c) + *(*(*(otra.matriz + p) + f) + c);
    
    if (c + 1 < dim) sumarRecursivoHelper(otra, resultado, p, f, c + 1);
    else if (f + 1 < dim) sumarRecursivoHelper(otra, resultado, p, f + 1, 0);
    else sumarRecursivoHelper(otra, resultado, p + 1, 0, 0);
}

template <class T>
void Matriz<T>::restarRecursivoHelper(const Matriz<T>& otra, Matriz<T>& resultado, int p, int f, int c) const {
    if (p >= dim) return;
    *(*(*(resultado.matriz + p) + f) + c) = *(*(*(this->matriz + p) + f) + c) - *(*(*(otra.matriz + p) + f) + c);
    
    if (c + 1 < dim) restarRecursivoHelper(otra, resultado, p, f, c + 1);
    else if (f + 1 < dim) restarRecursivoHelper(otra, resultado, p, f + 1, 0);
    else restarRecursivoHelper(otra, resultado, p + 1, 0, 0);
}

template <class T>
Matriz<T>::Matriz(int d) {
    dim = d;
    matriz = (T***)malloc(dim * sizeof(T**));
    for (int p = 0; p < dim; p++) {
        *(matriz + p) = (T**)malloc(dim * sizeof(T*));
        for (int f = 0; f < dim; f++) {
            *(*(matriz + p) + f) = (T*)malloc(dim * sizeof(T));
        }
    }
}

template <class T>
Matriz<T>::Matriz(const Matriz<T>& otra) {
    dim = otra.dim;
    matriz = (T***)malloc(dim * sizeof(T**));
    for (int p = 0; p < dim; p++) {
        *(matriz + p) = (T**)malloc(dim * sizeof(T*));
        for (int f = 0; f < dim; f++) {
            *(*(matriz + p) + f) = (T*)malloc(dim * sizeof(T));
            for (int c = 0; c < dim; c++) {
                *(*(*(matriz + p) + f) + c) = *(*(*(otra.matriz + p) + f) + c);
            }
        }
    }
}

template <class T>
Matriz<T>::~Matriz() {
    for (int p = 0; p < dim; p++) {
        for (int f = 0; f < dim; f++) {
            free(*(*(matriz + p) + f));
        }
        free(*(matriz + p));
    }
    free(matriz);
}

template <class T>
void Matriz<T>::setElemento(int p, int f, int c, T valor) {
    *(*(*(matriz + p) + f) + c) = valor;
}

template <class T>
T Matriz<T>::getElemento(int p, int f, int c) const {
    return *(*(*(matriz + p) + f) + c);
}

template <class T>
int Matriz<T>::getDim() const {
    return dim;
}

template <class T>
void Matriz<T>::imprimir() const {
    for (int p = 0; p < dim; p++) {
        cout << "--- Capa " << p << " ---" << endl;
        for (int f = 0; f < dim; f++) {
            for (int c = 0; c < dim; c++) {
                cout << getElemento(p, f, c) << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

template <class T>
Matriz<T> Matriz<T>::operator+(const Matriz<T>& otra) const {
    Matriz<T> resultado(dim);
    sumarRecursivoHelper(otra, resultado, 0, 0, 0); 
    return resultado;
}

template <class T>
Matriz<T> Matriz<T>::operator-(const Matriz<T>& otra) const {
    Matriz<T> resultado(dim);
    restarRecursivoHelper(otra, resultado, 0, 0, 0); 
    return resultado;
}

template <class T>
Matriz<T> Matriz<T>::operator*(const Matriz<T>& otra) const {
    Matriz<T> resultado(dim);
    for (int p = 0; p < dim; p++) {
        for (int f = 0; f < dim; f++) {
            for (int c = 0; c < dim; c++) {
                T suma_prod = 0;
                for (int k = 0; k < dim; k++) {
                    suma_prod += getElemento(p, f, k) * otra.getElemento(p, k, c);
                }
                resultado.setElemento(p, f, c, suma_prod);
            }
        }
    }
    return resultado;
}

#endif