/***********************************************************************
 * Module:  ListaCircularDoble.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:56:06
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#if !defined(__Class_Diagram_1_ListaCircularDoble_h)
#define __Class_Diagram_1_ListaCircularDoble_h
#include "Lista.h"
#include "Nodo.h"
#include <string>

class ListaCircularDoble : public Lista {
public:
   ListaCircularDoble();
   ~ListaCircularDoble();
    void insertarInicio(std::string c, std::string n);
    void insertarFinal(std::string c, std::string n);
    void eliminar(std::string c);
    bool buscar(std::string c);
    void mostrar();
    void insertarEntre(std::string c, std::string n, std::string cPos);
protected:
private:
    Nodo* cabeza;

};

#endif
