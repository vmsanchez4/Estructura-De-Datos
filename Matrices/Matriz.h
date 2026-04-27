#ifndef MATRIZ_H
#define MATRIZ_H
#include "IMatriz.h"

class Matriz : public IMatriz {
private:
    /* --- ATRIBUTOS 2D COMENTADOS ---
    int fila;
    int columna;
    float** elemento;
    ---------------------------------- */

    int capa;
    int fila;
    int columna;
    float*** elemento;
    

public:
    /*
    Matriz(int f, int c);
    ~Matriz(); 
    void encerar(float** elemento, int fila, int columna) override;
    void setElemento(int fila, int columna, float valor) override;
    float getElemento(int fila, int columna) const override;
    void setMatriz(float** matriz) override;
    float** getMatriz() const override;
    int getFila() const override;
    void setFila(int f) override;
    int getColumna() const override;
    void setColumna(int c) override;
    void sumar(const Matriz& a, const Matriz& b, Matriz& c);
    void multiplicar(const Matriz& a, const Matriz& b, Matriz& c);
    */

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
    
    void sumar(const Matriz& a, const Matriz& b, Matriz& c);
    void multiplicar(const Matriz& a, const Matriz& b, Matriz& c);
};

#endif