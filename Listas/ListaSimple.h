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
    void insertarInicio(std::string c, std::string n);
    void insertarFinal(std::string c, std::string n);
    void eliminar(std::string c);
    bool buscar(std::string c);
    void mostrar();
    Nodo* getCabeza();
    bool buscarNombre(string nombre);
protected:
private:
    Nodo* cabeza;
};

#endif
