#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include <fstream>
#include "Nodos.h"
using namespace std;

class GestorArchivos {
public:
    void cargarProvincias(NodoProvincia*& L) {
        ifstream f("provincias.txt"); if (!f.is_open()) return;
        char* b = new char[100];
        while (f.getline(b, 100)) {
            NodoProvincia* n = new NodoProvincia();
            n->codigo = new char[3]; n->nombre = new char[50]; n->siguiente = L;
            int i = 0, j = 0;
            while (*(b + i) != ',' && *(b + i)) { *(n->codigo + i) = *(b + i); i++; } *(n->codigo + i) = '\0';
            if (*(b + i) == ',') i++;
            while (*(b + i)) { *(n->nombre + j) = *(b + i); i++; j++; } *(n->nombre + j) = '\0';
            L = n;
        } 
        delete[] b; f.close();
    }

    void cargarPersonas(NodoPersona*& L) {
        ifstream f("cedulas.txt"); if (!f.is_open()) return;
        char* b = new char[100];
        while (f.getline(b, 100)) {
            NodoPersona* n = new NodoPersona();
            n->cedula = new char[15]; n->nombre = new char[50]; n->siguiente = L;
            int i = 0, j = 0;
            while (*(b + i) != ',' && *(b + i)) { *(n->cedula + i) = *(b + i); i++; } *(n->cedula + i) = '\0';
            if (*(b + i) == ',') i++;
            while (*(b + i)) { *(n->nombre + j) = *(b + i); i++; j++; } *(n->nombre + j) = '\0';
            L = n;
        } 
        delete[] b; f.close();
    }

    void guardarPersonas(NodoPersona* L) {
        ofstream f("cedulas.txt");
        while (L) { f << L->cedula << "," << L->nombre << endl; L = L->siguiente; }
        f.close();
    }
};
#endif