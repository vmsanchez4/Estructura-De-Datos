/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:35:45
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:
////////////////////////////////////////////////////////////////////////

Nodo::Nodo(string c, string n)
{
    cedula = c;
    nombre = n;
    siguiente = nullptr;
    anterior = nullptr;
}



Nodo::~Nodo()
{
   // TODO : implement
}



std::string Nodo::getCedula(void)
{
   return cedula;
}



void Nodo::setCedula(std::string newCedula)
{
   cedula = newCedula;
}



std::string Nodo::getNombre(void)
{
   return nombre;
}


void Nodo::setNombre(std::string newNombre)
{
   nombre = newNombre;
}
