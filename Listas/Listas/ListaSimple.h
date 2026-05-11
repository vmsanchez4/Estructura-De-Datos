/***********************************************************************
 * Module:  ListaSimple.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:55:23
 * Purpose: Declaration of the class ListaSimple
 ***********************************************************************/

#if !defined(__Class_Diagram_1_ListaSimple_h)
#define __Class_Diagram_1_ListaSimple_h
#include "Lista.h"
#include "Nodo.h"
#include <string>
using namespace std;
class ListaSimple : public Lista
{
public:
    ListaSimple();
   ~ListaSimple();
    void insertarInicio(string c, string n);
    void insertarFinal(string c, string n);
    void eliminar(string c);
    bool buscar(string c);
    void mostrar();
protected:
private:
    Nodo* cabeza;
};

#endif
