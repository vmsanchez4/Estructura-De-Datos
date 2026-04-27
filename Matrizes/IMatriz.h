#ifndef IMATRIZ_H
#define IMATRIZ_H

template <class T>
class IMatriz {
public:
    virtual void setElemento(int p, int f, int c, T valor) = 0; 
    virtual T getElemento(int p, int f, int c) const = 0;
    virtual int getDim() const = 0;
    virtual void imprimir() const = 0; 
    virtual ~IMatriz() {}
};

#endif