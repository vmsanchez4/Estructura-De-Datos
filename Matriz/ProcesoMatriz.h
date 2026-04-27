#ifndef PROCESOMATRIZ_H
#define PROCESOMATRIZ_H

// Declaración anticipada: le dice al compilador que la clase existe pero se define luego
class MatrizDinamica; 

class ProcesoMatriz {
public:
    // Métodos virtuales puros (=0): obligan a la clase hija a implementarlos
    // Usamos referencias (&) para pasar los objetos sin duplicar memoria
    virtual void sumar(const MatrizDinamica& m1, const MatrizDinamica& m2) = 0;
    virtual void restar(const MatrizDinamica& m1, const MatrizDinamica& m2) = 0;
    virtual void multiplicar(const MatrizDinamica& m1, const MatrizDinamica& m2) = 0;
    
    // Destructor virtual para asegurar que la memoria se limpie correctamente en herencia
    virtual ~ProcesoMatriz() = default;
};

#endif