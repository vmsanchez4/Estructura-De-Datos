/***********************************************************************
 * Module:  ListaDoble.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:35
 * Purpose: Declaration of the class ListaDoble
 ***********************************************************************/

#if !defined(__Class_Diagram_1_ListaDoble_h)
#define __Class_Diagram_1_ListaDoble_h
#include "Lista.h"
#include "Nodo.h"
#include <string>
using namespace std;

class ListaDoble : public Lista{
public:
    ListaDoble();
   ~ListaDoble();
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
