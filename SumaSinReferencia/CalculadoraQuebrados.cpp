#include "CalculadoraQuebrados.h"

Quebrado CalculadoraQuebrados::suma(Quebrado q1, Quebrado q2) {
    // Aplicamos la fórmula matemática usando los getters
    int nuevoNum = (q1.getNumerador() * q2.getDenominador()) + (q2.getNumerador() * q1.getDenominador());
    int nuevoDen = q1.getDenominador() * q2.getDenominador();
    
    return Quebrado(nuevoNum, nuevoDen);
}