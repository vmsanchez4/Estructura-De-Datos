#ifndef AUTO_H
#define AUTO_H

#include "IAuto.h"
#include "../IEntrada.h"
#include "../ISalida.h"

class Auto : public IAuto, public IEntrada, public ISalida {
private:
    float combustible;

public:
    Auto(); // Constructor
    
    void ingresarDatos() override;
    void mostrarDatos() const override;
    
    void cargarValor(float litros) override;
    void cargarRef(float& surtidor) override;
    void cargarPtr(float* surtidor) override;
};

#endif