/***********************************************************************
 * Module:  Quebrado.cpp
 * Author:  Vicente
 * Modified: jueves, 9 de abril de 2026 21:24:16
 * Purpose: Implementation of the class Quebrado
 ***********************************************************************/

#include "Quebrado.h"

////////////////////////////////////////////////////////////////////////
// Name:       Qurado::Quebrado()
// Purpose:    Implementation of Quebrado::Quebrado()
// Return:     
////////////////////////////////////////////////////////////////////////

Quebrado::Quebrado()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Quebrado::getDenominador()
// Purpose:    Implementation of Quebrado::getDenominador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Quebrado::getDenominador(void)
{
   return denominador;
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Quebrado::setNumerador3()
// Purpose:    Implementation of Quebrado::setNumerador3()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Quebrado::setNumerador(float num)
{
   numerador = num;
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Quebrado::getNumerador()
// Purpose:    Implementation of Quebrado::getNumerador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Quebrado::getNumerador(void)
{
   return numerador;
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Quebrado::setDenominador()
// Purpose:    Implementation of Quebrado::setDenominador()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Quebrado::setDenominador(float den)
{
   denominador = den;
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Quebrado::sumar()
// Purpose:    Implementation of Quebrado::sumar()
// Return:     Quebrado
////////////////////////////////////////////////////////////////////////

Quebrado Quebrado::sumar(Quebrado sum)
{
   Quebrado resultado;
    float nuevoNumerador = ((denominador*sum.getNumerador()) + (numerador*sum.getDenominador()) );

    float nuevoDenominador = denominador*sum.getDenominador();

    resultado.setDenominador(nuevoDenominador);
    resultado.setNumerador(nuevoNumerador);

    return resultado;
   // TODO : implement
}