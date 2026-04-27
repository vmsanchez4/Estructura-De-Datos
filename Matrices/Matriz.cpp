#include "Matriz.h"
#include <iostream>
#include <cstdlib>

/*
Matriz::Matriz(int f, int c) {
    this->fila = f;
    this->columna = c;
    elemento = (float**)malloc(fila * sizeof(float*));
    for(int i = 0; i < fila; i++) {
        *(elemento + i) = (float*)malloc(columna * sizeof(float));
        for(int j = 0; j < columna; j++) {
            *(*(elemento + i) + j) = 0;
        }
    }
}

Matriz::~Matriz() {
    for(int i = 0; i < fila; i++) {
        free(*(elemento + i));
    }
    free(elemento);
}

void Matriz::sumar(const Matriz& a, const Matriz& b, Matriz& c) {
    for(int i = 0; i < fila; i++) {
        for(int j = 0; j < columna; j++) {
            *(*(c.elemento + i) + j) = *(*(a.elemento + i) + j) + *(*(b.elemento + i) + j);
        }
    }
}

void Matriz::multiplicar(const Matriz& a, const Matriz& b, Matriz& c) {
    for(int i = 0; i < a.fila; i++) {
        for(int j = 0; j < b.columna; j++) {
            float suma = 0;
            for(int k = 0; k < a.columna; k++) {
                suma += (*(*(a.elemento + i) + k)) * (*(*(b.elemento + k) + j));
            }
            *(*(c.elemento + i) + j) = suma;
        }
    }
}
*/


Matriz::Matriz(int cp, int f, int c) {
    this->capa = cp;
    this->fila = f;
    this->columna = c;
    // Nivel 1: Capas (Profundidad)
    elemento = (float***)malloc(capa * sizeof(float**));
    for(int z = 0; z < capa; z++) {
        // Nivel 2: Filas
        *(elemento + z) = (float**)malloc(fila * sizeof(float*));
        for(int i = 0; i < fila; i++) {
            // Nivel 3: Columnas
            *(*(elemento + z) + i) = (float*)malloc(columna * sizeof(float));
            for(int j = 0; j < columna; j++) {
                *(*(*(elemento + z) + i) + j) = 0;
            }
        }
    }
}

Matriz::~Matriz() {
    for(int z = 0; z < capa; z++) {
        for(int i = 0; i < fila; i++) {
            free(*(*(elemento + z) + i)); // Libera columnas
        }
        free(*(elemento + z)); // Libera filas
    }
    free(elemento); // Libera capas
}

void Matriz::encerar(float*** elemento, int capa, int fila, int columna) {
    for(int z = 0; z < capa; z++) {
        for(int i = 0; i < fila; i++) {
            for(int j = 0; j < columna; j++) {
                elemento[z][i][j] = 0;
            }
        }
    }
}

void Matriz::setElemento(int cp, int f, int c, float valor) {
    *(*(*(elemento + cp) + f) + c) = valor;
}

float Matriz::getElemento(int cp, int f, int c) const {
    return *(*(*(elemento + cp) + f) + c);
}

void Matriz::setMatriz(float*** matriz) { this->elemento = matriz; }
float*** Matriz::getMatriz() const { return this->elemento; }
int Matriz::getCapa() const { return capa; }
void Matriz::setCapa(int cp) { this->capa = cp; }
int Matriz::getFila() const { return fila; }
void Matriz::setFila(int f) { this->fila = f; }
int Matriz::getColumna() const { return columna; }
void Matriz::setColumna(int c) { this->columna = c; }

//
void Matriz::sumar(const Matriz& a, const Matriz& b, Matriz& c) {
    for(int z = 0; z < capa; z++) {
        for(int i = 0; i < fila; i++) {
            for(int j = 0; j < columna; j++) {
                *(*(*(c.elemento + z) + i) + j) = 
                *(*(*(a.elemento + z) + i) + j) + *(*(*(b.elemento + z) + i) + j);
            }
        }
    }
}

void Matriz::multiplicar(const Matriz& a, const Matriz& b, Matriz& c) {
    for(int z = 0; z < capa; z++) {
        for(int i = 0; i < a.fila; i++) {
            for(int j = 0; j < b.columna; j++) {
                float suma = 0;
                for(int k = 0; k < a.columna; k++) {
                    suma += (*(*(*(a.elemento + z) + i) + k)) * (*(*(*(b.elemento + z) + k) + j));
                }
                *(*(*(c.elemento + z) + i) + j) = suma;
            }
        }
    }
}