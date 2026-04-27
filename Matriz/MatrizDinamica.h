#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "ProcesoMatriz.h"

class MatrizDinamica : public ProcesoMatriz {
private:
    int** matriz;      // Puntero doble para crear la tabla en memoria dinámica
    int filas;         // Atributo para almacenar el número de filas
    int columnas;      // Atributo para almacenar el número de columnas

    void alojarMemoria();  // Método privado para reservar espacio en la RAM
    void liberarMemoria(); // Método privado para liberar espacio en la RAM

public:
    // Constructor: inicializa filas, columnas y reserva memoria
    MatrizDinamica(int f = 0, int c = 0);
    // Destructor: se ejecuta automáticamente al final para borrar la memoria
    ~MatrizDinamica();
    // Constructor de copia: para pasar objetos por valor de forma segura
    MatrizDinamica(const MatrizDinamica& otra);
    
    // Sobrecarga del operador de asignación (=)
    MatrizDinamica& operator=(const MatrizDinamica& otra);

    // Getters: permiten leer los datos privados desde fuera
    int getFilas() const;
    int getColumnas() const;
    int getValor(int f, int c) const;

    // Setters: permiten modificar los datos privados desde fuera
    void setValor(int f, int c, int v);

    // Métodos de operación (implementación de la interfaz)
    void sumar(const MatrizDinamica& m1, const MatrizDinamica& m2) override;
    void restar(const MatrizDinamica& m1, const MatrizDinamica& m2) override;
    void multiplicar(const MatrizDinamica& m1, const MatrizDinamica& m2) override;

    // Métodos de utilidad
    void llenarAleatorio();
    void mostrar() const;
};

#endif