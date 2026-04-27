#ifndef ICUENTA_H
#define ICUENTA_H

class ICuenta {
public:
    // Los 3 contratos de paso de parámetros
    virtual void depositarValor(double cantidad) = 0;
    virtual void depositarRef(double& billetera) = 0;
    virtual void depositarPtr(double* billetera) = 0;
    //destructor
    virtual ~ICuenta() = default;
};

#endif