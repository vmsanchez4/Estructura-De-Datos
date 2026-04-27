/***********************************************************************
 * Module:  Proceso.h
 * Author:  Vicente
 * Modified: sabado, 11 de abril de 2026 21:24:16
 * Purpose: Declaration of the class Proceso
 ***********************************************************************/

#ifndef PROCESO_H
#define PROCESO_H

template <class T>
class Quebrado;

template <class T>
class Proceso {
public:
    
    virtual Quebrado<T> sumar(Quebrado<T> q1) = 0;
    virtual Quebrado<T> sumar(Quebrado<T> q1, Quebrado<T> q2) = 0;

    virtual ~Proceso() = default;
};

#endif