#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "Nodos.h"
#include "Validaciones.h"

class Operaciones {
    Validaciones val;
public:
    bool validarCedulaEcuatoriana(char* c, NodoProvincia* p) {
        if (val.longitud(c) != 10 || !val.esNumero(c)) return false;
        
        char* cp = new char[3]; *(cp + 0) = *(c + 0); *(cp + 1) = *(c + 1); *(cp + 2) = '\0';
        bool exP = false;
        while (p) { if (val.comparar(p->codigo, cp)) { exP = true; break; } p = p->siguiente; }
        delete[] cp;
        
        if (!exP || (*(c + 2) - '0') >= 6) return false;

        int sum = 0;
        for (int i = 0; i < 9; i++) {
            int d = *(c + i) - '0';
            if (i % 2 == 0) { d *= 2; if (d > 9) d -= 9; }
            sum += d;
        }
        return ((10 - (sum % 10)) % 10) == (*(c + 9) - '0');
    }

    bool existePersona(NodoPersona* L, char* c) {
        while (L) { if (val.comparar(L->cedula, c)) return true; L = L->siguiente; }
        return false;
    }
};
#endif