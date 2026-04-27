
#ifndef PROCESO_H
#define PROCESO_H

class Quebrado;

class Proceso {
public:
    virtual void sumar(const Quebrado& q1, const Quebrado& q2) = 0;
    virtual void mostrar() const = 0;
    virtual ~Proceso() = default;
};
#endif 