/***********************************************************************
 * Module:  Lista.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:38:09
 * Purpose: Declaration of the class Lista
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Lista_h)
#define __Class_Diagram_1_Lista_h
#include <string>
class Lista
{
public:
    virtual void insertarInicio(std::string cedula, std::string nombre)=0;
    virtual void insertarFinal(std::string cedula, std::string nombre)=0;
    virtual void eliminar(std::string cedula)=0;
    virtual bool buscar(std::string cedula)=0;
    virtual void mostrar(void)=0;
    virtual ~Lista() {}
protected:
private:

};

#endif
