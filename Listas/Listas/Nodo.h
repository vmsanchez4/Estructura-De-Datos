/***********************************************************************
 * Module:  Nodo.h
 * Author:  ASUS
 * Modified: domingo, 26 de abril de 2026 21:35:45
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h
#include <string>
class Nodo
{
public:
   Nodo();
   ~Nodo();
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);

protected:
private:
   std::string cedula;
   std::string nombre;
   Nodo* anterior;
   Nodo* siguiente;


};

#endif
