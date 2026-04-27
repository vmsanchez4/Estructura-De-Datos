#include <iostream>
#include <cstdlib> // Para rand()
#include "MatrizDinamica.h"

using namespace std;

// Reserva memoria dinámica para una matriz de f x c
void MatrizDinamica::alojarMemoria() {
    if (filas <= 0 || columnas <= 0) 
    return; // Validación básica
    matriz = new int*[filas];               // Crea un arreglo de punteros (filas)
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas]();    // Crea un arreglo de enteros para cada fila
    }
}

// Borra la memoria de la RAM para evitar fugas 
void MatrizDinamica::liberarMemoria() {
    if (matriz != nullptr) {                // Si la matriz existe
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i];             // Borra cada fila
        }
        delete[] matriz;                    // Borra el arreglo de punteros
        matriz = nullptr;                   // Evita punteros colgados
    }
}

// Constructor: asigna dimensiones y pide memoria
MatrizDinamica::MatrizDinamica(int f, int c) : filas(f), columnas(c) {
    alojarMemoria();
}

// Destructor: limpia la memoria automáticamente
MatrizDinamica::~MatrizDinamica() {
    liberarMemoria();
}

// Constructor de copia: clona otra matriz en una nueva
MatrizDinamica::MatrizDinamica(const MatrizDinamica& otra) {
    filas = otra.filas;
    columnas = otra.columnas;
    alojarMemoria();
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = otra.matriz[i][j];
}

// Operador de asignación: permite hacer m1 = m2 de forma segura
MatrizDinamica& MatrizDinamica::operator=(const MatrizDinamica& otra) {
    if (this != &otra) {                    // Evita auto-asignación
        liberarMemoria();                   // Borra memoria actual
        filas = otra.filas;
        columnas = otra.columnas;
        alojarMemoria();                    // Pide memoria nueva
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                matriz[i][j] = otra.matriz[i][j];
    }
    return *this;
}

// Getters y Setters básicos
int MatrizDinamica::getFilas() const {
    return filas; 
}
int MatrizDinamica::getColumnas() const { 
    return columnas; 
}
int MatrizDinamica::getValor(int f, int c) const { 
    return matriz[f][c]; 
}
void MatrizDinamica::setValor(int f, int c, int v) { 
    matriz[f][c] = v; 
}

// Suma: recorre ambas matrices y guarda el resultado en 'this'
void MatrizDinamica::sumar(const MatrizDinamica& m1, const MatrizDinamica& m2) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            this->matriz[i][j] = m1.matriz[i][j] + m2.matriz[i][j];
}

// Resta: recorre ambas matrices y guarda el resultado en 'this'
void MatrizDinamica::restar(const MatrizDinamica& m1, const MatrizDinamica& m2) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            this->matriz[i][j] = m1.matriz[i][j] - m2.matriz[i][j];
}

// Multiplicación: Algoritmo de filas por columnas
void MatrizDinamica::multiplicar(const MatrizDinamica& m1, const MatrizDinamica& m2) {
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            this->matriz[i][j] = 0; // Inicializa la celda en 0
            for (int k = 0; k < m1.columnas; k++) {
                // Suma de los productos de la fila de m1 por la columna de m2
                this->matriz[i][j] += m1.matriz[i][k] * m2.matriz[k][j];
            }
        }
    }
}

// Genera números aleatorios entre 1 y 9
void MatrizDinamica::llenarAleatorio() {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = rand() % 9 + 1;
}

// Imprime la matriz de forma estética
void MatrizDinamica::mostrar() const {
    for (int i = 0; i < filas; i++) {
        cout << "[ ";
        for (int j = 0; j < columnas; j++) 
        cout << matriz[i][j] << "\t";
        cout << "]" << endl;
    }
}