#ifndef QUEBRADO_H
#define QUEBRADO_H

class Quebrado {
private:
    int numerador;
    int denominador;

public:
    Quebrado(int num = 0, int den = 1);

    int getNumerador() const;
    int getDenominador() const;
    void setNumerador(int num);
    void setDenominador(int den);
    
    void mostrar() const;
};

#endif