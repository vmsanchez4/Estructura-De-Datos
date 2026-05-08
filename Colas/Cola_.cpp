#include "Cola_.h"
#include <iostream>
#include <stdexcept>

Cola::Cola() {
    this->frente = nullptr;
    this->final = nullptr;
}


bool Cola::buscar_G2(const std::string& cedulaBuscar) {
    Cola colaAuxiliar;
    bool loEncontre = false;

    while (this->frente != nullptr) {
        Persona personaActual = desencolar();
        
        if (personaActual.getCedula() == cedulaBuscar) {
            loEncontre = true;
        }
        
        colaAuxiliar.encolar(personaActual); 
    }

 
    while (colaAuxiliar.frente != nullptr) {
        this->encolar(colaAuxiliar.desencolar());
    }

    return loEncontre;
}

