#ifndef MATRIZ_H
#define MATRIZ_H
#include "IMatriz.h"

class Matriz : public IMatriz {
private:
    int capa;
    int fila;
    int columna;
    float*** elemento;

    // --- FUNCIONES AUXILIARES RECURSIVAS ---
    void sumaRecursiva(const Matriz& a, const Matriz& b, Matriz& c, int z, int i, int j);
    void multRecursiva(const Matriz& a, const Matriz& b, Matriz& c, int z, int i, int j);
    float productoPuntoRecursivo(const Matriz& a, const Matriz& b, int z, int i, int j, int k) const;

public:
    Matriz(int cp, int f, int c);
    ~Matriz(); 
    void encerar(float*** elemento, int capa, int fila, int columna) override;
    void setElemento(int capa, int fila, int columna, float valor) override;
    float getElemento(int capa, int fila, int columna) const override;
    void setMatriz(float*** matriz) override;
    float*** getMatriz() const override;
    int getCapa() const override;
    void setCapa(int cp) override;
    int getFila() const override;
    void setFila(int f) override;
    int getColumna() const override;
    void setColumna(int c) override;
    
    // Operaciones (Métodos disparadores)
    void sumar(const Matriz& a, const Matriz& b, Matriz& c);
    void multiplicar(const Matriz& a, const Matriz& b, Matriz& c);
};

#endif