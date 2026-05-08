#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo {
private:
    string cedula;
    string nombre;
    Nodo* siguiente;

public:
    Nodo(string cedula, string nombre, Nodo* siguiente);
    Nodo();

    void setCedula(string cedula);
    void setNombre(string nombre);
    void setSiguiente(Nodo* siguiente);

    string getCedula() const;
    string getNombre() const;
    Nodo* getSiguiente() const;
};

#endif