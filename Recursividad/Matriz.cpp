#include "Matriz.h"
#include <iostream>
#include <cstdlib>

Matriz::Matriz(int cp, int f, int c) {
    this->capa = cp;
    this->fila = f;
    this->columna = c;
    
    elemento = (float***)malloc(capa * sizeof(float**));
    for(int z = 0; z < capa; z++) {
        *(elemento + z) = (float**)malloc(fila * sizeof(float*));
        for(int i = 0; i < fila; i++) {
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
            free(*(*(elemento + z) + i)); 
        }
        free(*(elemento + z)); 
    }
    free(elemento); 
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

// ==============================================
// ====== MÉTODOS VOID (Disparadores) ===========
// ==============================================

void Matriz::sumar(const Matriz& a, const Matriz& b, Matriz& c) {
    sumaRecursiva(a, b, c, 0, 0, 0);
}

void Matriz::multiplicar(const Matriz& a, const Matriz& b, Matriz& c) {
    multRecursiva(a, b, c, 0, 0, 0);
}

// ==============================================
// ====== LÓGICA RECURSIVA PRIVADA ==============
// ==============================================

void Matriz::sumaRecursiva(const Matriz& a, const Matriz& b, Matriz& c, int z, int i, int j) {
    if (z >= capa) return; 
    
    if (i >= fila) {
        sumaRecursiva(a, b, c, z + 1, 0, 0); 
        return;
    }
    
    if (j >= columna) {
        sumaRecursiva(a, b, c, z, i + 1, 0); 
        return;
    }
    
    *(*(*(c.elemento + z) + i) + j) = *(*(*(a.elemento + z) + i) + j) + *(*(*(b.elemento + z) + i) + j);
    
    sumaRecursiva(a, b, c, z, i, j + 1);
}

void Matriz::multRecursiva(const Matriz& a, const Matriz& b, Matriz& c, int z, int i, int j) {
    if (z >= capa) return; 
    
    if (i >= a.fila) {
        multRecursiva(a, b, c, z + 1, 0, 0);
        return;
    }
    
    if (j >= b.columna) {
        multRecursiva(a, b, c, z, i + 1, 0);
        return;
    }
    
    float suma = productoPuntoRecursivo(a, b, z, i, j, 0);
    *(*(*(c.elemento + z) + i) + j) = suma;
    
    multRecursiva(a, b, c, z, i, j + 1);
}

float Matriz::productoPuntoRecursivo(const Matriz& a, const Matriz& b, int z, int i, int j, int k) const {
    if (k >= a.columna) return 0; 
    
    float productoActual = (*(*(*(a.elemento + z) + i) + k)) * (*(*(*(b.elemento + z) + k) + j));
    return productoActual + productoPuntoRecursivo(a, b, z, i, j, k + 1);
}