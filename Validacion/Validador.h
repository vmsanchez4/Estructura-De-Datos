#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>
using namespace std;

class Validador {
public:
    virtual ~Validador() {}
    virtual bool validar(string cedula) = 0;
    virtual void contarPorProvincia() = 0;
};

#endif