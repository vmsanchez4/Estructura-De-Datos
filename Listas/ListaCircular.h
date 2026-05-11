/***********************************************************************
 * Module:  ListaCircular.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:48
 * Purpose: Declaration of the class ListaCircular
 ***********************************************************************/

#if !defined(__Class_Diagram_1_ListaCircular_h)
#define __Class_Diagram_1_ListaCircular_h
#include "Lista.h"
#include "Nodo.h"
#include <string>

class ListaCircular : public Lista{
public:
   ListaCircular();
   ~ListaCircular();
    void insertarInicio(std::string c, std::string n);
    void insertarFinal(std::string c, std::string n);
    void eliminar(std::string c);
    bool buscar(std::string c);
    void mostrar();
protected:
private:
    Nodo* cabeza;

};

#endif
