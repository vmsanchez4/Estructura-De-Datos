/***********************************************************************
 * Module:  Nodo.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:35:45
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h
#include <string>
using namespace std;
class Nodo
{
public:
   Nodo(std::string c, std::string n);
   ~Nodo();
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
    std::string cedula;
   std::string nombre;
   Nodo* anterior;
   Nodo* siguiente;

protected:
private:
};

#endif
