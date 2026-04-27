#ifndef CUENTA_H
#define CUENTA_H
#include "ICuenta.h"
#include "../IEntrada.h"
#include "../ISalida.h"

class Cuenta : public ICuenta, public IEntrada, public ISalida {
private:
    double saldo;
public:
    Cuenta();
    void ingresarDatos() override;
    void mostrarDatos() const override;
    void depositarValor(double cantidad) override;
    void depositarRef(double& billetera) override;
    void depositarPtr(double* billetera) override;
};
#endif