#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "IPersonaje.h"
#include "../IEntrada.h" // Buscamos la interfaz genérica afuera
#include "../ISalida.h"

// Firmamos los tres contratos (Herencia múltiple)
class Personaje : public IPersonaje, public IEntrada, public ISalida {
private:
    int salud;

public:
    Personaje(); // Constructor
    
    // Contratos de Entrada/Salida
    void ingresarDatos() override;
    void mostrarDatos() const override;
    
    // Contratos de Curación
    void curarValor(int pocion) override;
    void curarRef(int& pocion) override;
    void curarPtr(int* pocion) override;
};

#endif