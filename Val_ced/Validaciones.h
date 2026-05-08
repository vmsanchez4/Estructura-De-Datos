#ifndef VALIDACIONES_H
#define VALIDACIONES_H
class Validaciones {
public:
    int longitud(char* c) { int l = 0; while (*(c + l)) l++; return l; }
    
    bool comparar(char* c1, char* c2) {
        int i = 0; 
        while (*(c1 + i) || *(c2 + i)) { if (*(c1 + i) != *(c2 + i)) return false; i++; }
        return true;
    }
    
    bool esNumero(char* c) {
        int i = 0;
        while (*(c + i)) { if (*(c + i) < '0' || *(c + i) > '9') return false; i++; }
        return true;
    }
};
#endif