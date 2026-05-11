/***********************************************************************
 * Module:  OperacionesCedula.cpp
 * Author:  ASUS
 * Modified: lunes, 4 de mayo de 2026 10:10:50
 * Purpose: Implementation of the class OperacionesCedula
 ***********************************************************************/

#include "OperacionesCedula.h"
#include <cctype>

bool OperacionesCedula::validarCedula(string cedula) {
    int suma = 0;
    int bandera=false;
    if (cedula.length()!=10)
        return false;
    for (char c : cedula) {
        if (!isdigit(c))
            return false;
    }
    int provincia=stoi(cedula.substr(0,2));
    if (provincia < 1 || provincia > 24)
        return false;
    int tipoCedula = cedula[2] - '0';
    if (tipoCedula >= 6)
        return false;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9)
                digito -= 9;
        }
        suma+=digito;
    }
    int verificador=(10-(suma % 10))% 10;
    if(verificador==(cedula[9]-'0'))
        bandera=true;
    return bandera;
}
extern "C" __declspec(dllexport)
Validaciones* crearValidaciones() {
    return new OperacionesCedula();
}
