/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:35:45
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::Nodo(String c, String n)
{
    cedula = c;
    nombre = n;
    sig = nullptr;
    ant = nullptr;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::~Nodo()
// Purpose:    Implementation of Nodo::~Nodo()
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::~Nodo()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getCedula()
// Purpose:    Implementation of Nodo::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Nodo::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setCedula(std::string newCedula)
// Purpose:    Implementation of Nodo::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getNombre()
// Purpose:    Implementation of Nodo::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Nodo::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setNombre(std::string newNombre)
// Purpose:    Implementation of Nodo::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setNombre(std::string newNombre)
{
   nombre = newNombre;
}
