#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include <iostream>
#include <cstdlib> // Para rand()
#include "ProcesoMatriz.h"

using namespace std;

// Convertimos la clase en una plantilla genérica
template <typename T>
class MatrizDinamica : public ProcesoMatriz<T> {
private:
    T** matriz;        // Puntero doble del tipo genérico T
    int filas;
    int columnas;

    void alojarMemoria() {
        if (filas <= 0 || columnas <= 0) return;
        matriz = new T*[filas];
        for (int i = 0; i < filas; ++i) {
            matriz[i] = new T[columnas]();
        }
    }
    
    void liberarMemoria() {
        if (matriz != nullptr) {
            for (int i = 0; i < filas; ++i) delete[] matriz[i];
            delete[] matriz;
            matriz = nullptr;
        }
    }

public:
    MatrizDinamica(int f = 0, int c = 0) : filas(f), columnas(c) {
        alojarMemoria();
    }

    ~MatrizDinamica() {
        liberarMemoria();
    }

    MatrizDinamica(const MatrizDinamica<T>& otra) {
        filas = otra.filas;
        columnas = otra.columnas;
        alojarMemoria();
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                matriz[i][j] = otra.matriz[i][j];
    }
    
    MatrizDinamica<T>& operator=(const MatrizDinamica<T>& otra) {
        if (this != &otra) {
            liberarMemoria();
            filas = otra.filas;
            columnas = otra.columnas;
            alojarMemoria();
            for (int i = 0; i < filas; i++)
                for (int j = 0; j < columnas; j++)
                    matriz[i][j] = otra.matriz[i][j];
        }
        return *this;
    }

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    
    // Retorna y recibe tipo T
    T getValor(int f, int c) const { return matriz[f][c]; }
    void setValor(int f, int c, T v) { matriz[f][c] = v; }

    void sumar(const MatrizDinamica<T>& m1, const MatrizDinamica<T>& m2) override {
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                this->matriz[i][j] = m1.matriz[i][j] + m2.matriz[i][j];
    }

    void llenarAleatorio() {
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
            matriz[i][j] = static_cast<T>(rand() % 9 + 1); // Forzamos conversión a T
    }

    void mostrar() const {
        for (int i = 0; i < filas; i++) {
            cout << "[ ";
            for (int j = 0; j < columnas; j++) 
                cout << matriz[i][j] << "\t";
            cout << "]" << endl;
        }
    }
};

#endif