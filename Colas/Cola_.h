#ifndef COLA_H
#define COLA_H
#include "IOPERACION_COLA.h"
#include "Nodo.h"

class Cola : public IOPERACION_COLA {
private:
    Nodo* frente; 
    Nodo* final;  
public:
    Cola();
    

    bool buscar_G2(const std::string& cedulaBuscar) override;
};
#endif