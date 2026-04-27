#ifndef IAUTO_H
#define IAUTO_H

class IAuto {
public:
    virtual void cargarValor(float litros) = 0;
    virtual void cargarRef(float& surtidor) = 0;
    virtual void cargarPtr(float* surtidor) = 0;
    
    virtual ~IAuto() = default;
};

#endif