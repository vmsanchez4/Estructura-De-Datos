#ifndef NODOS_H
#define NODOS_H
struct NodoProvincia { char* codigo; char* nombre; NodoProvincia* siguiente; };
struct NodoPersona { char* cedula; char* nombre; NodoPersona* siguiente; };
#endif