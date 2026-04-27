#ifndef PROCESOMATRIZ_H
#define PROCESOMATRIZ_H

// Declaración anticipada con template
template <typename T>
class MatrizDinamica; 

template <typename T>
class ProcesoMatriz {
public:
    //
    virtual void sumar(const MatrizDinamica<T>& m1, const MatrizDinamica<T>& m2) = 0;
   
    
    virtual ~ProcesoMatriz() = default;
};

#endif