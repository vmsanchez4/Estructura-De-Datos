/***********************************************************************
 * Module:  Validaciones.h
 * Author:  ASUS
 * Modified: lunes, 4 de mayo de 2026 10:10:06
 * Purpose: Declaration of the class Validaciones
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Validaciones_h)
#define __Class_Diagram_1_Validaciones_h
#include <string>
#define API __declspec(dllexport)

class API Validaciones {
public:
    virtual bool validarCedula(std::string c) = 0;
    virtual ~Validaciones() {}
};

#endif
