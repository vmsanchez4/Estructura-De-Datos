/***********************************************************************
 * Module:  OperacionesCedula.h
 * Author:  ASUS
 * Modified: lunes, 4 de mayo de 2026 10:10:50
 * Purpose: Declaration of the class OperacionesCedula
 ***********************************************************************/

#if !defined(__Class_Diagram_1_OperacionesCedula_h)
#define __Class_Diagram_1_OperacionesCedula_h

#include "Validaciones.h"
#include <string>

using namespace std;

class OperacionesCedula : public Validaciones {
public:
    bool validarCedula(string cedula) override;
};

#endif
